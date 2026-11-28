/* =========================================================
   PR Pathway Agent — immigration dataset
   ---------------------------------------------------------
   Researched against official sources (IRCC / canada.ca,
   NOC 2021 / noc.esdc.gc.ca, Job Bank, Ontario OINP) and
   adversarially fact-checked. Current as of June 2026.
   Rules change often — verify on canada.ca before acting.
   NO personal identifiers are stored here. The sample
   profile is illustrative and de-identified.
   ========================================================= */
window.PR_DATA = {
  meta: {
    asOf: "June 2026",
    note: "Educational demo. Not legal advice. Verify all figures with IRCC."
  },

  /* ---- Illustrative sample profile (FICTIONAL) ----
     A made-up persona that models a common situation — a recent
     Canadian college grad on a PGWP whose current job doesn't
     count toward PR. Contains no real personal data. Anything
     you enter stays only in your browser (localStorage). */
  sampleProfile: {
    fullName: "Jordan Lee",
    age: 26,
    maritalStatus: "single",
    citizenship: "",
    education: "twoYear",
    canadianEducation: true,
    fieldOfStudy: "Computer Programming",
    canadianExp: 0,
    foreignExp: 0,
    englishCLB: 0,
    frenchNCLC: 0,
    status: "pgwp",
    pgwpExpiry: "2026-12-15",
    targetField: "Web & Software"
  },

  /* ---- PR routes (ranked) ---- */
  routes: [
    {
      id: "ee-french",
      tier: "primary",
      prob: "~80%",
      name: "Express Entry — French-language category",
      summary: "Enter the Express Entry pool, then get invited through the federal French-language category-based draws. Cut-offs run roughly 80–130 points below general draws, and no job offer or provincial nomination is required.",
      why: "With a strong French test (target NCLC 9) plus 12 months of skilled Canadian work, the projected CRS clears every recent French cut-off with margin — and it works from anywhere outside Quebec.",
      eligibleNow: "Not yet",
      eligibleAfter: "Eligible"
    },
    {
      id: "cec-general",
      tier: "backup",
      name: "Canadian Experience Class (general draws)",
      summary: "The same 12 months of skilled (TEER 0–3) Canadian work makes you CEC-eligible. General CEC draws cut off ~100 points higher, so this is the fallback if the French test underperforms.",
      why: "No proof-of-funds required under CEC; fully within your control.",
      eligibleNow: "Not yet",
      eligibleAfter: "Eligible"
    },
    {
      id: "c16",
      tier: "backup",
      name: "Francophone Mobility (C16 work permit)",
      summary: "An LMIA-exempt work permit for French speakers (only NCLC 5 in speaking + listening). It isn't PR itself — it's a way to keep working and keep the CEC clock running if your PGWP can't stretch to a full 12 months.",
      why: "Insurance for work authorization, not a PR pathway on its own."
    },
    {
      id: "oinp-workforce",
      tier: "backup",
      name: "Ontario Workforce Priority (OINP)",
      summary: "Provincial-nominee insurance for recent Ontario grads with a skilled, permanent job offer. As a base stream it adds 0 CRS and processes slowly, so keep it only as a safety net.",
      why: "Slow + 0 CRS boost; the federal French route is faster for this profile."
    },
    {
      id: "lmia",
      tier: "avoid",
      name: "LMIA-based work permit",
      summary: "Expensive (~$1,000), requires weeks of advertising, and since spring 2025 a job offer adds 0 CRS points. Not worth it for this profile.",
      why: "High cost and effort for zero CRS benefit."
    },
    {
      id: "back-to-school",
      tier: "avoid",
      name: "Enrolling in another program",
      summary: "A second program will not get you a second PGWP, it pauses the CEC clock, and student work doesn't count toward skilled experience.",
      why: "Stalls the PR clock instead of advancing it."
    },
    {
      id: "relocate",
      tier: "avoid",
      name: "Relocating to another province / Quebec",
      summary: "An Ontario diploma plus a remote job fails most provinces' intent-to-reside test, and Quebec runs its own slower system. Staying in Ontario is strictly better here.",
      why: "Adds risk and delay with no offsetting benefit."
    }
  ],

  /* ---- Recent Express Entry French-language draws (2025–26) ---- */
  frenchDraws: [
    { date: "May 28, 2026", crsCutoff: 409, itas: 4500 },
    { date: "Apr 29, 2026", crsCutoff: 400, itas: 4000 },
    { date: "Apr 15, 2026", crsCutoff: 419, itas: 4000 },
    { date: "Mar 18, 2026", crsCutoff: 393, itas: 4000 },
    { date: "Mar 4, 2026", crsCutoff: 397, itas: 5500 },
    { date: "Feb 6, 2026", crsCutoff: 400, itas: 8500 },
    { date: "Dec 17, 2025", crsCutoff: 399, itas: 6000 }
  ],
  cecGeneralCutoff: "507–518",

  /* ---- Skilled occupations (NOC 2021, TEER 0–3) ----
     Centred on web/software/IT — realistic targets for a
     Canadian Computer Programming diploma grad. TEER 0–3
     means each one counts toward CEC. Wages are approximate
     national medians (Job Bank); verify per province. */
  occupations: [
    { noc: "21233", title: "Web Designer", teer: 1, category: "Web & Software",
      typicalEducation: "University degree OR a college program in computer science, communications, graphic…", medianWageCAD: "~$70,000/yr",
      countsForCEC: true, attainable: "high",
      whyRelevant: "Directly matches your HTML/CSS/JavaScript skills from your computer programming diploma and is the most natural entry point into a TEER 1 skilled role.",
      sampleDuties: ["Consult with clients to develop and document website requirements", "Plan, design and create the visual layout, look and feel of websites and web applications", "Write, modify and test HTML, CSS and JavaScript to build responsive, accessible pages", "Create and optimize digital images, graphics and other visual elements for the web", "Conduct usability and accessibility tests to ensure sites are easy to navigate"],
      coverLetterAngle: "Lead with a portfolio of responsive sites and landing pages you have built, framing your diploma plus hands-on HTML/CSS/JS work as proof you can design and ship usable, accessible web experiences." },
    { noc: "21234", title: "Web Developer / Programmer", teer: 1, category: "Web & Software",
      typicalEducation: "University degree or college program in computer science or a related field plus web…", medianWageCAD: "~$80,000/yr",
      countsForCEC: true, attainable: "high",
      whyRelevant: "Your diploma plus front-end (HTML/CSS/JS) and C/C++ coding map almost exactly onto this TEER 1 web developer unit group, which the task confirmed as your primary target.",
      sampleDuties: ["Analyze users' requirements and design website content, structure and functionality", "Write, modify, integrate and test code using HTML, CSS, JavaScript and other languages", "Build and maintain front-end and back-end web applications connected to databases", "Test and debug websites and web applications to ensure performance and capacity", "Integrate content, graphics, audio and other media into websites"],
      coverLetterAngle: "Position yourself as a junior front-end/full-stack developer, citing class and personal projects where you analyzed requirements and wrote, tested and deployed website code." },
    { noc: "22220", title: "Computer Network & Web Technician", teer: 2, category: "IT Support",
      typicalEducation: "Completion of a college program in computer science, network administration, web…", medianWageCAD: "~$74,900/yr",
      countsForCEC: true, attainable: "high",
      whyRelevant: "The unit group explicitly requires a college program in web technology/network administration, and the 'web technician' stream uses your web skills, making it a strong realistic match.",
      sampleDuties: ["Maintain, troubleshoot and administer LANs, WANs and network hardware", "Evaluate, install and configure computer hardware, networking and operating-system software", "Set up and maintain internet, intranet and extranet websites and web-server software", "Monitor and optimize network connectivity and performance", "Respond to requests for help from website visitors and users"],
      coverLetterAngle: "Pitch yourself as a web/network technician who can build and maintain sites and support web servers, leaning on the exact alignment between your diploma and the role's requirement." },
    { noc: "22221", title: "User Support Technician (Help Desk)", teer: 2, category: "IT Support",
      typicalEducation: "Completion of a college program in computer science, computer programming or network…", medianWageCAD: "~$65,500/yr",
      countsForCEC: true, attainable: "high",
      whyRelevant: "IT helpdesk/desktop-support roles are one of the most realistic first skilled jobs for a new diploma grad and count as TEER 2.",
      sampleDuties: ["Communicate with users to determine and document technical problems", "Diagnose, reproduce and resolve issues with hardware, software and communications", "Consult user guides and technical manuals to research and implement solutions", "Provide advice and training to users", "Provide business-systems, network and internet support"],
      coverLetterAngle: "Combine your technical troubleshooting from the diploma with your proven Tim Hortons customer-service skills to stand out for first-line IT support." },
    { noc: "22222", title: "QA / Testing Technician", teer: 2, category: "QA & Testing",
      typicalEducation: "Completion of a college program in computer science, computer programming or network…", medianWageCAD: "~$72,800/yr",
      countsForCEC: true, attainable: "high",
      whyRelevant: "QA/software-testing technician roles map directly to college programming grads and are a common, accessible entry point into tech.",
      sampleDuties: ["Execute, analyze and document results of software, application and system tests", "Develop and implement software/system testing policies, procedures and scripts", "Identify, report and track product defects", "Propose solutions to product defects", "Set up test environments and test data"],
      coverLetterAngle: "Highlight attention to detail, your programming knowledge for writing test scripts, and willingness to learn tools like Selenium/JIRA as a junior QA tester." },
    { noc: "13110", title: "Administrative Assistant", teer: 3, category: "Business & Marketing",
      typicalEducation: "Completion of secondary school plus a one- or two-year college program for…", medianWageCAD: "~$55,000/yr",
      countsForCEC: true, attainable: "high",
      whyRelevant: "A very attainable TEER 3 skilled role for a newcomer that leverages your computer/office-software skills and counts for CEC (note: a 'data entry clerk', NOC 14400, is TEER 4 and would NOT count, so this is the data/admin role to target instead).",
      sampleDuties: ["Prepare, key in, edit and proofread correspondence, reports and presentations", "Open and distribute mail and coordinate the flow of information", "Schedule and confirm appointments and meetings", "Maintain electronic and paper filing and data-entry systems", "Compile data and prepare spreadsheets, records and documents"],
      coverLetterAngle: "Combine your diploma's strong computer skills with your reliable Tim Hortons work record to win an administrative/office role while building Canadian skilled (CEC-eligible) experience." },
    { noc: "52120", title: "Graphic Designer / Illustrator", teer: 2, category: "Design & Content",
      typicalEducation: "Completion of a college or university program in graphic arts/design or visual arts;…", medianWageCAD: "~$65,000/yr",
      countsForCEC: true, attainable: "medium",
      whyRelevant: "Your web-design eye and HTML/CSS skills overlap with digital graphic design, especially web and UI graphics.",
      sampleDuties: ["Consult with clients to establish the look, elements and content of communications materials", "Determine the medium best suited to produce the desired visual effect", "Design and produce graphics, layouts and illustrations for print, web and digital media", "Use design software (e.g., Adobe Creative Suite) and web tools to create assets", "Coordinate production of print, audio-visual or electronic materials such as websites"],
      coverLetterAngle: "Present a portfolio blending web and visual design, positioning yourself as a digital/web-leaning graphic designer who can also code your layouts." },
    { noc: "51112", title: "Technical Writer", teer: 1, category: "Design & Content",
      typicalEducation: "University degree or college diploma in a technical/scientific field plus strong…", medianWageCAD: "~$75,000/yr",
      countsForCEC: true, attainable: "medium",
      whyRelevant: "Your ability to read code and understand software lets your document products - a TEER 1 role many developers transition through.",
      sampleDuties: ["Write and edit technical manuals, user guides, specifications and online help", "Translate complex technical information into clear documentation for users", "Research products, software and processes to gather necessary information", "Collaborate with developers and subject-matter experts to document features", "Maintain and update documentation as products change"],
      coverLetterAngle: "Use your programming background to argue you can turn complex technical features into clear user guides and developer documentation." },
    { noc: "11202", title: "Marketing / Communications Specialist", teer: 1, category: "Business & Marketing",
      typicalEducation: "University degree or college diploma in communications, marketing, public relations,…", medianWageCAD: "~$74,000/yr",
      countsForCEC: true, attainable: "medium",
      whyRelevant: "Web, content and social-media skills support digital-marketing and social-media coordinator roles that fall in this TEER 1 group.",
      sampleDuties: ["Develop and implement communication, promotion and marketing strategies", "Plan and manage social-media, content and digital-marketing campaigns", "Create and coordinate website, email and online advertising content", "Analyze marketing needs and measure campaign performance", "Maintain media and public relations on behalf of an organization"],
      coverLetterAngle: "Frame yourself as a technically fluent digital-marketing/social-media coordinator who can build landing pages, run campaigns and read analytics." },
    { noc: "21232", title: "Software Developer / Programmer", teer: 1, category: "Web & Software",
      typicalEducation: "Bachelor's degree in computer science or a related field, or a college program in…", medianWageCAD: "~$100,000/yr",
      countsForCEC: true, attainable: "medium",
      whyRelevant: "Your C/C++ programming foundation aligns with general software development, though some employers prefer a degree or prior experience.",
      sampleDuties: ["Write, modify, integrate and test software code for applications", "Identify and communicate technical problems, processes and solutions", "Assist in collecting and documenting user requirements and specifications", "Maintain existing programs by making modifications as required", "Run diagnostic programs and debug software to verify effectiveness"],
      coverLetterAngle: "Emphasize coursework projects in C/C++ and any apps you built, presenting yourself as a coachable junior programmer eager to grow on a development team." },
    { noc: "21230", title: "Computer Systems Developer", teer: 1, category: "Web & Software",
      typicalEducation: "University degree or college program in computer science, mathematics or a related field", medianWageCAD: "~$90,000/yr",
      countsForCEC: true, attainable: "medium",
      whyRelevant: "Covers general programmer roles that build and modify application and systems code, a realistic step adjacent to your web focus.",
      sampleDuties: ["Write, modify, integrate and test code for software, data processing and systems-level software", "Maintain existing software by identifying and fixing defects", "Prepare reports, manuals and documentation on software status and maintenance", "Assist in collecting and documenting user requirements", "Research and evaluate a variety of software products"],
      coverLetterAngle: "Highlight your ability to write, debug and document code across languages and your diploma's systems/programming coursework as evidence you can contribute on day one." },
    { noc: "21223", title: "Database Analyst / Administrator", teer: 1, category: "Data",
      typicalEducation: "University degree or college program in computer science or a related field;…", medianWageCAD: "~$85,000/yr",
      countsForCEC: true, attainable: "stretch",
      whyRelevant: "Your diploma's database and SQL coursework provides a foundation for junior database/data-analyst work.",
      sampleDuties: ["Collect and document user requirements and design database architecture", "Design, construct, modify, integrate, implement and test data models and DBMS", "Operate database management systems to analyze data and perform data mining", "Conduct research and advise on selection and implementation of database tools", "Develop and implement data administration policies, standards and models"],
      coverLetterAngle: "Showcase SQL projects and data modeling from your program and apply as a junior data/database analyst willing to certify on a specific DBMS." },
    { noc: "21221", title: "Business Systems Specialist", teer: 1, category: "Business & Marketing",
      typicalEducation: "University degree or college program in computer science, business or a related field", medianWageCAD: "~$93,900/yr",
      countsForCEC: true, attainable: "stretch",
      whyRelevant: "Bridges your technical skills with business analysis; realistic after some IT experience or via junior BA/QA roles.",
      sampleDuties: ["Confer with clients to identify and document business and systems requirements", "Analyze information-systems processes and propose customized solutions", "Design, develop, integrate, test and implement information-systems business solutions", "Provide advice on systems strategy, policy, security and service delivery", "Act as a liaison between business units and technology teams"],
      coverLetterAngle: "Stress your ability to translate requirements into working solutions and to test systems, positioning yourself as a junior business systems analyst." },
    { noc: "21222", title: "Information Systems Specialist", teer: 1, category: "Business & Marketing",
      typicalEducation: "University degree or college program in computer science, business administration or a…", medianWageCAD: "~$96,000/yr",
      countsForCEC: true, attainable: "stretch",
      whyRelevant: "Includes QA-analyst and systems-analyst roles that your testing and programming coursework supports.",
      sampleDuties: ["Analyze, test and assess information-systems requirements", "Develop and implement information-systems plans, policies and procedures", "Collect and analyze data to identify areas for IT improvement", "Develop quality-assurance procedures and tests for new and existing systems", "Provide advice on a range of information-systems issues"],
      coverLetterAngle: "Lead with QA/testing aptitude and SDLC awareness from your diploma to enter as a junior information systems or QA analyst." },
    { noc: "21220", title: "Cybersecurity Specialist", teer: 1, category: "IT Support",
      typicalEducation: "University degree or college program in computer science, IT security or a related…", medianWageCAD: "~$103,000/yr",
      countsForCEC: true, attainable: "stretch",
      whyRelevant: "A fast-growing field you can pivot into from programming, though entry typically needs security certifications or experience.",
      sampleDuties: ["Confer with clients to identify and document security requirements and assess risks", "Apply encryption protocols and manage keys to protect data at rest and in transit", "Monitor access and credentials for information systems", "Install, test and operate security software such as anti-virus and threat-detection tools", "Carry out security measures in response to cybersecurity incidents"],
      coverLetterAngle: "Pair your programming diploma with an entry security certification (e.g., CompTIA Security+) and present yourself as a security-aware developer moving toward a SOC/analyst role." },
    { noc: "21231", title: "Software Engineer", teer: 1, category: "Web & Software",
      typicalEducation: "Bachelor's degree in computer science, software/computer engineering or mathematics;…", medianWageCAD: "~$117,500/yr",
      countsForCEC: true, attainable: "stretch",
      whyRelevant: "A higher-tier engineering role you can target after building experience, since the NOC typically expects a university degree.",
      sampleDuties: ["Collect and document user requirements and develop logical and physical specifications", "Research, evaluate and synthesize technical information to design and test computer-based systems", "Develop data, process and network models to optimize architecture", "Plan, design and coordinate development and integration of software systems", "Assess, test, troubleshoot and document software and operating environments"],
      coverLetterAngle: "Frame it as a 1-2 year growth goal while applying now to 'junior software engineer' postings that accept a strong diploma plus a project portfolio." },
    { noc: "21211", title: "Data Scientist", teer: 1, category: "Data",
      typicalEducation: "Bachelor's or graduate degree in computer science, mathematics, statistics or a related…", medianWageCAD: "~$96,000/yr",
      countsForCEC: true, attainable: "stretch",
      whyRelevant: "A stretch goal that builds on your programming base once you adds statistics and Python/ML skills.",
      sampleDuties: ["Extract, clean and prepare data using a programming language", "Build and apply machine-learning, statistical and predictive models", "Perform large-scale experimentation to identify relationships in datasets", "Develop algorithms such as regression, clustering, decision trees and neural networks", "Visualize and communicate findings and automated recommendations"],
      coverLetterAngle: "Target junior data-analyst stepping-stones first while upskilling in Python and machine learning to credibly move toward data science." },
    { noc: "20012", title: "IT / Systems Manager", teer: 0, category: "IT Support",
      typicalEducation: "University degree in computer science or business plus several years of IT experience;…", medianWageCAD: "~$138,700/yr",
      countsForCEC: true, attainable: "stretch",
      whyRelevant: "A TEER 0 long-term career goal rather than an entry role, included to show the upward path from your technical base (TEER 0 also counts for CEC).",
      sampleDuties: ["Plan, organize and direct the activities of IT/software teams", "Manage development, implementation and operation of systems and networks", "Set IT standards, budgets and project priorities", "Recruit, supervise and evaluate technical staff", "Liaise with clients and senior management on IT strategy"],
      coverLetterAngle: "Treat as a 5+ year aspiration; for now, demonstrate project leadership and aim for team-lead steps that build toward IT management." }
  ],

  /* ---- Phased action plan / timeline ---- */
  timeline: [
    { phase: "Now — start the clock", months: "Months 0–1",
      actions: [
        "Renew your passport for maximum validity (this gates the PGWP extension)",
        "Start full-time skilled work in a NOC TEER 0–3 role (e.g. Web Designer 21233)",
        "Set up payroll and begin an evidence file (contract, pay stubs)"
      ] },
    { phase: "Phase 1 — Secure status & sit language tests", months: "Months 1–3",
      deadline: "Nov 8, 2026 (PGWP expiry)",
      actions: [
        "File the PGWP passport-validity extension BEFORE your PGWP expires",
        "Sit the French test (TEF/TCF Canada) — target NCLC 9 in all four abilities",
        "Sit an English test (CELPIP/IELTS) — target CLB 5+ for the bilingual bonus",
        "Do NOT travel outside Canada while an extension is pending"
      ] },
    { phase: "Phase 2 — Bank 12 months of skilled work", months: "Months 3–12",
      actions: [
        "Work ≥30 hrs/week continuously to reach 1,560 hours",
        "Keep every pay stub; collect your T4 at year end",
        "Secure a NOC-compliant employer reference letter (all 7 elements)"
      ] },
    { phase: "Phase 3 — Express Entry profile & ITA", months: "Months 12–15",
      actions: [
        "Create your Express Entry profile under CEC + the French-language category",
        "Confirm your CRS clears recent French cut-offs",
        "Receive an Invitation to Apply (ITA) in a French draw"
      ] },
    { phase: "Phase 4 — e-APR & processing to PR", months: "Months 15–22",
      actions: [
        "Submit your e-APR within 60 days of the ITA (fees ≈ CAD $1,590)",
        "Complete the upfront medical exam and police certificates",
        "Receive your COPR — you're a Permanent Resident"
      ] }
  ],

  /* ---- Cost estimate (government fees, CAD) ---- */
  costs: [
    { item: "Passport renewal", amount: "$150", notes: "approx; enables PGWP extension" },
    { item: "PGWP passport-validity extension", amount: "$255", notes: "IMM 5710" },
    { item: "French test (TEF/TCF Canada)", amount: "$340" },
    { item: "English test (CELPIP/IELTS)", amount: "$280" },
    { item: "PR application + RPRF", amount: "$1,590", notes: "$990 processing + $600 right-of-PR" },
    { item: "Upfront medical exam", amount: "$300" },
    { item: "Police certificate(s)", amount: "$50" }
  ],

  /* ---- Cover-letter templates (placeholders auto-filled) ---- */
  coverLetters: [
    {
      variant: "Web / Front-End",
      body:
"Dear [Hiring Manager],\n\n" +
"I am writing to apply for the [Job Title] position at [Company Name]. I recently completed a two-year college diploma in [Field] in Canada, where I built hands-on experience in [Key Skill 1] and [Key Skill 2], and I am excited to bring that foundation to your team.\n\n" +
"During my studies I designed and built responsive web projects from wireframe to deployment, applying clean, accessible HTML, CSS and JavaScript. I care about the details that make an interface feel effortless, and I learn new tools quickly. You can see a sample of my work here: [Portfolio Link].\n\n" +
"What draws me to [Company Name] is the chance to grow as a developer while contributing real value from day one. I would welcome the opportunity to discuss how my skills can support your goals.\n\n" +
"Thank you for your time and consideration.\n\n" +
"Sincerely,\n[Your Name]"
    },
    {
      variant: "IT Support / QA",
      body:
"Dear [Hiring Manager],\n\n" +
"I am applying for the [Job Title] role at [Company Name]. With a Canadian college diploma in [Field] and a background in customer-facing work, I combine technical training with the patience and communication that great support depends on.\n\n" +
"I am comfortable diagnosing hardware and software issues, documenting solutions clearly, and following structured processes so nothing slips through the cracks. My coursework covered [Key Skill 1] and [Key Skill 2], and I pride myself on being dependable and detail-oriented under pressure.\n\n" +
"I would be glad to bring this mix of technical skill and service mindset to [Company Name], and I would welcome a conversation about the role.\n\n" +
"Thank you for considering my application.\n\n" +
"Best regards,\n[Your Name]"
    },
    {
      variant: "Concise / general",
      body:
"Dear [Hiring Manager],\n\n" +
"Please accept my application for the [Job Title] position at [Company Name]. I am a recent Canadian graduate in [Field] with practical skills in [Key Skill 1] and [Key Skill 2], and I am eager to contribute and keep learning.\n\n" +
"I bring a strong work ethic, quick adaptability, and a genuine enthusiasm for the work your team does. My portfolio is available at [Portfolio Link].\n\n" +
"I would appreciate the chance to discuss how I can help. Thank you for your consideration.\n\n" +
"Sincerely,\n[Your Name]"
    }
  ],

  /* ---- Résumé optimization tips ---- */
  resumeTips: [
    "Mirror the exact job title and key duties from the posting — many employers screen with ATS software.",
    "Quantify impact: \"rebuilt a 12-page site, cutting load time 40%\" beats \"worked on websites\".",
    "Lead with a Skills section listing concrete tools (HTML, CSS, JavaScript, C, C++, Git, Figma).",
    "Use Canadian formatting: no photo, no date of birth, no marital status — just name, city, phone, email.",
    "Add a portfolio/GitHub link near the top; for web roles it matters more than a long summary.",
    "Frame class projects as real work with outcomes — recruiters value evidence over job titles.",
    "Keep it to 1–2 pages with consistent fonts, clear headings and generous white space.",
    "Use strong action verbs (built, designed, automated, tested, deployed) and the past tense.",
    "Tailor each application — swap in the keywords and tools the specific posting emphasizes.",
    "Proofread ruthlessly; a single typo can sink an otherwise strong technical résumé."
  ],

  /* ---- Employer reference-letter checklist (CEC-critical) ---- */
  referenceLetterChecklist: [
    "Printed on official company letterhead",
    "Signed by a manager/HR with their name, title and contact details",
    "Your full name and official job title(s)",
    "Start date (and end date, or \"currently employed since…\")",
    "Whether the role is full-time or part-time",
    "Number of hours worked per week",
    "Annual salary plus any benefits",
    "A detailed list of your main duties — in plain language matching your NOC",
    "Company address, phone, email and website"
  ],

  /* ---- Evidence file checklist (collect from day one) ---- */
  evidenceFileChecklist: [
    "Signed employment contract / offer letter",
    "Every pay stub (keep them all)",
    "T4 slip and CRA Notice of Assessment",
    "Bank statements showing salary deposits",
    "The employer reference letter (once issued)",
    "A portfolio of the actual work you produced",
    "Any promotion or salary-increase letters"
  ]
};
