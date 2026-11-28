/* ===========================================================
   NIMCET Prep 2027 — Formula sheet
   Searchable last-mile revision reference, grouped by chapter.
   =========================================================== */
(function () {
    const App = window.NIMCET;

    const SHEET = [
        {
            sec: 'math', group: 'Algebra — Quadratic Equations', items: [
                'For ax² + bx + c = 0 : x = [ −b ± √(b² − 4ac) ] / 2a',
                'Discriminant D = b² − 4ac',
                'D &gt; 0 → real & distinct · D = 0 → real & equal · D &lt; 0 → complex conjugate',
                'Sum of roots α + β = −b/a',
                'Product of roots αβ = c/a',
                'Equation from roots: x² − (α+β)x + αβ = 0',
                'α − β = ±√D / a',
                'α² + β² = (α+β)² − 2αβ'
            ]
        },
        {
            sec: 'math', group: 'Algebra — Progressions', items: [
                'AP: aₙ = a + (n−1)d',
                'AP sum: Sₙ = n/2 [ 2a + (n−1)d ] = n/2 (a + l)',
                'GP: aₙ = a·r^(n−1)',
                'GP sum: Sₙ = a(rⁿ − 1)/(r − 1), r ≠ 1',
                'Infinite GP: S∞ = a/(1 − r), |r| &lt; 1',
                'HP: reciprocals form an AP; nth term = 1/[a + (n−1)d]',
                'AM = (a+b)/2 · GM = √(ab) · HM = 2ab/(a+b)',
                'AM ≥ GM ≥ HM, and GM² = AM × HM',
                'Σn = n(n+1)/2 · Σn² = n(n+1)(2n+1)/6 · Σn³ = [n(n+1)/2]²'
            ]
        },
        {
            sec: 'math', group: 'Algebra — Logarithms & Indices', items: [
                'log(mn) = log m + log n',
                'log(m/n) = log m − log n',
                'log(mⁿ) = n log m',
                'Change of base: log_b a = log_c a / log_c b',
                'a^(log_a x) = x · log_a a = 1 · log_a 1 = 0',
                'aᵐ · aⁿ = a^(m+n) · (aᵐ)ⁿ = a^(mn) · a^(−n) = 1/aⁿ'
            ]
        },
        {
            sec: 'math', group: 'Algebra — Matrices & Determinants', items: [
                '(AB)ᵀ = Bᵀ Aᵀ · (AB)⁻¹ = B⁻¹ A⁻¹',
                'A⁻¹ = adj(A) / |A|, valid when |A| ≠ 0',
                '|AB| = |A| · |B| · |Aᵀ| = |A|',
                '|kA| = kⁿ |A| for an n × n matrix',
                '|A⁻¹| = 1/|A| · |adj A| = |A|^(n−1)',
                '2×2 determinant: |a b ; c d| = ad − bc',
                'Cramer\'s rule: xᵢ = Dᵢ / D, provided D ≠ 0',
                'Singular matrix ⇔ |A| = 0 ⇔ inverse does not exist'
            ]
        },
        {
            sec: 'math', group: 'Set Theory & Counting', items: [
                'n(A ∪ B) = n(A) + n(B) − n(A ∩ B)',
                'n(A∪B∪C) = Σn(A) − Σn(A∩B) + n(A∩B∩C)',
                'Subsets of a set with n elements = 2ⁿ · proper subsets = 2ⁿ − 1',
                'ⁿPᵣ = n! / (n−r)!',
                'ⁿCᵣ = n! / [ r! (n−r)! ]',
                'ⁿCᵣ = ⁿC₍ₙ₋ᵣ₎ · ⁿCᵣ + ⁿC₍ᵣ₋₁₎ = ⁿ⁺¹Cᵣ',
                'Circular permutations of n objects = (n−1)!',
                'Arrangements of n items with repeats p, q, r = n! / (p! q! r!)'
            ]
        },
        {
            sec: 'math', group: 'Probability & Statistics', items: [
                'P(A) = favourable outcomes / total outcomes, 0 ≤ P(A) ≤ 1',
                'P(A ∪ B) = P(A) + P(B) − P(A ∩ B)',
                'Mutually exclusive: P(A ∩ B) = 0',
                'Independent events: P(A ∩ B) = P(A) · P(B)',
                'Conditional: P(A|B) = P(A ∩ B) / P(B)',
                'Bayes: P(A|B) = P(B|A) P(A) / P(B)',
                'Complement: P(A′) = 1 − P(A)',
                'Mean = Σx / n · for grouped data Σfx / Σf',
                'Variance σ² = Σ(x − x̄)² / n = (Σx²/n) − x̄²',
                'Standard deviation σ = √variance',
                'Mode = 3 Median − 2 Mean (empirical relation)'
            ]
        },
        {
            sec: 'math', group: 'Coordinate Geometry — Lines', items: [
                'Distance = √[(x₂−x₁)² + (y₂−y₁)²]',
                'Section formula (internal): ( (mx₂+nx₁)/(m+n), (my₂+ny₁)/(m+n) )',
                'Midpoint = ( (x₁+x₂)/2, (y₁+y₂)/2 )',
                'Centroid = ( (x₁+x₂+x₃)/3, (y₁+y₂+y₃)/3 )',
                'Area of triangle = ½ |x₁(y₂−y₃) + x₂(y₃−y₁) + x₃(y₁−y₂)|',
                'Slope m = (y₂−y₁)/(x₂−x₁) = tan θ',
                'Slope–intercept: y = mx + c · Point–slope: y − y₁ = m(x − x₁)',
                'Intercept form: x/a + y/b = 1',
                'Angle between lines: tan θ = |(m₁ − m₂)/(1 + m₁m₂)|',
                'Parallel ⇔ m₁ = m₂ · Perpendicular ⇔ m₁m₂ = −1',
                'Distance of point from line: |ax₁ + by₁ + c| / √(a² + b²)',
                'Distance between parallel lines: |c₁ − c₂| / √(a² + b²)'
            ]
        },
        {
            sec: 'math', group: 'Coordinate Geometry — Conics', items: [
                'Circle (centre h,k radius r): (x−h)² + (y−k)² = r²',
                'General circle: x² + y² + 2gx + 2fy + c = 0, centre (−g,−f), r = √(g²+f²−c)',
                'Parabola y² = 4ax : focus (a,0), directrix x = −a, latus rectum 4a',
                'Ellipse x²/a² + y²/b² = 1 : e = √(1 − b²/a²), foci (±ae, 0)',
                'Ellipse latus rectum = 2b²/a',
                'Hyperbola x²/a² − y²/b² = 1 : e = √(1 + b²/a²)',
                'Hyperbola asymptotes: y = ±(b/a)x',
                'Tangent to y² = 4ax at (x₁,y₁): yy₁ = 2a(x + x₁)'
            ]
        },
        {
            sec: 'math', group: 'Trigonometry', items: [
                'sin²θ + cos²θ = 1 · 1 + tan²θ = sec²θ · 1 + cot²θ = cosec²θ',
                'sin(A±B) = sinA cosB ± cosA sinB',
                'cos(A±B) = cosA cosB ∓ sinA sinB',
                'tan(A±B) = (tanA ± tanB)/(1 ∓ tanA tanB)',
                'sin2θ = 2 sinθ cosθ · cos2θ = cos²θ − sin²θ = 2cos²θ − 1 = 1 − 2sin²θ',
                'tan2θ = 2tanθ/(1 − tan²θ)',
                'sin3θ = 3sinθ − 4sin³θ · cos3θ = 4cos³θ − 3cosθ',
                'Sine rule: a/sinA = b/sinB = c/sinC = 2R',
                'Cosine rule: cosA = (b² + c² − a²)/(2bc)',
                'Area of triangle = ½ ab sinC = √[s(s−a)(s−b)(s−c)]',
                'r = Δ/s · R = abc/(4Δ)',
                'General solution: sinθ = sinα ⇒ θ = nπ + (−1)ⁿ α',
                'cosθ = cosα ⇒ θ = 2nπ ± α · tanθ = tanα ⇒ θ = nπ + α'
            ]
        },
        {
            sec: 'math', group: 'Calculus — Limits & Derivatives', items: [
                'lim(x→0) sinx/x = 1 · lim(x→0) tanx/x = 1',
                'lim(x→0) (eˣ − 1)/x = 1 · lim(x→0) (aˣ − 1)/x = ln a',
                'lim(x→0) ln(1+x)/x = 1 · lim(x→∞) (1 + 1/x)ˣ = e',
                'lim(x→a) (xⁿ − aⁿ)/(x − a) = n a^(n−1)',
                'd/dx (xⁿ) = n x^(n−1) · d/dx (eˣ) = eˣ · d/dx (ln x) = 1/x',
                'd/dx (sinx) = cosx · d/dx (cosx) = −sinx · d/dx (tanx) = sec²x',
                'Product rule: (uv)′ = u′v + uv′',
                'Quotient rule: (u/v)′ = (u′v − uv′)/v²',
                'Chain rule: dy/dx = dy/du × du/dx',
                'Tangent slope at (x₁,y₁) = (dy/dx) at that point; normal slope = −1/(dy/dx)',
                'Maxima/minima: f′(x) = 0; f″(x) &lt; 0 → maximum, f″(x) &gt; 0 → minimum'
            ]
        },
        {
            sec: 'math', group: 'Calculus — Integration', items: [
                '∫xⁿ dx = x^(n+1)/(n+1) + C, n ≠ −1',
                '∫(1/x) dx = ln|x| + C · ∫eˣ dx = eˣ + C',
                '∫sinx dx = −cosx + C · ∫cosx dx = sinx + C',
                '∫sec²x dx = tanx + C · ∫cosec²x dx = −cotx + C',
                '∫dx/(x² + a²) = (1/a) tan⁻¹(x/a) + C',
                '∫dx/√(a² − x²) = sin⁻¹(x/a) + C',
                'By parts: ∫u v dx = u ∫v dx − ∫ (u′ ∫v dx) dx  [ILATE order]',
                '∫ₐᵇ f(x) dx = −∫ᵇₐ f(x) dx',
                '∫₀ᵃ f(x) dx = ∫₀ᵃ f(a − x) dx',
                '∫₋ₐᵃ f(x) dx = 2∫₀ᵃ f(x) dx if f is even, 0 if f is odd',
                'Area between curves = ∫ₐᵇ |f(x) − g(x)| dx'
            ]
        },
        {
            sec: 'math', group: 'Vectors', items: [
                '|a| = √(a₁² + a₂² + a₃²)',
                'a · b = |a||b| cosθ = a₁b₁ + a₂b₂ + a₃b₃',
                'Perpendicular ⇔ a · b = 0',
                'a × b = |a||b| sinθ n̂ ; |a × b| = area of parallelogram',
                'Parallel ⇔ a × b = 0',
                'Area of triangle = ½ |a × b|',
                'Scalar triple product [a b c] = a · (b × c) = volume of parallelepiped',
                'Coplanar ⇔ [a b c] = 0',
                'Projection of a on b = (a · b)/|b|',
                'Work done = F · d · Moment of force = r × F'
            ]
        },
        {
            sec: 'computer', group: 'Number Systems & Data Representation', items: [
                'Binary → decimal: multiply each bit by 2^position and sum',
                'Decimal → binary: repeated division by 2, read remainders bottom-up',
                'Hex digit = exactly 4 bits · Octal digit = exactly 3 bits',
                '1\'s complement: invert every bit',
                '2\'s complement: invert every bit, then add 1',
                'Range of n-bit signed (2\'s complement): −2^(n−1) to 2^(n−1) − 1',
                'Range of n-bit unsigned: 0 to 2ⁿ − 1',
                'n bits address 2ⁿ distinct locations',
                'ASCII = 7 bits (128 characters) · Extended ASCII = 8 bits · Unicode ≥ 16 bits',
                'IEEE 754 single precision: 1 sign + 8 exponent + 23 mantissa = 32 bits',
                'IEEE 754 double precision: 1 + 11 + 52 = 64 bits',
                'Normalised form: exactly one non-zero digit before the point'
            ]
        },
        {
            sec: 'computer', group: 'Boolean Algebra & Logic', items: [
                'A + 0 = A · A + 1 = 1 · A · 0 = 0 · A · 1 = A',
                'A + A = A · A · A = A (idempotent)',
                'A + A′ = 1 · A · A′ = 0 (complement)',
                'A + AB = A · A(A + B) = A (absorption)',
                'A + A′B = A + B',
                'De Morgan: (A + B)′ = A′B′ · (AB)′ = A′ + B′',
                'XOR: A ⊕ B = A′B + AB′ ; A ⊕ A = 0 ; A ⊕ 0 = A',
                'NAND and NOR are each functionally complete',
                'n input variables → 2ⁿ rows in the truth table',
                'Minterm = product term where the function is 1; SOP is the sum of minterms'
            ]
        },
        {
            sec: 'computer', group: 'Memory & Architecture', items: [
                '1 byte = 8 bits · 1 KB = 2¹⁰ B · 1 MB = 2²⁰ B · 1 GB = 2³⁰ B',
                'Memory size = number of locations × word size',
                'Address lines needed for N locations = log₂N',
                'Speed order: registers &gt; cache &gt; RAM &gt; SSD &gt; HDD &gt; tape',
                'Cost per bit and capacity move opposite to speed in the hierarchy',
                'Hit ratio = hits / total accesses',
                'Average access time = h·Tc + (1 − h)·Tm',
                'Instruction cycle = fetch → decode → execute → store',
                'Program Counter holds the address of the next instruction',
                'MAR holds the address, MBR/MDR holds the data'
            ]
        }
    ];

    App.registerRoute('formulas', function () {
        App.view().innerHTML = `
            <div class="page-head">
                <h1>Formula Sheet</h1>
                <p>Every formula the NIMCET syllabus can draw on, grouped by chapter. Built for the final
                   fortnight — read it top to bottom once a day and gaps stop appearing.</p>
                <div class="gl-search-bar" style="display:flex;gap:12px;align-items:center;margin-top:14px;flex-wrap:wrap">
                    <input type="search" id="fsSearch" class="search" placeholder="Filter formulas — try 'determinant', 'complement', 'integral'…"
                           style="flex:1 1 340px;min-width:0;padding:11px 14px;font-size:14px;border:1px solid var(--border);border-radius:10px;background:var(--bg-elev);color:inherit;font-family:inherit">
                    <span class="chip" id="fsCount"></span>
                    <button class="btn" onclick="window.print()">🖨️ Print</button>
                </div>
            </div>
            <div class="fs-grid" id="fsBody"></div>`;

        const body = App.el('fsBody'), count = App.el('fsCount'), search = App.el('fsSearch');

        function draw(q) {
            const term = (q || '').trim().toLowerCase();
            let shown = 0;
            body.innerHTML = SHEET.map(g => {
                const sec = App.sectionById(g.sec);
                const items = term
                    ? g.items.filter(i => i.toLowerCase().includes(term) || g.group.toLowerCase().includes(term))
                    : g.items;
                if (!items.length) return '';
                shown += items.length;
                return `<div class="fs-card">
                    <h3 style="color:${sec ? sec.color : 'var(--brand)'}">${g.group}</h3>
                    <ul>${items.map(i => `<li>${i}</li>`).join('')}</ul>
                </div>`;
            }).join('') || `<p class="muted">No formula matches “${App.esc(term)}”.</p>`;
            count.textContent = `${shown} formulas`;
        }

        draw('');
        search.addEventListener('input', () => draw(search.value));
    });

    // Make formulas findable from the global search box.
    SHEET.forEach(g => App.searchIndex.push({
        title: g.group, course: 'Formula sheet',
        keywords: g.items.join(' '), hash: '#/formulas'
    }));
})();
