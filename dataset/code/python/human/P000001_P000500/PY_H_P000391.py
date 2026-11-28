"""AI provider abstraction + grounded RAG assistant.

The AI layer is strictly secondary: deterministic filters run first, the LLM
only summarizes/explains grounded database content. If no LLM is configured,
a deterministic assistant returns the same grounded results without an LLM.

Never hallucinates: every factual claim in the response is sourced from the
database and includes source attribution.
"""

from __future__ import annotations

from abc import ABC, abstractmethod
from typing import Any, Optional

import httpx

from app.core.config import settings


class AIProvider(ABC):
    @abstractmethod
    async def complete(self, system: str, user: str) -> Optional[str]:
        ...


class OpenAICompatibleProvider(AIProvider):
    def __init__(
        self,
        api_key: str,
        model: str,
        base_url: Optional[str] = None,
    ):
        self.api_key = api_key
        self.model = model
        self.base_url = (base_url or "https://api.openai.com/v1").rstrip("/")

    async def complete(self, system: str, user: str) -> Optional[str]:
        try:
            async with httpx.AsyncClient(timeout=30) as client:
                resp = await client.post(
                    f"{self.base_url}/chat/completions",
                    headers={
                        "Authorization": f"Bearer {self.api_key}",
                        "Content-Type": "application/json",
                    },
                    json={
                        "model": self.model,
                        "messages": [
                            {"role": "system", "content": system},
                            {"role": "user", "content": user},
                        ],
                        "temperature": 0.2,
                    },
                )
                resp.raise_for_status()
                data = resp.json()
                return data["choices"][0]["message"]["content"]
        except Exception:
            return None


class AnthropicProvider(AIProvider):
    def __init__(self, api_key: str, model: str):
        self.api_key = api_key
        self.model = model

    async def complete(self, system: str, user: str) -> Optional[str]:
        try:
            async with httpx.AsyncClient(timeout=30) as client:
                resp = await client.post(
                    "https://api.anthropic.com/v1/messages",
                    headers={
                        "x-api-key": self.api_key,
                        "anthropic-version": "2023-06-01",
                        "Content-Type": "application/json",
                    },
                    json={
                        "model": self.model,
                        "max_tokens": 1024,
                        "system": system,
                        "messages": [{"role": "user", "content": user}],
                    },
                )
                resp.raise_for_status()
                data = resp.json()
                return data["content"][0]["text"]
        except Exception:
            return None


class NullProvider(AIProvider):
    async def complete(self, system: str, user: str) -> Optional[str]:
        return None


def get_provider() -> AIProvider:
    if settings.ai_provider == "openai":
        return OpenAICompatibleProvider(settings.llm_api_key, settings.llm_model or "gpt-4o-mini")
    if settings.ai_provider == "anthropic":
        return AnthropicProvider(settings.llm_api_key, settings.llm_model or "claude-3-5-sonnet")
    if settings.ai_provider == "custom":
        return OpenAICompatibleProvider(
            settings.llm_api_key,
            settings.llm_model or "model",
            settings.ai_base_url or "https://api.openai.com/v1",
        )
    return NullProvider()


_SYSTEM_PROMPT = """You are the Scholarship AI Assistant for the Global Scholarship Finder \
platform, which helps Pakistani students find verified scholarships.

STRICT RULES:
- Only use information provided in the SCHOLARSHIP DATA section below.
- NEVER invent scholarship names, deadlines, amounts, requirements, universities or links.
- If information is not in the data, say "The source does not specify this."
- Never present a match score as an admission probability.
- Reference sources by their numbers like [Source 1].
- Answer in plain, concise markdown. Use the student's intent: country, degree, field, funding."""


def build_context(scholarships: list[Any]) -> str:
    """Serialize scholarships into compact grounded context."""
    lines = []
    for i, s in enumerate(scholarships, start=1):
        country = s.country.name if s.country else "Not specified"
        uni = s.university.name if s.university else None
        provider = s.provider.name if s.provider else None
        lines.append(
            f"[Source {i}] {s.canonical_title}\n"
            f"  Country: {country}\n"
            f"  University: {uni or 'Not specified by source'}\n"
            f"  Provider: {provider or 'Not specified by source'}\n"
            f"  Degrees: {', '.join(s.degree_levels or []) or 'Not specified'}\n"
            f"  Fields: {', '.join(s.study_fields or []) or 'Not specified'}\n"
            f"  Funding: {s.funding_type} ({s.funding_description or 'Not specified by source'})\n"
            f"  Pakistan eligibility: {s.pakistan_eligibility} — {s.pakistan_eligibility_evidence or 'not stated'}\n"
            f"  IELTS: {s.ielts_status} ({s.ielts_score or 'score not stated'})\n"
            f"  Minimum GPA: {s.minimum_gpa or 'not specified'}\n"
            f"  Status: {s.status} | Deadline: {s.deadline or 'not specified'}\n"
            f"  Official application: {s.official_application_url or 'not specified'}\n"
            f"  URL: {s.source_url or 'not specified'}"
        )
    return "\n\n".join(lines)


async def grounded_assistant(query: str, scholarships: list[Any]) -> dict[str, Any]:
    """Run the RAG pipeline: DB search already done by caller; we ground + explain."""
    context = build_context(scholarships)
    if not scholarships:
        return {
            "answer": (
                "I could not find scholarships matching your query in the current database. "
                "Try adjusting filters such as country, degree, or funding type."
            ),
            "sources": [],
            "used_llm": False,
        }

    provider = get_provider()
    user_prompt = (
        f"Student query: {query}\n\n"
        f"SCHOLARSHIP DATA:\n{context}\n\n"
        "Please summarize the most relevant opportunities for this student with source citations, "
        "highlighting funding, deadline, and Pakistan eligibility."
    )
    llm_answer = await provider.complete(_SYSTEM_PROMPT, user_prompt)

    sources = [
        {
            "number": i,
            "label": f"{s.canonical_title} — {s.university.name if s.university else (s.provider.name if s.provider else 'Official Source')}",
            "url": s.official_application_url or s.source_url,
        }
        for i, s in enumerate(scholarships, start=1)
    ]

    if llm_answer is None:
        return {
            "answer": deterministic_answer(query, scholarships),
            "sources": sources,
            "used_llm": False,
        }

    return {
        "answer": llm_answer,
        "sources": sources,
        "used_llm": llm_answer is not None,
    }


def deterministic_answer(query: str, scholarships: list[Any]) -> str:
    """Deterministic fallback summary when no LLM is configured."""
    from app.services.dates import days_remaining, today_utc

    lines = [
        f"Found {len(scholarships)} matching scholarship{'s' if len(scholarships) != 1 else ''} for "
        f'"{query}". Here is a quick overview:'
    ]
    for i, s in enumerate(scholarships, start=1):
        country = s.country.name if s.country else "Multiple countries"
        uni = s.university.name if s.university else (s.provider.name if s.provider else None)
        bits = [
            f"{i}. **{s.canonical_title}** ({country})",
            f"Funding: {s.funding_type}",
        ]
        if uni:
            bits.append(f"Host: {uni}")
        if s.degree_levels:
            bits.append(f"Degrees: {', '.join(s.degree_levels)}")
        if s.deadline:
            remaining = days_remaining(s.deadline, today_utc())
            bits.append(f"Deadline: {s.deadline.strftime('%d %B %Y')} ({remaining} days remaining)")
        elif s.status == "ROLLING":
            bits.append("Deadline: rolling")
        if s.ielts_status and s.ielts_status != "IELTS_NOT_REQUIRED":
            bits.append(f"IELTS: {s.ielts_status}")
        lines.append(" — ".join(bits))
    lines.append("See the linked source cards below for official application details.")
    return "\n".join(lines)


_UNI_SYSTEM_PROMPT = """You are the University Application Guide Assistant for the Global \
Scholarship Finder platform, helping Pakistani students apply to universities abroad.

STRICT RULES:
- Only use information provided in the UNIVERSITY DATA section below.
- NEVER invent fees, deadlines, requirements, links or any university facts.
- If a fact is not present in the data, say "Not recorded — verify on the university's \
official website."
- Never state that any specific outcome is guaranteed.
- Reference official links where available.
- Answer in plain, concise markdown."""


def build_university_context(detail: Any) -> str:
    """Serialize the university guide detail into compact grounded context."""
    p = detail.profile
    lines = [f"University: {detail.name}", f"Country: {detail.country.name if detail.country else 'Not recorded'}"]
    if p:
        lines += [
            f"City: {p.city or 'Not recorded'}",
            f"Type: {p.university_type or 'Not recorded'}",
            f"World rank: {p.world_rank or 'Not recorded'}",
            f"Application fee: {p.application_fee or 'Not recorded'} {p.application_fee_currency or ''}".strip(),
            f"Established: {p.established_year or 'Not recorded'}",
        ]
    lines.append(f"Website: {detail.website or 'Not recorded'}")
    if p and p.admissions_url:
        lines.append(f"Admissions: {p.admissions_url}")
    if p and p.application_portal_url:
        lines.append(f"Application portal: {p.application_portal_url}")

    if detail.programs:
        lines.append("\nPrograms:")
        for prog in detail.programs:
            lines.append(
                f"- {prog.name} | {prog.degree_level or ''} {prog.field or ''} | "
                f"intake {prog.intake or 'not recorded'} | "
                f"deadline {prog.application_deadline or 'not recorded'} | "
                f"IELTS {prog.ielts_min or 'not recorded'} | "
                f"tuition {prog.tuition_amount or 'not recorded'} {prog.tuition_currency or ''}"
            )
    else:
        lines.append("\nPrograms: not recorded")

    if detail.milestones:
        lines.append("\nKey dates:")
        for m in detail.milestones:
            lines.append(f"- {m.milestone_type.replace('_', ' ').title()}: {m.date or 'not recorded'}")
    else:
        lines.append("\nKey dates: not recorded")

    if detail.requirements:
        lines.append("\nRequirements:")
        for r in detail.requirements:
            lines.append(
                f"- {r.field_key} ({r.category}): {r.value or r.min_score or 'not recorded'} "
                f"| evidence: {r.evidence or 'not stated'}"
            )
    else:
        lines.append("\nRequirements: not recorded")

    if detail.documents:
        lines.append("\nDocuments:")
        for d in detail.documents:
            lines.append(f"- [{d.category}] {d.name}")
    else:
        lines.append("\nDocuments: not recorded")

    if detail.costs:
        lines.append("\nCosts:")
        for c in detail.costs:
            lines.append(f"- {c.label or c.category}: {c.amount or 'not recorded'} {c.currency or ''} ({c.cost_type})")
    else:
        lines.append("\nCosts: not recorded")

    if detail.links:
        lines.append("\nOfficial links:")
        for lk in detail.links:
            lines.append(f"- {lk.label}: {lk.url}")
    return "\n".join(lines)


async def answer_university_question(db, university: Any, detail: Any, message: str) -> dict[str, Any]:
    """Grounded Q&A about a specific university using only recorded data."""
    context = build_university_context(detail)
    provider = get_provider()
    user_prompt = (
        f"Student question: {message}\n\n"
        f"UNIVERSITY DATA:\n{context}\n\n"
        "Answer the question using only the data above. Cite official links where relevant."
    )
    llm_answer = await provider.complete(_UNI_SYSTEM_PROMPT, user_prompt)

    sources = [
        {"label": lk.label, "url": lk.url}
        for lk in detail.links
    ]
    if detail.website and not any(s["url"] == detail.website for s in sources):
        sources.append({"label": f"{detail.name} - official website", "url": detail.website})

    if llm_answer:
        return {"answer": llm_answer, "sources": sources, "used_llm": True}

    # Deterministic fallback: keyword-matched facts from the recorded data.
    low = message.lower()
    facts: list[str] = []
    if any(w in low for w in ["deadline", "date", "when", "closing", "intake"]):
        if detail.milestones:
            for m in detail.milestones:
                facts.append(
                    f"- {m.milestone_type.replace('_', ' ').title()}: "
                    f"{m.date or 'not recorded'}" + (f" ({m.round_label})" if m.round_label else "")
                )
        else:
            facts.append("- No key dates are recorded. Verify on the official website.")
    if any(w in low for w in ["ielts", "english", "language", "toefl"]):
        for r in detail.requirements:
            if r.category == "LANGUAGE":
                facts.append(f"- {r.field_key}: {r.value or r.min_score or 'recorded'}")
        if not any(r.category == "LANGUAGE" for r in detail.requirements):
            facts.append("- No language requirement recorded. Verify on the official website.")
    if any(w in low for w in ["fee", "cost", "tuition", "money", "fund"]):
        if detail.costs:
            for c in detail.costs:
                facts.append(
                    f"- {c.label or c.category}: {c.amount or 'not recorded'} {c.currency or ''} "
                    f"({c.cost_type.lower()})"
                )
        else:
            facts.append("- No cost data recorded. Verify on the official website.")
    if any(w in low for w in ["document", "require", "checklist", "what do i need"]):
        if detail.documents:
            for d in detail.documents:
                facts.append(f"- [{d.category}] {d.name}")
        else:
            facts.append("- No document list recorded. Verify on the official website.")
    if any(w in low for w in ["program", "degree", "course", "study", "major"]):
        if detail.programs:
            for prog in detail.programs[:8]:
                facts.append(f"- {prog.name} ({prog.degree_level or 'degree not recorded'})")
        else:
            facts.append("- No programs recorded. Check the official website for programs.")

    if not facts:
        facts.append(
            "I can answer about this university's recorded dates, IELTS/English requirements, "
            "fees and costs, required documents, and programs."
        )

    answer = (
        f"Here is what is recorded for **{detail.name}**:\n\n" + "\n".join(facts) +
        "\n\nAnything not recorded here must be confirmed on the university's official website."
    )
    return {"answer": answer, "sources": sources, "used_llm": False}
