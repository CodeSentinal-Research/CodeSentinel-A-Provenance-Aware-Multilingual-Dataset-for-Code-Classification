/* ===========================================================
   NIMCET Prep 2027 — Sectional drills

   Short, timed, single-section papers for targeted practice.
   Use these when a full-length paper is too long: they surface a
   weak topic in 15-30 minutes instead of two hours.

   Same rules as the real exam (+12 / -3) and the same engine, so
   the section-wise analysis on the results page still applies.
   All questions are original and pattern-based.
   =========================================================== */
(function () {
    const App = window.NIMCET;

    const Q = (section, topic, q, a, c, why) => ({ section, topic, q, a, c, why });

    /* ---------------- Mathematics drill ---------------- */
    App.registerPaper({
        id: 'sec-math',
        kind: 'sectional',
        title: 'Mathematics Drill — 25 Questions',
        durationMin: 30,
        blurb: 'Covers all seven Maths units in proportion to their exam weight. Target: 25 questions in 30 minutes, the pace the real paper demands.',
        questions: [
            /* Calculus 5 */
            Q('math', 'Calculus', 'lim<sub>x→0</sub> (sin 7x)/(2x) equals:', ['7/2', '2/7', '7', '1'], 0,
                'Rewrite as (7/2)·(sin7x)/(7x); the bracket tends to 1.'),
            Q('math', 'Calculus', 'If y = (2x + 1)⁵, then dy/dx equals:', ['10(2x + 1)⁴', '5(2x + 1)⁴', '2(2x + 1)⁴', '10(2x + 1)⁵'], 0,
                'Chain rule: 5(2x+1)⁴ × 2 = 10(2x+1)⁴.'),
            Q('math', 'Calculus', '∫ cos x dx equals:', ['sin x + C', '−sin x + C', 'tan x + C', '−cos x + C'], 0,
                'The antiderivative of cosine is sine.'),
            Q('math', 'Calculus', 'The maximum value of f(x) = 6 − (x − 2)² is:', ['6', '2', '4', '0'], 0,
                'The squared term is never negative, so f is largest when it is zero, at x = 2.'),
            Q('math', 'Calculus', 'The value of ∫₀¹ 3x² dx is:', ['1', '3', '1/3', '2'], 0,
                '[x³]₀¹ = 1.'),

            /* Algebra 5 */
            Q('math', 'Algebra', 'If α + β = 7 and αβ = 10, the quadratic with these roots is:', ['x² − 7x + 10 = 0', 'x² + 7x + 10 = 0', 'x² − 10x + 7 = 0', 'x² − 7x − 10 = 0'], 0,
                'The standard form is x² − (sum)x + (product) = 0.'),
            Q('math', 'Algebra', 'The sum of the first 12 terms of the AP 4, 9, 14, … is:', ['378', '360', '390', '350'], 0,
                'S₁₂ = 12/2 [2(4) + 11(5)] = 6(8 + 55) = 6 × 63 = 378.'),
            Q('math', 'Algebra', 'If log₅ x = 3, then x equals:', ['125', '15', '25', '8'], 0,
                '5³ = 125.'),
            Q('math', 'Algebra', 'For a 2×2 matrix A with |A| = 3, |A²| equals:', ['9', '6', '3', '12'], 0,
                '|A²| = |A|² = 9.'),
            Q('math', 'Algebra', 'The common ratio of the GP 81, 27, 9, … is:', ['1/3', '3', '−3', '1/9'], 0,
                'Each term is a third of the one before it.'),

            /* Coordinate 4 */
            Q('math', 'Coordinate Geometry', 'The distance between (−1, 3) and (2, 7) is:', ['5', '4', '25', '√5'], 0,
                '√(3² + 4²) = 5.'),
            Q('math', 'Coordinate Geometry', 'The slope of a line parallel to 3x − y = 4 is:', ['3', '−3', '1/3', '−1/3'], 0,
                'Rewriting gives y = 3x − 4, and parallel lines share the slope 3.'),
            Q('math', 'Coordinate Geometry', 'The centre of the circle (x − 2)² + (y + 5)² = 9 is:', ['(2, −5)', '(−2, 5)', '(2, 5)', '(9, 9)'], 0,
                'Standard form (x − h)² + (y − k)² = r² gives centre (h, k) = (2, −5).'),
            Q('math', 'Coordinate Geometry', 'The vertex of the parabola y² = −8x is:', ['(0, 0)', '(−2, 0)', '(2, 0)', '(0, −2)'], 0,
                'All parabolas of the form y² = 4ax have their vertex at the origin.'),

            /* Probability 4 */
            Q('math', 'Probability & Statistics', 'A die is thrown once. P(getting a prime number) is:', ['1/2', '1/3', '2/3', '1/6'], 0,
                'The primes on a die are 2, 3 and 5 — three of six outcomes.'),
            Q('math', 'Probability & Statistics', 'The mean of the first 5 even natural numbers is:', ['6', '5', '10', '4'], 0,
                '(2 + 4 + 6 + 8 + 10)/5 = 30/5 = 6.'),
            Q('math', 'Probability & Statistics', 'If two events are mutually exclusive, then P(A ∩ B) equals:', ['0', '1', 'P(A)P(B)', 'P(A) + P(B)'], 0,
                'Mutually exclusive events cannot occur together, so their intersection is empty.'),
            Q('math', 'Probability & Statistics', 'The range of 12, 5, 18, 7, 20 is:', ['15', '13', '20', '8'], 0,
                'Range = largest − smallest = 20 − 5 = 15.'),

            /* Trigonometry 3 */
            Q('math', 'Trigonometry', 'The value of sin 90° − cos 90° is:', ['1', '0', '−1', '2'], 0,
                'sin90° = 1 and cos90° = 0, so the difference is 1.'),
            Q('math', 'Trigonometry', '1 + tan²θ equals:', ['sec²θ', 'cosec²θ', 'cot²θ', 'sin²θ'], 0,
                'This is a standard Pythagorean identity.'),
            Q('math', 'Trigonometry', 'If tan θ = 1, the smallest positive θ is:', ['45°', '30°', '60°', '90°'], 0,
                'tan45° = 1.'),

            /* Vectors 2 */
            Q('math', 'Vectors', 'If a = 2i − j and b = i + 2j, then a · b equals:', ['0', '4', '2', '−2'], 0,
                '(2)(1) + (−1)(2) = 0, so the vectors are perpendicular.'),
            Q('math', 'Vectors', 'The magnitude of 6i − 8j is:', ['10', '14', '2', '100'], 0,
                '√(36 + 64) = √100 = 10.'),

            /* Set theory 2 */
            Q('math', 'Set Theory & Counting', 'The value of ⁷C₃ is:', ['35', '21', '210', '42'], 0,
                '7·6·5/(3·2·1) = 210/6 = 35.'),
            Q('math', 'Set Theory & Counting', 'The number of arrangements of the letters of BOOK is:', ['12', '24', '6', '4'], 0,
                '4 letters with O repeated twice: 4!/2! = 12.')
        ]
    });

    /* ---------------- Reasoning drill ---------------- */
    App.registerPaper({
        id: 'sec-reasoning',
        kind: 'sectional',
        title: 'Reasoning Drill — 20 Questions',
        durationMin: 20,
        blurb: 'One minute per question across series, syllogisms, puzzles, coding and direction sense. The fastest section to improve and the cheapest marks in the paper.',
        questions: [
            Q('reasoning', 'Number & Letter Series', 'Find the next term: 7, 14, 28, 56, ?', ['112', '108', '96', '120'], 0,
                'Each term doubles the previous one.'),
            Q('reasoning', 'Number & Letter Series', 'Find the next term: 2, 3, 5, 7, 11, ?', ['13', '12', '14', '15'], 0,
                'These are consecutive prime numbers.'),
            Q('reasoning', 'Number & Letter Series', 'Find the missing letter: Z, X, V, T, ?', ['R', 'S', 'Q', 'P'], 0,
                'The sequence steps back two letters each time.'),
            Q('reasoning', 'Number & Letter Series', 'Find the odd one out: 16, 25, 36, 48, 49', ['48', '16', '36', '49'], 0,
                'All the others are perfect squares.'),
            Q('reasoning', 'Syllogisms & Logical Deduction', 'Statements: All doctors are graduates. Some graduates are rich. Conclusion I: Some doctors are rich. Conclusion II: All graduates are doctors.', ['Neither follows', 'Only I follows', 'Only II follows', 'Both follow'], 0,
                'The rich graduates need not include any doctor, and II reverses the first statement.'),
            Q('reasoning', 'Syllogisms & Logical Deduction', 'Statements: All keys are locks. No lock is a door. Conclusion I: No key is a door. Conclusion II: Some keys are doors.', ['Only I follows', 'Only II follows', 'Both follow', 'Neither follows'], 0,
                'Keys lie wholly inside locks, which are wholly outside doors.'),
            Q('reasoning', 'Syllogisms & Logical Deduction', 'Statements: Some pens are blue. All blue things are bright. Conclusion I: Some pens are bright. Conclusion II: All pens are bright.', ['Only I follows', 'Only II follows', 'Both follow', 'Neither follows'], 0,
                'The blue pens must be bright; the rest are unconstrained.'),
            Q('reasoning', 'Seating Arrangement & Puzzles', 'In a row of 30 students, Neha is 8th from the left. What is her position from the right?', ['23rd', '22nd', '24th', '21st'], 0,
                '30 − 8 + 1 = 23.'),
            Q('reasoning', 'Seating Arrangement & Puzzles', 'Five people stand in a line. X is immediately left of Y. Z is at the right end. W is immediately left of X. Who is at the left end?', ['W or V', 'X', 'Y', 'Z'], 0,
                'The block W-X-Y sits before Z; the fifth person V can take either remaining slot, so the left end is W or V.'),
            Q('reasoning', 'Seating Arrangement & Puzzles', 'Ravi ranks 12th from the top and 18th from the bottom in a class. How many students are there?', ['29', '30', '28', '31'], 0,
                '12 + 18 − 1 = 29.'),
            Q('reasoning', 'Blood Relations & Direction Sense', 'A is the mother of B. B is the sister of C. How is A related to C?', ['Mother', 'Aunt', 'Sister', 'Grandmother'], 0,
                'B and C are siblings, so A is the mother of both.'),
            Q('reasoning', 'Blood Relations & Direction Sense', 'A man walks 3 km south, then 4 km west. How far is he from the start?', ['5 km', '7 km', '1 km', '12 km'], 0,
                'The legs are perpendicular: √(9 + 16) = 5 km.'),
            Q('reasoning', 'Blood Relations & Direction Sense', 'Facing east, you turn 180° and then 90° clockwise. Which direction do you face?', ['North', 'South', 'East', 'West'], 0,
                'East → 180° gives West → 90° clockwise from West gives North.'),
            Q('reasoning', 'Coding–Decoding', 'If SUN is coded as TVO, then MOON is coded as:', ['NPPO', 'NPPN', 'NOOP', 'NPON'], 0,
                'Each letter advances by one: M→N, O→P, O→P, N→O.'),
            Q('reasoning', 'Coding–Decoding', 'If FACE is written as ECAF, the rule is:', ['Reverse the letters', 'Shift each letter forward', 'Shift each letter back', 'Swap vowels only'], 0,
                'ECAF is FACE written backwards.'),
            Q('reasoning', 'Analogy & Classification', 'Sculptor : Statue :: Poet : ?', ['Poem', 'Pen', 'Words', 'Stage'], 0,
                'The relation is creator to the work created.'),
            Q('reasoning', 'Analogy & Classification', 'Find the odd one out: Rose, Lily, Mango, Jasmine', ['Mango', 'Rose', 'Lily', 'Jasmine'], 0,
                'The others are flowers; mango is a fruit.'),
            Q('reasoning', 'Data Interpretation', 'A shop sold 40, 55, 65 and 60 items over four weeks. What was the average weekly sale?', ['55', '50', '60', '65'], 0,
                'Total 220 across 4 weeks gives 55.'),
            Q('reasoning', 'Data Interpretation', 'If a quantity rises from 80 to 100, the percentage increase is:', ['25%', '20%', '30%', '15%'], 0,
                'Increase 20 on a base of 80 is 25%.'),
            Q('reasoning', 'Clocks, Calendars & Cubes', 'How many times do the hands of a clock overlap in 12 hours?', ['11', '12', '10', '24'], 0,
                'The hands coincide 11 times in 12 hours, because one overlap is "lost" over a full cycle.')
        ]
    });

    /* ---------------- Computer Awareness drill ---------------- */
    App.registerPaper({
        id: 'sec-computer',
        kind: 'sectional',
        title: 'Computer Awareness Drill — 20 Questions',
        durationMin: 15,
        blurb: 'The most compressible section in the paper: 20 questions of pure recall that a prepared candidate finishes in ten minutes, banking time for Maths.',
        questions: [
            Q('computer', 'Computer Basics & Organisation', 'CPU stands for:', ['Central Processing Unit', 'Computer Personal Unit', 'Central Program Unit', 'Control Processing Unit'], 0,
                'The processor that executes instructions is the Central Processing Unit.'),
            Q('computer', 'Computer Basics & Organisation', 'Which of the following is application software?', ['MS Excel', 'Windows', 'Linux', 'BIOS'], 0,
                'Excel performs a user task; the others are system-level software.'),
            Q('computer', 'Computer Basics & Organisation', 'The set of programs that controls the hardware is the:', ['Operating system', 'Application', 'Compiler', 'Utility'], 0,
                'The operating system manages hardware resources for all other programs.'),
            Q('computer', 'Computer Basics & Organisation', 'Fourth-generation computers are characterised by:', ['Microprocessors', 'Vacuum tubes', 'Transistors', 'Integrated circuits'], 0,
                'The fourth generation introduced the microprocessor on a single chip.'),
            Q('computer', 'Computer Basics & Organisation', 'A program that translates assembly language into machine code is a:', ['Assembler', 'Compiler', 'Interpreter', 'Linker'], 0,
                'The assembler is specific to assembly language.'),
            Q('computer', 'Computer Basics & Organisation', 'Firmware is typically stored in:', ['ROM', 'RAM', 'Cache', 'Hard disk'], 0,
                'Firmware must survive power loss, so it lives in read-only memory.'),
            Q('computer', 'Number Systems & Data Representation', 'The binary equivalent of decimal 16 is:', ['10000', '1000', '1100', '10001'], 0,
                '16 is 2⁴, which sets a single bit in the fifth position.'),
            Q('computer', 'Number Systems & Data Representation', 'The decimal equivalent of octal 17 is:', ['15', '17', '14', '23'], 0,
                '1 × 8 + 7 = 15.'),
            Q('computer', 'Number Systems & Data Representation', 'How many bytes are in 2 KB?', ['2048', '2000', '1024', '4096'], 0,
                '2 × 1024 = 2048 bytes.'),
            Q('computer', 'Number Systems & Data Representation', 'The hexadecimal digit A represents the decimal value:', ['10', '11', '12', '15'], 0,
                'Hex digits run 0–9 then A=10 through F=15.'),
            Q('computer', 'Number Systems & Data Representation', 'The binary number 1111 in decimal is:', ['15', '16', '14', '11'], 0,
                '8 + 4 + 2 + 1 = 15.'),
            Q('computer', 'Memory & I/O Devices', 'Which memory retains data without power?', ['ROM', 'RAM', 'Cache', 'Register'], 0,
                'ROM is non-volatile; the other three lose their contents.'),
            Q('computer', 'Memory & I/O Devices', 'Which is a secondary storage device?', ['Hard disk', 'RAM', 'Cache', 'Register'], 0,
                'Secondary storage is non-volatile and sits outside the CPU–memory path.'),
            Q('computer', 'Memory & I/O Devices', 'A scanner is an example of:', ['An input device', 'An output device', 'A storage device', 'A processing device'], 0,
                'It converts physical documents into data for the computer.'),
            Q('computer', 'Binary Arithmetic', 'The binary addition 1100 + 0011 gives:', ['1111', '1110', '1001', '10000'], 0,
                '12 + 3 = 15, which is 1111.'),
            Q('computer', 'Binary Arithmetic', "The 2's complement of 0001 in 4 bits is:", ['1111', '1110', '0001', '1000'], 0,
                "Invert to 1110, then add 1 to get 1111, which represents −1."),
            Q('computer', 'Binary Arithmetic', 'Binary 1000 divided by binary 10 gives:', ['100', '10', '1000', '110'], 0,
                '8 ÷ 2 = 4, which is 100 in binary.'),
            Q('computer', 'Boolean Algebra & Truth Tables', 'The output of an OR gate is 0 only when:', ['All inputs are 0', 'All inputs are 1', 'Inputs differ', 'Any input is 0'], 0,
                'OR outputs 1 if any input is high, so it is 0 only when every input is low.'),
            Q('computer', 'Boolean Algebra & Truth Tables', 'A · 1 equals:', ['A', '1', '0', "A′"], 0,
                'ANDing with 1 leaves the variable unchanged.'),
            Q('computer', 'Boolean Algebra & Truth Tables', "De Morgan's theorem states that (A + B)′ equals:", ["A′·B′", "A′ + B′", "A·B", "A + B"], 0,
                'The complement of a sum is the product of the complements.')
        ]
    });

    /* ---------------- English drill ---------------- */
    App.registerPaper({
        id: 'sec-english',
        kind: 'sectional',
        title: 'General English Drill — 15 Questions',
        durationMin: 12,
        blurb: 'Only 10 questions appear in the real paper, but they are the fastest marks available. This drill covers vocabulary, grammar, comprehension and technical usage.',
        questions: [
            Q('english', 'Vocabulary & Word Power', 'Choose the synonym of CANDID:', ['Frank', 'Secretive', 'Rude', 'Cautious'], 0,
                'Candid means open and straightforward in speech.'),
            Q('english', 'Vocabulary & Word Power', 'Choose the synonym of OBSOLETE:', ['Outdated', 'Modern', 'Rare', 'Expensive'], 0,
                'Obsolete describes something no longer in use.'),
            Q('english', 'Vocabulary & Word Power', 'Choose the antonym of CONCISE:', ['Verbose', 'Brief', 'Clear', 'Exact'], 0,
                'Concise means brief; verbose means using too many words.'),
            Q('english', 'Vocabulary & Word Power', 'The word REDUNDANT in a technical document means:', ['Unnecessary or duplicated', 'Essential', 'Encrypted', 'Compressed'], 0,
                'Redundant information repeats what is already stated.'),
            Q('english', 'Vocabulary & Word Power', 'Choose the correctly spelt word:', ['Occurrence', 'Occurence', 'Ocurrence', 'Occurrance'], 0,
                'The word takes a double c, a double r and the ending -ence.'),
            Q('english', 'Basic English Grammar', 'Fill in the blank: The data ____ been analysed thoroughly.', ['have', 'has', 'is', 'was'], 0,
                'In formal and technical writing "data" is treated as a plural noun.'),
            Q('english', 'Basic English Grammar', 'Choose the correct sentence:', ['He has been living here for ten years.', 'He is living here for ten years.', 'He lives here for ten years.', 'He live here since ten years.'], 0,
                'A duration continuing to the present needs the present perfect continuous with "for".'),
            Q('english', 'Basic English Grammar', 'Identify the part of speech of "quickly" in "She ran quickly."', ['Adverb', 'Adjective', 'Noun', 'Verb'], 0,
                'It modifies the verb "ran", which makes it an adverb.'),
            Q('english', 'Basic English Grammar', 'Fill in the blank: Neither of the answers ____ correct.', ['is', 'are', 'were', 'have been'], 0,
                '"Neither" is singular and takes a singular verb.'),
            Q('english', 'Reading Comprehension', 'Read the passage: "Version control did not become standard practice because developers grew more disciplined. It spread because merging changes by hand became impossible once teams passed a certain size. Tooling followed necessity, not virtue." <br><br>According to the passage, version control spread because:', ['Manual merging stopped scaling with team size', 'Developers became more disciplined', 'Managers mandated it', 'It was cheaper than the alternatives'], 0,
                'The passage attributes adoption to the impossibility of hand-merging in larger teams.'),
            Q('english', 'Reading Comprehension', 'From the same passage, "Tooling followed necessity, not virtue" means:', ['Tools were adopted out of practical need rather than good intentions', 'Tools made developers virtuous', 'Virtue is more important than necessity', 'Tools were unnecessary'], 0,
                'The sentence contrasts practical compulsion with moral improvement.'),
            Q('english', 'Reading Comprehension', 'The passage is primarily:', ['Explaining a cause', 'Telling a story', 'Issuing a warning', 'Making a request'], 0,
                'It sets out why a practice spread, which is causal explanation.'),
            Q('english', 'Sentence Correction & Technical Writing', 'Identify the error: "Each of the modules were tested separately."', ['were should be was', 'modules should be module', 'tested should be testing', 'No error'], 0,
                '"Each" is singular, so the verb must be "was".'),
            Q('english', 'Sentence Correction & Technical Writing', 'Choose the clearest technical sentence:', ['The server restarts automatically after a crash.', 'A restart of the server is performed automatically subsequent to a crash event.', 'Automatic restarting of the server occurs post-crash.', 'After a crash, an automatic server restart is what happens.'], 0,
                'Technical writing favours a plain active construction with the fewest words.'),
            Q('english', 'Sentence Correction & Technical Writing', 'Identify the error: "The report was more clearer than the previous one."', ['more clearer should be clearer', 'was should be were', 'previous should be previously', 'No error'], 0,
                'A double comparative is incorrect — use either "clearer" or "more clear", not both.')
        ]
    });
})();
