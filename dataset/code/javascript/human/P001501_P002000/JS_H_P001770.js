/* ACPIA Console — application logic (modern scroll-driven UI)
   Each view = a dark hero band + a scrolling body with reveal-on-scroll
   sections. Renders entirely from window.ACPIA_DATA. Vanilla JS, no build.
   --------------------------------------------------------------------------- */

const DATA = window.ACPIA_DATA;
let activeCaseId = DATA.cases[0].id;
let currentView = "dashboard";

const $ = (sel, root = document) => root.querySelector(sel);
const $$ = (sel, root = document) => [...root.querySelectorAll(sel)];
const getCase = () => DATA.cases.find((c) => c.id === activeCaseId);

/* ---------- helpers ---------- */
function riskClass(score) { return score >= 80 ? "crit" : score >= 60 ? "high" : score >= 40 ? "med" : "low"; }
function riskLabel(score) { return score >= 80 ? "Critical" : score >= 60 ? "High" : score >= 40 ? "Medium" : "Low"; }
const levelClass = (lvl) => ({ critical: "crit", high: "high", med: "med", low: "low" }[lvl] || "low");
const typeIconName = (t) => ({ chat: "chat", image: "image", audio: "audio", log: "log", archive: "archive" }[t] || "file");
const typeIcon = (t, size) => ICON(typeIconName(t), size || 18);
const kindIcon = (k) => ICON(({ person: "person", account: "account", phone: "phone", victim: "victim", place: "place", device: "device" }[k] || "file"), 16);
/* inline file label: small icon + name, vertically aligned */
const fileLabel = (item) => `<span class="file-label">${typeIcon(item.type, 17)}<span>${escapeHtml(item.name)}</span></span>`;
function escapeHtml(s) {
  return String(s).replace(/[&<>"']/g, (c) => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" }[c]));
}

/* hero band builder shared by every view */
function hero({ eyebrow, title, lead, right = "", idTag = "" }) {
  return `<section class="view-hero">
    <div class="hero-inner">
      <p class="hero-eyebrow">${escapeHtml(eyebrow)}</p>
      <div class="hero-row">
        <h1>${escapeHtml(title)}${idTag ? ` <span class="case-id">${escapeHtml(idTag)}</span>` : ""}</h1>
        ${right}
      </div>
      ${lead ? `<p class="lead">${escapeHtml(lead)}</p>` : ""}
    </div>
  </section>`;
}

/* ========================================================================
   VIEWS
   ===================================================================== */

function viewDashboard() {
  const c = getCase();
  const s = c.stats;
  const topLeads = [...c.evidence].sort((a, b) => b.risk - a.risk).slice(0, 3);
  return (
    hero({
      eyebrow: "Case Workspace",
      title: c.title,
      idTag: c.id,
      lead: c.summary,
      right: `<span class="status-pill ${c.status === "Active" ? "on" : ""}">${c.status}</span>`,
    }) +
    `<div class="view-body">
      <div class="stat-grid">
        ${statCard("items", s.items, "Evidence items", "", "evidence")}
        ${statCard("alert", s.highRisk, "High-risk flags", "crit", "leads")}
        ${statCard("sources", s.sources, "Distinct sources", "", "evidence")}
        ${statCard("shield", s.victimsPotential, "Potential victims", "high", "leads")}
      </div>

      <div class="panel-row reveal-up" style="margin-top:30px">
        <section class="panel">
          <div class="panel-head"><h2>${ICON("target", 17)} Top AI-prioritized leads</h2><button class="link-btn" data-goto="leads">View all &rarr;</button></div>
          <div class="lead-list">${topLeads.map(leadRow).join("")}</div>
        </section>

        <section class="panel">
          <div class="panel-head"><h2>${ICON("ai", 17)} AI case assessment</h2></div>
          <div class="assess">
            <p>ACPIA has processed <strong>${s.items} items</strong> across <strong>${s.sources} sources</strong>.
            The evidence is consistent with an <strong>active grooming pattern</strong> escalating to an
            in-person meeting on <strong>2026-05-28</strong>.</p>
            <ul class="assess-list">
              <li><span class="dot crit"></span> Arrange-meeting + secrecy language (E-01) corroborated by geotag (E-02)</li>
              <li><span class="dot high"></span> Fabricated AI-generated persona indicates identity concealment (E-03)</li>
              <li><span class="dot high"></span> Possible minor voice + coercion cues need priority human review (E-05)</li>
            </ul>
            <div class="assess-foot">${ICON("shield", 15)} Recommendation is decision-<em>support</em> only &mdash; confirm before any action.</div>
          </div>
        </section>
      </div>
    </div>`
  );
}

function statCard(iconName, value, label, tone = "", goto = "") {
  const gotoAttr = goto ? `data-goto="${goto}"` : "";
  const clickable = goto ? "clickable" : "";
  return `<div class="stat-card ${tone} ${clickable} reveal-up" ${gotoAttr} role="${goto ? 'button' : 'presentation'}" tabindex="${goto ? '0' : '-1'}">
    <div class="sc-icon">${ICON(iconName, 20)}</div>
    <div class="sc-num" data-count="${value}">0</div>
    <div class="sc-label">${label}</div>
    ${goto ? `<div class="sc-arrow">${ICON('search', 13)}<span>View all</span></div>` : ""}
  </div>`;
}
function leadRow(item) {
  return `<button class="lead-row" data-evidence="${item.id}">
    <span class="risk-chip ${riskClass(item.risk)}">${item.risk}</span>
    <span class="lead-main"><strong>${fileLabel(item)}</strong>
    <small>${escapeHtml(item.category)} &middot; ${escapeHtml(item.source)}</small></span>
    <span class="lead-go">&rsaquo;</span></button>`;
}

function viewEvidence() {
  const c = getCase();
  return (
    hero({
      eyebrow: "Digital Evidence",
      title: "Evidence Locker",
      lead: "Every seized export, analyzed and risk-scored by ACPIA. Click any item for the full AI breakdown.",
      right: `<label class="upload-btn">+ Add evidence<input type="file" id="fakeUpload" hidden multiple /></label>`,
    }) +
    `<div class="view-body">
      <p class="muted upload-note" id="uploadNote">Drop seized exports here. In this prototype, uploads are simulated — the AI analysis shown uses built-in sample results.</p>
      <div class="ev-grid">${c.evidence.map((i) => `<div class="reveal-up">${evidenceCard(i)}</div>`).join("")}</div>
    </div>`
  );
}
function evidenceCard(item) {
  return `<article class="ev-card" data-evidence="${item.id}">
    <div class="ev-top"><span class="ev-icon">${typeIcon(item.type, 22)}</span>
      <span class="risk-chip ${riskClass(item.risk)}">${riskLabel(item.risk)} ${item.risk}</span></div>
    <h3>${escapeHtml(item.name)}</h3>
    <p class="ev-cat">${escapeHtml(item.category)}</p>
    <p class="ev-sum">${escapeHtml(item.summary.slice(0, 110))}…</p>
    <div class="tag-row">${item.tags.map((t) => `<span class="tag">${escapeHtml(t)}</span>`).join("")}</div>
    <div class="ev-foot"><small>${escapeHtml(item.source)}</small><span class="conf">conf ${(item.confidence * 100) | 0}%</span></div>
  </article>`;
}

function viewLeads() {
  const c = getCase();
  const sorted = [...c.evidence].sort((a, b) => b.risk - a.risk);
  return (
    hero({
      eyebrow: "Prioritization",
      title: "Leads & Risk",
      lead: "Ranked by AI risk score so investigators focus on the highest-impact items first.",
    }) +
    `<div class="view-body">
      <table class="lead-table reveal-up">
        <thead><tr><th>Risk</th><th>Item</th><th>Category</th><th>Key signal</th><th>Source</th><th></th></tr></thead>
        <tbody>
          ${sorted.map((i) => `<tr data-evidence="${i.id}">
            <td><span class="risk-chip ${riskClass(i.risk)}">${i.risk}</span></td>
            <td><strong>${fileLabel(i)}</strong></td>
            <td>${escapeHtml(i.category)}</td>
            <td class="signal">${escapeHtml(i.findings[0])}</td>
            <td><small>${escapeHtml(i.source)}</small></td>
            <td class="go">&rsaquo;</td></tr>`).join("")}
        </tbody>
      </table>
    </div>`
  );
}

function viewTimeline() {
  const c = getCase();
  return (
    hero({
      eyebrow: "Reconstruction",
      title: "Case Timeline",
      lead: "Events correlated across all sources into a single chronological narrative.",
    }) +
    `<div class="view-body">
      <div class="timeline">
        ${c.timeline.map((e) => `<div class="tl-item ${levelClass(e.risk)} reveal-up">
          <div class="tl-dot"></div>
          <div class="tl-card">
            <div class="tl-date">${e.date}</div>
            <strong>${escapeHtml(e.label)}</strong>
            <p>${escapeHtml(e.detail)}</p>
            <span class="tl-src">${e.source === "case" ? "Case event" : "Source " + e.source}</span>
          </div></div>`).join("")}
      </div>
    </div>`
  );
}

function viewNetwork() {
  const c = getCase();
  const net = c.network;
  const cx = 320, cy = 230, r = 165;
  const pos = {};
  net.nodes.forEach((n, i) => {
    const ang = (i / net.nodes.length) * Math.PI * 2 - Math.PI / 2;
    pos[n.id] = { x: cx + r * Math.cos(ang), y: cy + r * Math.sin(ang) };
  });
  const lines = net.links.map((l) => {
    const a = pos[l.from], b = pos[l.to], mx = (a.x + b.x) / 2, my = (a.y + b.y) / 2;
    return `<line x1="${a.x}" y1="${a.y}" x2="${b.x}" y2="${b.y}" class="net-link"/>
            <text x="${mx}" y="${my - 4}" class="net-link-label">${escapeHtml(l.label)}</text>`;
  }).join("");
  const dots = net.nodes.map((n) => {
    const p = pos[n.id];
    const g = ICON_RAW(({ person: "person", account: "account", phone: "phone", victim: "victim", place: "place", device: "device" }[n.kind] || "file"));
    return `<g class="net-node ${levelClass(n.risk)}">
      <circle cx="${p.x}" cy="${p.y}" r="30"/>
      <g transform="translate(${p.x - 11}, ${p.y - 11}) scale(0.92)" class="net-glyph" fill="none" stroke-width="1.7" stroke-linecap="round" stroke-linejoin="round">${g}</g>
      <text x="${p.x}" y="${p.y + 48}" class="net-label">${escapeHtml(n.label)}</text></g>`;
  }).join("");
  return (
    hero({
      eyebrow: "Intelligence Fusion",
      title: "Source Correlation",
      lead: "Entities and relationships fused across chats, calls, devices and locations.",
    }) +
    `<div class="view-body">
      <div class="net-wrap reveal-up">
        <svg viewBox="0 0 640 470" class="net-svg">${lines}${dots}</svg>
        <div class="net-legend">
          <span><i class="dot crit"></i> Critical</span><span><i class="dot high"></i> High</span>
          <span><i class="dot med"></i> Medium</span><span><i class="dot low"></i> Low</span>
        </div>
      </div>
    </div>`
  );
}

function viewSearch() {
  return (
    hero({
      eyebrow: "Retrieval",
      title: "Intelligent Search",
      lead: "Natural-language search across every item in the active case.",
    }) +
    `<div class="view-body">
      <div class="search-box reveal-up">
        <input id="searchInput" placeholder="Try: meeting, Fort Kochi, minor, AI-generated, late-night calls…" autocomplete="off"/>
        <button id="searchBtn">Search</button>
      </div>
      <div class="search-chips reveal-up">
        ${["meeting", "Fort Kochi", "minor", "AI-generated", "coercion", "geotag"].map((q) => `<button class="qchip" data-q="${q}">${q}</button>`).join("")}
      </div>
      <div id="searchResults" class="search-results"><p class="muted">Enter a query to search the case evidence.</p></div>
    </div>`
  );
}
function runSearch(query) {
  const c = getCase();
  const q = query.trim().toLowerCase();
  const box = $("#searchResults");
  if (!q) { box.innerHTML = `<p class="muted">Enter a query to search the case evidence.</p>`; return; }
  const hits = c.evidence.filter((i) => {
    const hay = [i.name, i.category, i.summary, i.tags.join(" "), i.findings.join(" "), i.entities.join(" ")].join(" ").toLowerCase();
    return hay.includes(q);
  });
  box.innerHTML = hits.length
    ? `<p class="muted">${hits.length} item(s) match “${escapeHtml(query)}”.</p>` +
      hits.map((i) => {
        const where = i.findings.find((f) => f.toLowerCase().includes(q)) || i.summary;
        return `<button class="result-row" data-evidence="${i.id}">
          <span class="risk-chip ${riskClass(i.risk)}">${i.risk}</span>
          <span class="result-main"><strong>${typeIcon(i.type)} ${escapeHtml(i.name)}</strong>
          <small>${escapeHtml(where)}</small></span><span class="lead-go">›</span></button>`;
      }).join("")
    : `<p class="muted">No items match “${escapeHtml(query)}”. Try a broader term.</p>`;
  wireEvidenceClicks(box);
}

function viewReport() {
  const c = getCase();
  const high = c.evidence.filter((e) => e.risk >= 60).length;
  const today = new Date().toISOString().slice(0, 10);
  return (
    hero({
      eyebrow: "Automated Reporting",
      title: "Case Report",
      lead: "An AI-assembled investigative summary, ready for human review and export.",
      right: `<button class="upload-btn" onclick="window.print()">${ICON("printer", 16)} Print / Export</button>`,
    }) +
    `<div class="view-body">
      <article class="report reveal-up">
        <header class="report-head">
          <h2>Investigative Summary — ${escapeHtml(c.title)}</h2>
          <p>${c.id} · Generated ${today} · Lead: ${escapeHtml(c.lead)}</p>
          <span class="report-stamp">DRAFT · For authorized review</span>
        </header>
        <h3>1. Overview</h3>
        <p>${escapeHtml(c.summary)}</p>
        <h3>2. Key findings</h3>
        <ul>
          <li><strong>${high}</strong> items scored high or critical risk by ACPIA.</li>
          <li>Evidence indicates an escalating grooming pattern culminating in a meeting on 2026-05-28.</li>
          <li>Suspect persona (@riverboat_88) used a likely AI-generated avatar — identity concealment.</li>
          <li>Audio evidence may involve a minor and contains coercion cues — flagged for priority human review.</li>
        </ul>
        <h3>3. Evidence index</h3>
        <table class="report-table">
          <thead><tr><th>ID</th><th>Item</th><th>Category</th><th>Risk</th><th>Confidence</th></tr></thead>
          <tbody>${c.evidence.map((i) => `<tr><td>${i.id}</td><td>${escapeHtml(i.name)}</td><td>${escapeHtml(i.category)}</td><td>${riskLabel(i.risk)} (${i.risk})</td><td>${(i.confidence * 100) | 0}%</td></tr>`).join("")}</tbody>
        </table>
        <h3>4. Recommended next steps</h3>
        <ol>
          <li>Prioritize victim safeguarding for the self-identified 14-year-old contact.</li>
          <li>Corroborate geotag (E-02) with CCTV / cell-site data for 2026-05-28.</li>
          <li>Forensic confirmation of synthetic media (E-03) by lab.</li>
          <li>Human review of audio (E-05) by trained analyst.</li>
        </ol>
        <footer class="report-foot">
          This report was assembled with AI assistance and must be verified by the investigating officer.
          ACPIA provides decision-support; it does not make investigative or prosecutorial decisions.
        </footer>
      </article>
    </div>`
  );
}

/* ========================================================================
   DRAWER (evidence detail)
   ===================================================================== */
function openDrawer(evidenceId) {
  const c = getCase();
  const item = c.evidence.find((e) => e.id === evidenceId);
  if (!item) return;
  const drawer = $("#drawer");
  const sens = window.wbIsSensitive ? window.wbIsSensitive(item) : false;
  const status = window.getLeadStatus ? window.getLeadStatus(item.id) : "";
  const note = window.getNote ? window.getNote(item.id) : "";
  /* AI summary + detected signals are the sensitive payload — gate them when
     wellbeing safeguards are on and the item is flagged sensitive. */
  const sensitiveBlock =
    `<h4>AI summary</h4><p>${escapeHtml(item.summary)}</p>
     <h4>Detected signals</h4>
     <ul class="drawer-findings">${item.findings.map((f) => `<li>${escapeHtml(f)}</li>`).join("")}</ul>`;
  const gated = window.wbGate ? window.wbGate(sensitiveBlock, item.id, sens) : sensitiveBlock;
  const statusPill = status
    ? `<span class="lead-status ${status}">${status === "confirmed" ? "Lead confirmed" : "Marked for review"}</span>` : "";

  drawer.innerHTML = `
    <button class="drawer-close" id="drawerClose" aria-label="Close">&times;</button>
    <div class="drawer-head">
      <span class="ev-icon big">${typeIcon(item.type, 30)}</span>
      <div><h2>${escapeHtml(item.name)} ${window.wbBadge ? window.wbBadge(item) : ""}</h2><p class="muted">${escapeHtml(item.id)} &middot; ${escapeHtml(item.type)} &middot; ${escapeHtml(item.size)}</p></div>
    </div>
    <div class="drawer-risk">
      <span class="risk-chip ${riskClass(item.risk)} lg">${riskLabel(item.risk)} · ${item.risk}</span>
      <span class="conf">AI confidence ${(item.confidence * 100) | 0}%</span>
      ${statusPill}
    </div>
    ${gated}
    <h4>Linked entities</h4>
    <div class="tag-row">${item.entities.length ? item.entities.map((e) => `<span class="tag ent">${escapeHtml(e)}</span>`).join("") : '<span class="muted">None extracted</span>'}</div>
    <h4>Provenance</h4>
    <p class="muted">Source: ${escapeHtml(item.source)} · Ingested ${escapeHtml(item.added)}</p>
    <h4>Investigator notes</h4>
    <textarea class="drawer-note-input" id="drawerNote" placeholder="Add a note — saved to this case…">${escapeHtml(note)}</textarea>
    <div class="drawer-actions">
      <button class="btn-confirm" data-act="confirmed" ${status === "confirmed" ? "disabled" : ""}>${status === "confirmed" ? "✓ Lead confirmed" : "Confirm lead"}</button>
      <button class="btn-dismiss" data-act="review" ${status === "review" ? "disabled" : ""}>${status === "review" ? "✓ Marked for review" : "Mark for review"}</button>
    </div>
    <p class="drawer-note">Every action here is written to the case audit log. AI output requires human confirmation.</p>`;
  drawer.classList.add("open");
  drawer.setAttribute("aria-hidden", "false");
  $("#drawerBackdrop").classList.add("show");
  $("#drawerClose").onclick = closeDrawer;
  if (window.wbWire) window.wbWire(drawer);

  // persist + audit lead decisions
  $$(".drawer-actions button", drawer).forEach((b) => (b.onclick = () => {
    const act = b.dataset.act;
    if (window.setLeadStatus) window.setLeadStatus(item.id, act);
    if (window.logAudit) window.logAudit(act === "confirmed" ? "Confirmed lead" : "Marked lead for review", `${item.id} · ${item.name}`);
    $$(".drawer-actions button", drawer).forEach((x) => { x.disabled = false; x.textContent = x.dataset.act === "confirmed" ? "Confirm lead" : "Mark for review"; });
    b.textContent = act === "confirmed" ? "✓ Lead confirmed" : "✓ Marked for review";
    b.disabled = true;
    if (window.toast) window.toast(`${act === "confirmed" ? "Lead confirmed" : "Marked for review"} — ${item.id}. Logged to audit.`);
  }));

  // persist notes
  const noteEl = $("#drawerNote", drawer);
  if (noteEl) {
    let initial = note;
    noteEl.addEventListener("input", () => { if (window.setNote) window.setNote(item.id, noteEl.value); });
    noteEl.addEventListener("blur", () => {
      if (noteEl.value.trim() !== initial.trim()) {
        if (window.logAudit) window.logAudit(noteEl.value.trim() ? "Saved investigator note" : "Cleared investigator note", item.id);
        initial = noteEl.value;
      }
    });
  }
}
function closeDrawer() {
  $("#drawer").classList.remove("open");
  $("#drawer").setAttribute("aria-hidden", "true");
  $("#drawerBackdrop").classList.remove("show");
}

/* ========================================================================
   RENDER + EVENTS + SCROLL REVEAL
   ===================================================================== */
const VIEWS = { dashboard: viewDashboard, evidence: viewEvidence, leads: viewLeads, timeline: viewTimeline, network: viewNetwork, search: viewSearch, report: viewReport };

/* Merge in the enhanced modules (mod-*.js). These register render functions on
   window.ACPIA_EXT_VIEWS and optional post-render mount hooks on
   window.ACPIA_MOUNT. Extension views override the built-ins of the same name
   (e.g. the upgraded dashboard, timeline, network, search and report). */
Object.assign(VIEWS, window.ACPIA_EXT_VIEWS || {});

function render() {
  const area = $("#viewArea");
  area.innerHTML = `<div class="view-enter">${VIEWS[currentView]()}</div>`;
  area.scrollTop = 0;
  updateProgress();
  wireViewEvents();
  setupReveal();
  animateCounts();
  /* run the module's mount hook (charts, graph, chat, drag-drop, etc.) */
  const mount = (window.ACPIA_MOUNT || {})[currentView];
  if (mount) { try { mount(getCase()); } catch (err) { console.error("mount(" + currentView + ")", err); } }
}

/* count-up animation for the dashboard stats (no timers/Date — rAF based) */
function animateCounts() {
  $$(".sc-num[data-count]").forEach((el) => {
    const target = parseInt(el.dataset.count, 10) || 0;
    if (target === 0) { el.textContent = "0"; return; }
    let frame = 0;
    const total = 38; // ~0.6s at 60fps
    const tick = () => {
      frame++;
      const p = 1 - Math.pow(1 - frame / total, 3); // easeOutCubic
      el.textContent = Math.round(target * p);
      if (frame < total) requestAnimationFrame(tick);
      else el.textContent = String(target);
    };
    requestAnimationFrame(tick);
  });
}

/* scroll-progress bar driven by the scrolling view area */
function updateProgress() {
  const area = $("#viewArea");
  const bar = $("#scrollProgress");
  if (!area || !bar) return;
  const max = area.scrollHeight - area.clientHeight;
  bar.style.width = (max <= 0 ? 0 : (area.scrollTop / max) * 100) + "%";
}

let revealObserver;
function setupReveal() {
  if (revealObserver) revealObserver.disconnect();
  revealObserver = new IntersectionObserver((entries) => {
    entries.forEach((e) => {
      if (e.isIntersecting) { e.target.classList.add("in"); revealObserver.unobserve(e.target); }
    });
  }, { threshold: 0.08, root: $("#viewArea") });
  $$(".reveal-up").forEach((el, i) => {
    el.style.transitionDelay = Math.min(i * 55, 350) + "ms";
    revealObserver.observe(el);
  });
}

function wireEvidenceClicks(root = document) {
  $$("[data-evidence]", root).forEach((el) => (el.onclick = () => openDrawer(el.dataset.evidence)));
}

function wireViewEvents() {
  wireEvidenceClicks($("#viewArea"));
  $$("[data-goto]").forEach((el) => {
    el.onclick = () => switchView(el.dataset.goto);
    el.onkeydown = (e) => { if (e.key === "Enter" || e.key === " ") { e.preventDefault(); switchView(el.dataset.goto); } };
  });
  const si = $("#searchInput");
  if (si) {
    const go = () => runSearch(si.value);
    $("#searchBtn").addEventListener("click", go);
    si.addEventListener("keydown", (e) => e.key === "Enter" && go());
    $$(".qchip").forEach((c) => c.addEventListener("click", () => { si.value = c.dataset.q; go(); }));
  }
  const up = $("#fakeUpload");
  if (up) up.addEventListener("change", () => {
    const n = up.files.length;
    $("#uploadNote").innerHTML = `<strong>${n} file(s) queued.</strong> Simulated ingest complete — in a live system the AI pipeline would now analyze and score them. This prototype shows pre-loaded sample results.`;
  });
}

function switchView(view) {
  currentView = view;
  $$(".nav-item").forEach((b) => b.classList.toggle("active", b.dataset.view === view));
  render();
  $("#sidebar").classList.remove("open");
}

function populateCaseSelect() {
  const sel = $("#caseSelect");
  sel.innerHTML = DATA.cases.map((c) => `<option value="${c.id}">${c.title} — ${c.id}</option>`).join("");
  sel.value = activeCaseId;
  sel.addEventListener("change", () => {
    activeCaseId = sel.value;
    if (window.logAudit) window.logAudit("Switched active case", activeCaseId);
    render();
  });
}

/* render the line-art icons into the static chrome (sidebar, top bar, footer) */
function renderChromeIcons() {
  $$(".nav-item[data-icon]").forEach((b) => {
    const label = b.textContent.trim();
    b.innerHTML = `<span class="ni-icon">${ICON(b.dataset.icon, 18)}</span><span>${label}</span>`;
  });
  const rt = $("#restrictedTag");
  if (rt) rt.innerHTML = `${ICON("shield", 14)} Authorized Use Only`;
  const oc = $("#oversightChip");
  if (oc) oc.querySelector("span").innerHTML = ICON("shield", 13);
}

/* ---------- init ---------- */
function init() {
  renderChromeIcons();
  populateCaseSelect();
  $$(".nav-item").forEach((b) => b.addEventListener("click", () => switchView(b.dataset.view)));
  $("#drawerBackdrop").addEventListener("click", closeDrawer);
  $("#hamburger").addEventListener("click", () => $("#sidebar").classList.toggle("open"));
  document.addEventListener("keydown", (e) => e.key === "Escape" && closeDrawer());
  $("#viewArea").addEventListener("scroll", updateProgress, { passive: true });
  render();
}
init();
