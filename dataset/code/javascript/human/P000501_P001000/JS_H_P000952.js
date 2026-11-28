// Checks every worked example src/lib/techniques.ts can print, by enumerating
// every question src/lib/mentalMath.ts can generate. Not part of the app build —
// run it after touching either file.
//
// Usage:
//   node scripts/audit-techniques.mjs [--verbose]
//
// Three things are verified for each question:
//
//   1. Every equation in the steps is arithmetically true. Steps are parsed back
//      out of the strings the drill renders, so a rule whose prose and numbers
//      disagree is caught here rather than by a user mid-drill.
//   2. The question's answer is actually reached by the steps.
//   3. No step is degenerate — "0 + 0 = 0", "leaving 30 − 30 = 0". Those are
//      arithmetically fine and pedagogically worthless: a rule that fires on a
//      case it has nothing to say about should hand off to a simpler one.
//
// Exits non-zero if any of those fail. Rule frequencies and unreachable branches
// are reported too, but are notes, not failures.

import { configForDigits, DEFAULT_CONFIG } from "../src/lib/mentalMath.ts";
import { suggestTechnique } from "../src/lib/techniques.ts";

const verbose = process.argv.includes("--verbose");

// Mirrors the module-private PERCENTS list in mentalMath.ts.
const PERCENTS = [5, 10, 15, 20, 25, 50, 75];

// The 3-digit addition grid is 900 × 900. A stride coprime to 10 walks every
// units digit and every distance-to-a-round-number without walking every pair.
const STRIDE = { d3: 7 };

const CONFIGS = {
  default: DEFAULT_CONFIG,
  d1: configForDigits(1),
  d2: configForDigits(2),
  d3: configForDigits(3),
};

const q = (op, a, b, text, answer) => ({ kind: "arithmetic", op, a, b, text, answer });

/** Every question generateArithmetic() can emit under one config. */
function* questions(cfg, stride = 1) {
  const range = ([lo, hi], step = 1) => {
    const out = [];
    for (let v = lo; v <= hi; v += step) out.push(v);
    return out;
  };

  // Subtraction is the inverse of an addition, division the inverse of a
  // multiplication — same operand draw, so they are enumerated in the same pass.
  for (const a of range(cfg.add.a, stride))
    for (const b of range(cfg.add.b, stride)) {
      yield q("add", a, b, `${a} + ${b}`, a + b);
      yield q("sub", a + b, a, `${a + b} − ${a}`, b);
    }
  for (const a of range(cfg.mul.a))
    for (const b of range(cfg.mul.b)) {
      yield q("mul", a, b, `${a} × ${b}`, a * b);
      yield q("div", a * b, a, `${a * b} ÷ ${a}`, b);
    }
  for (const p of PERCENTS)
    for (let n = 20 * Math.max(1, Math.ceil(cfg.pct[0] / 20)); n <= cfg.pct[1]; n += 20)
      yield q("pct", p, n, `${p}% of ${n}`, (p * n) / 100);
  for (const n of range(cfg.sq)) yield q("sq", n, n, `${n}²`, n * n);
}

// ------------------------------------------------- reading the steps back out

/** Rewrites the rendered step into something evaluable, prose included. */
function normalize(step) {
  return step
    .replace(/−/g, "-")
    .replace(/×/g, "*")
    .replace(/÷/g, "/")
    .replace(/(\d+)²/g, "($1**2)")
    .replace(/(\d+)% of (\d+)/g, "($1*$2/100)")
    .replace(/half of (\d+)/g, "($1/2)")
    .replace(/(\d+) with a zero on the end/g, "($1*10)")
    .replace(/(\d+) with (\d+) zeros on the end/g, "($1*10**$2)")
    .replace(/glue the tail on as two digits: (\d+) \* (\d+) = (\d+)/g, "$1*$2 = $3");
}

const SEPARATORS = /,|;|:|→|—| so | then | and | leaving | is | with /;
const ARITHMETIC = /^[\d+\-*/().\s]+$/;

const compiled = new Map();
function evaluate(expr) {
  let fn = compiled.get(expr);
  if (!fn) {
    fn = Function(`"use strict";return (${expr})`);
    compiled.set(expr, fn);
  }
  return fn();
}

/** Every equation and bare value a step claims. Fragments with prose are skipped. */
function claims(step) {
  const equations = [];
  const values = [];
  for (const fragment of normalize(step).split(SEPARATORS)) {
    const sides = fragment
      .split("=")
      .map((s) => s.trim())
      .filter(Boolean);
    if (!sides.every((s) => ARITHMETIC.test(s) && /\d/.test(s))) continue;
    let evaluated;
    try {
      evaluated = sides.map(evaluate);
    } catch {
      continue;
    }
    values.push(...evaluated);
    if (sides.length > 1) equations.push({ fragment: fragment.trim(), evaluated });
  }
  return { equations, values };
}

/** A term that contributes nothing: "0 + 0 = 0", "30 − 30 = 0", "0 → 0". */
const degenerate = (step) => /(^|[^\d.])0([^\d.]|$)/.test(step);

// ------------------------------------------------------------------- the run

const failures = [];
const rules = new Map();
const leadingConstants = new Set();
let total = 0;

for (const [name, cfg] of Object.entries(CONFIGS)) {
  for (const question of questions(cfg, STRIDE[name] ?? 1)) {
    total++;
    const technique = suggestTechnique(question);
    if (!technique) {
      failures.push({ kind: "no technique offered", question: question.text });
      continue;
    }

    const key = `${question.op} | ${technique.name.replace(/\d+/g, "N")}`;
    const rule = rules.get(key) ?? { count: 0, equations: 0, configs: new Set(), sample: null };
    rule.count++;
    rule.configs.add(name);
    rule.sample ??= `${question.text} → ${technique.steps.join(" / ")}`;
    rules.set(key, rule);

    const lead = technique.name.match(/^([×÷])(\d+)/);
    if (lead) leadingConstants.add(lead[1] + lead[2]);

    const seen = [];
    for (const step of technique.steps) {
      const { equations, values } = claims(step);
      rule.equations += equations.length;
      seen.push(...values);
      for (const { fragment, evaluated } of equations)
        if (evaluated.some((v) => Math.abs(v - evaluated[0]) > 1e-9))
          failures.push({ kind: "false equation", question: question.text, name: technique.name, fragment, steps: technique.steps });
      if (degenerate(step))
        failures.push({ kind: "degenerate step", question: question.text, name: technique.name, step, steps: technique.steps });

      // Doubling chains carry no "=" to check, so walk the hops directly.
      const chain = /double \d+ times/.test(technique.name) && step.match(/\d+(?: → \d+)+/);
      if (chain) {
        const hops = chain[0].split(" → ").map(Number);
        for (let i = 1; i < hops.length; i++)
          if (hops[i] !== hops[i - 1] * 2)
            failures.push({ kind: "broken doubling chain", question: question.text, name: technique.name, steps: technique.steps });
        seen.push(hops[hops.length - 1]);
      }
    }

    const stated = technique.steps.some((step) =>
      new RegExp(`(^|[^\\d.])${String(question.answer).replace(".", "\\.")}([^\\d.]|$)`).test(step)
    );
    if (!stated && !seen.some((v) => Math.abs(v - question.answer) < 1e-9))
      failures.push({ kind: "answer never reached", question: question.text, answer: question.answer, name: technique.name, steps: technique.steps });
  }
}

// ---------------------------------------------------------------- the report

console.log(`${total.toLocaleString()} questions enumerated across ${Object.keys(CONFIGS).length} configs\n`);

console.log("rule".padEnd(48) + "fired".padStart(9) + "equations".padStart(11) + "  configs");
for (const [key, rule] of [...rules].sort((a, b) => a[0].localeCompare(b[0]))) {
  console.log(
    key.padEnd(48) +
      rule.count.toLocaleString().padStart(9) +
      rule.equations.toLocaleString().padStart(11) +
      "  " +
      [...rule.configs].join(",")
  );
  if (verbose) console.log(`  ${rule.sample}`);
}

// Constants the multiplication and division rules name. Kept in step with
// MUL_SCALE / MUL_DOUBLES / MUL_TEN_POWERS / DIV_SCALE by hand: an entry that
// stops firing is not a bug, but it does mean the drill can no longer reach it.
const DECLARED = ["×10", "×100", "×1000", "×11", "×9", "×5", "×25", "×50", "×125", "×250", "×500", "×4", "×8", "×16", "÷5", "÷10", "÷25", "÷50", "÷100", "÷125", "÷1000"];
const unreachable = DECLARED.filter((c) => !leadingConstants.has(c));
if (unreachable.length) console.log(`\nnote: no question routes to ${unreachable.join(", ")} — dead branches given the current ranges`);
const rare = [...rules].filter(([, r]) => r.count < 25).map(([k, r]) => `${k} (${r.count})`);
if (rare.length) console.log(`note: barely reachable — ${rare.join(", ")}`);

if (failures.length) {
  console.log(`\n${failures.length} FAILURES`);
  const grouped = new Map();
  for (const failure of failures) {
    const key = `${failure.kind} | ${failure.name ?? ""}`;
    if (!grouped.has(key)) grouped.set(key, []);
    grouped.get(key).push(failure);
  }
  for (const [key, list] of grouped) console.log(`  ${key} ×${list.length}\n    ${JSON.stringify(list[0])}`);
  process.exit(1);
}

console.log("\nno failures: every equation checks out, every answer is reached, no dead steps");
