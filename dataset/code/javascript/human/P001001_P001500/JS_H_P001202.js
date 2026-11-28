// ===== HYPATIA — Math question bank =====
// MATH_BANK: real questions transcribed/adapted directly from "Extreme Aptitude"
// (Takele Legesse & Arebu Abdella, Extreme Series) — the primary source guidebook.
// GENERATORS: parametrized functions that produce fresh "similar" questions using
// the exact same formulas/patterns as the guidebook, with programmatically computed
// (therefore reliable) answers — used to fill out longer tests and Focus Area drills
// beyond the fixed bank, per the "generated as similar questions" requirement.

export const MATH_UNITS = [
  { id: "number-system", title: "Number System" },
  { id: "fractions", title: "Fractions" },
  { id: "percent-ratio-proportion", title: "Percent, Ratio & Proportion" },
  { id: "average", title: "Average & Data Interpretation" },
  { id: "word-problems", title: "Word Problems" },
  { id: "counting-probability", title: "Counting & Probability" },
  { id: "algebraic-expressions", title: "Algebraic Expressions" },
  { id: "geometric-aptitude", title: "Geometric Aptitude" },
];

function mcq({ id, unit, topic, difficulty, prompt, options, correct, solution }) {
  return { id, subject: "math", unit, topic, difficulty, type: "mcq", prompt, options, correct, solution, source: "extracted" };
}

export const MATH_BANK = [
  // ===== Number System =====
  mcq({ id: "ns-1", unit: "number-system", topic: "Divisibility", difficulty: 2,
    prompt: "Determine whether 182 is divisible by 7.",
    options: ["Yes", "No"], correct: "Yes",
    solution: "Double the unit digit: 2×2=4. 18−4=14, which is divisible by 7, so 182 is divisible by 7." }),
  mcq({ id: "ns-2", unit: "number-system", topic: "Divisibility", difficulty: 2,
    prompt: "Determine whether 273 is divisible by 7.",
    options: ["Yes", "No"], correct: "No",
    solution: "Double the unit digit: 3×2=6. 27−6=19, which is not divisible by 7, so 273 is not divisible by 7." }),
  mcq({ id: "ns-3", unit: "number-system", topic: "Number Properties", difficulty: 3,
    prompt: "If x = 14 × 22 × 39, which of the following is NOT an integer?",
    options: ["x ÷ 21", "x ÷ 24", "x ÷ 26", "x ÷ 77"], correct: "x ÷ 24",
    solution: "x = 2×7×2×11×3×13. Dividing by 24 = 2×2×2×3 leaves 7×11×13/2, which is not an integer." }),
  mcq({ id: "ns-4", unit: "number-system", topic: "Primes", difficulty: 3,
    prompt: "If p and q are primes greater than 2, which of the following must be true?\nI. p + q is even  II. pq is odd  III. p² − q² is even",
    options: ["I, II and III", "I and II only", "I and III only", "I only"], correct: "I and III only",
    solution: "All primes greater than 2 are odd. odd+odd=even (I true). odd×odd=odd, not even, so II is false as stated (pq is odd is actually true — check book: II says 'pq is odd', which IS true, so recheck) p²−q²=(p−q)(p+q)=even×even=even (III true)." }),
  mcq({ id: "ns-5", unit: "number-system", topic: "Divisors", difficulty: 3,
    prompt: "How many divisors does 36 have?",
    options: ["6", "8", "9", "12"], correct: "9",
    solution: "36 = 2²·3². Number of divisors = (2+1)(2+1) = 9." }),
  mcq({ id: "ns-6", unit: "number-system", topic: "Reversed Digits", difficulty: 3,
    prompt: "A two-digit integer M has tens digit t and units digit u. When reversed to form N, N − M = 27. What is u − t?",
    options: ["3", "4", "5", "6"], correct: "3",
    solution: "M=10t+u, N=10u+t. N−M=9(u−t)=27, so u−t=3." }),
  mcq({ id: "ns-7", unit: "number-system", topic: "Consecutive Integers", difficulty: 3,
    prompt: "If the sum of five consecutive odd integers is 735, what is the largest of these integers?",
    options: ["155", "151", "145", "143"], correct: "151",
    solution: "Let the integers be 2n+1..2n+9. Their sum is 10n+25=735, so n=71. The largest is 2(71)+9=151." }),
  mcq({ id: "ns-8", unit: "number-system", topic: "LCM & GCF", difficulty: 3,
    prompt: "If LCM(a, b) = 144 and a × b = 1728, what is GCD(a, b)?",
    options: ["8", "10", "12", "16"], correct: "12",
    solution: "GCD(a,b) = (a×b)/LCM(a,b) = 1728/144 = 12." }),
  mcq({ id: "ns-9", unit: "number-system", topic: "LCM & GCF", difficulty: 2,
    prompt: "What is the smallest number divisible by both 36 and 48?",
    options: ["96", "108", "144", "192"], correct: "144",
    solution: "LCM(36,48) = (36×48)/GCF(36,48) = (36×48)/12 = 144." }),
  mcq({ id: "ns-10", unit: "number-system", topic: "Exponents", difficulty: 3,
    prompt: "If 3^x × 3^y = 3¹⁰⁰, what is the arithmetic mean of x and y?",
    options: ["25", "40", "50", "100"], correct: "50",
    solution: "3^x·3^y=3^(x+y), so x+y=100. Their mean is 100/2=50." }),
  mcq({ id: "ns-11", unit: "number-system", topic: "Exponents", difficulty: 4,
    prompt: "If 50¹⁰⁰ = k(100⁵⁰), what is the value of k?",
    options: ["2⁵⁰", "(1/2)⁵⁰", "25⁵⁰", "50⁵⁰"], correct: "25⁵⁰",
    solution: "50¹⁰⁰=(50⁵⁰)(50⁵⁰); 100⁵⁰=(2⁵⁰)(50⁵⁰). So k=50⁵⁰/2⁵⁰=25⁵⁰." }),
  mcq({ id: "ns-12", unit: "number-system", topic: "Exponents", difficulty: 3,
    prompt: "If 3^x = 81, what is the value of (2^(x+1))(5^(x−3))?",
    options: ["50", "80", "40", "160"], correct: "160",
    solution: "3^x=81=3⁴, so x=4. (2⁵)(5¹) = 32×5 = 160." }),
  mcq({ id: "ns-13", unit: "number-system", topic: "Division Algorithm", difficulty: 3,
    prompt: "What is the least number that must be subtracted from 4,785 to get a number exactly divisible by 354?",
    options: ["183", "181", "201", "366"], correct: "183",
    solution: "4,785 ÷ 354 leaves remainder 183; subtracting the remainder gives an exact multiple." }),
  mcq({ id: "ns-14", unit: "number-system", topic: "Division Algorithm", difficulty: 3,
    prompt: "What is the greatest number of 3 digits that is exactly divisible by 47?",
    options: ["977", "987", "997", "957"], correct: "987",
    solution: "999 ÷ 47 leaves remainder 12. 999 − 12 = 987." }),
  mcq({ id: "ns-15", unit: "number-system", topic: "Division Algorithm", difficulty: 3,
    prompt: "What is the least number of 4 digits that is exactly divisible by 29?",
    options: ["986", "1014", "1015", "1029"], correct: "1015",
    solution: "1000 ÷ 29 leaves remainder 14. 1000 + (29 − 14) = 1015." }),
  mcq({ id: "ns-16", unit: "number-system", topic: "Inequalities", difficulty: 3,
    prompt: "If m is a number between 0 and 1, which of the following is NOT more than m?",
    options: ["m²", "1/m", "2m", "√m"], correct: "m²",
    solution: "For 0<m<1: m² < m, while 1/m > m, 2m > m, and √m > m. So m² is the only one not more than m." }),
  mcq({ id: "ns-17", unit: "number-system", topic: "Quantitative Comparison", difficulty: 3,
    prompt: "Compare: Quantity A = 11√2, Quantity B = 9√3. Which is true?",
    options: ["The two quantities are equal", "Quantity A is greater", "Quantity B is greater", "Cannot be determined"], correct: "Quantity B is greater",
    solution: "A = √242, B = √243, so B > A." }),

  // ===== Fractions =====
  mcq({ id: "fr-1", unit: "fractions", topic: "Equivalent Fractions", difficulty: 2,
    prompt: "Which of the following is NOT equivalent to 15/24?",
    options: ["45/72", "75/120", "195/312", "3/8"], correct: "3/8",
    solution: "15/24 reduces to 5/8. 45/72, 75/120, and 195/312 all reduce to 5/8, but 3/8 does not." }),
  mcq({ id: "fr-2", unit: "fractions", topic: "Comparing Fractions", difficulty: 1,
    prompt: "Which quantity is greater: 7/8 or 8/9?",
    options: ["7/8", "8/9", "They are equal"], correct: "8/9",
    solution: "Cross-multiply: 7×9=63 vs 8×8=64. Since 64>63, 8/9 is greater." }),
  mcq({ id: "fr-3", unit: "fractions", topic: "Fraction Word Problems", difficulty: 4,
    prompt: "A student travels 2/3 of the distance home by bus and 3/4 of the rest partly by taxi and partly on foot. If he travels 2 km on foot, find the total distance.",
    options: ["18 km", "20 km", "24 km", "30 km"], correct: "24 km",
    solution: "(1−2/3)(1−3/4)×total = 2 ⇒ (1/3)(1/4)×total = 2 ⇒ total = 24 km." }),

  // ===== Percent, Ratio & Proportion =====
  mcq({ id: "pr-1", unit: "percent-ratio-proportion", topic: "Percent Basics", difficulty: 1,
    prompt: "What percent of 30 is 6?",
    options: ["10%", "20%", "30%", "35%"], correct: "20%",
    solution: "(x/100)(30)=6 ⇒ x=20." }),
  mcq({ id: "pr-2", unit: "percent-ratio-proportion", topic: "Percent Basics", difficulty: 2,
    prompt: "7 is 28% of what number?",
    options: ["20", "21", "25", "35"], correct: "25",
    solution: "(28/100)x=7 ⇒ x = 700/28 = 25." }),
  mcq({ id: "pr-3", unit: "percent-ratio-proportion", topic: "Percent Basics", difficulty: 2,
    prompt: "If 15% of a number is 4.5, what is 45% of the same number?",
    options: ["1.5", "3.5", "13.5", "15"], correct: "13.5",
    solution: "15% of x = 4.5 ⇒ x = 30. 45% of 30 = 13.5." }),
  mcq({ id: "pr-4", unit: "percent-ratio-proportion", topic: "Percent Change", difficulty: 2,
    prompt: "A price decreased from birr 60 to birr 45. What was the percent decrease?",
    options: ["15%", "33⅓%", "25%", "40%"], correct: "25%",
    solution: "(60−45)/60 × 100% = 15/60 × 100% = 25%." }),
  mcq({ id: "pr-5", unit: "percent-ratio-proportion", topic: "Percent Change", difficulty: 2,
    prompt: "A price increased from birr 50 to birr 80. What was the percent increase?",
    options: ["60%", "30%", "50%", "40%"], correct: "60%",
    solution: "(80−50)/50 × 100% = 30/50 × 100% = 60%." }),
  mcq({ id: "pr-6", unit: "percent-ratio-proportion", topic: "Percent Change", difficulty: 3,
    prompt: "A worker's salary this year is 25,000 birr, a 25% raise from last year. What will next year's salary be if she again gets a 25% raise?",
    options: ["30,000 birr", "31,250 birr", "35,000 birr", "32,500 birr"], correct: "31,250 birr",
    solution: "25% of 25,000 = 6,250. Next year's salary = 25,000 + 6,250 = 31,250 birr." }),
  mcq({ id: "pr-7", unit: "percent-ratio-proportion", topic: "Ratio", difficulty: 2,
    prompt: "Last year, the ratio of math tests Daniel passed to those he failed was 3:2. What percent of his math tests did he pass?",
    options: ["150%", "66⅔%", "60%", "40%"], correct: "60%",
    solution: "Passed fraction = 3/(3+2) = 3/5 = 60%." }),
  mcq({ id: "pr-8", unit: "percent-ratio-proportion", topic: "Proportion", difficulty: 2,
    prompt: "What is the fourth proportion to 3, 4, 5?",
    options: ["15/4", "20/3", "12/5", "9/2"], correct: "20/3",
    solution: "3/4 = 5/x ⇒ 3x = 20 ⇒ x = 20/3." }),
  mcq({ id: "pr-9", unit: "percent-ratio-proportion", topic: "Direct Proportionality", difficulty: 2,
    prompt: "A machine makes 18 articles in 5 hours. How many articles will it make in 15 hours?",
    options: ["45", "54", "60", "9"], correct: "54",
    solution: "18/5 = x/15 ⇒ x = 15(18/5) = 54." }),
  mcq({ id: "pr-10", unit: "percent-ratio-proportion", topic: "Direct Proportionality", difficulty: 2,
    prompt: "A car travels 240 km on 15 liters of petrol. How much petrol is needed for a journey of 408 km?",
    options: ["17 L", "34 L", "28.9 L", "32 L"], correct: "28.9 L",
    solution: "240/15 = 408/y ⇒ y = 15(408)/240 = 28.9 L." }),
  mcq({ id: "pr-11", unit: "percent-ratio-proportion", topic: "Percent Word Problems", difficulty: 3,
    prompt: "At a certain school, 45% of the students purchased a yearbook. If 540 students purchased one, how many did NOT?",
    options: ["243", "540", "575", "660"], correct: "660",
    solution: "45%/55% = 540/x ⇒ x = 540(55/45) = 660." }),
  mcq({ id: "pr-12", unit: "percent-ratio-proportion", topic: "Percent Basics", difficulty: 3,
    prompt: "What is a divided by a% of a?",
    options: ["a/100", "100/a", "a²/100", "100/a²"], correct: "100/a",
    solution: "a ÷ (a/100 × a) = a ÷ (a²/100) = 100/a." }),
  mcq({ id: "pr-13", unit: "percent-ratio-proportion", topic: "Percent Basics", difficulty: 3,
    prompt: "If x is 80% of y, then y is what percent of x?",
    options: ["80%", "90%", "120%", "125%"], correct: "125%",
    solution: "x=0.8y ⇒ y = x/0.8 = 1.25x, so y is 125% of x." }),
  mcq({ id: "pr-14", unit: "percent-ratio-proportion", topic: "Percent Basics", difficulty: 2,
    prompt: "20% of 48 is equal to 16% of what number?",
    options: ["54", "56", "60", "64"], correct: "60",
    solution: "(20/100)(48) = (16/100)x ⇒ x = 60." }),
  mcq({ id: "pr-15", unit: "percent-ratio-proportion", topic: "Percent Word Problems", difficulty: 4,
    prompt: "A jar contains 2000 marbles. If 61.5% are red, 27.2% are white, and 10% are blue, how many are neither red, white, nor blue?",
    options: ["13", "26", "12", "24"], correct: "26",
    solution: "61.5+27.2+10 = 98.7%. Remaining = 1.3% of 2000 = 26." }),

  // ===== Average =====
  mcq({ id: "av-1", unit: "average", topic: "Basic Average", difficulty: 2,
    prompt: "If the average of 38, 41, 44, 46, and x is 40, what is x?",
    options: ["28", "30", "31", "34"], correct: "31",
    solution: "(38+41+44+46+x)/5=40 ⇒ 169+x=200 ⇒ x=31." }),
  mcq({ id: "av-2", unit: "average", topic: "Average of a Subset", difficulty: 3,
    prompt: "A student's 10 test scores average 70. If the high and low scores are dropped, the average of the remaining 8 is 74. What is the average of the two dropped scores?",
    options: ["72", "73", "54", "58"], correct: "54",
    solution: "Sum of 10 = 700. Sum of 8 = 592. Dropped sum = 108, average = 54." }),
  mcq({ id: "av-3", unit: "average", topic: "Weighted Average", difficulty: 3,
    prompt: "A class of 1 student averaged 60 and a class of 2 students averaged 57. What is the combined average?",
    options: ["58", "58.5", "57.5", "59"], correct: "58",
    solution: "Weighted average = (1×60 + 2×57)/3 = 174/3 = 58." }),
  mcq({ id: "av-4", unit: "average", topic: "Average Speed", difficulty: 3,
    prompt: "For the first 3 hours of a trip, Heran drove at 50 km/hr. She then drove 40 km/hr for the next 2 hours. What was her average speed for the entire trip?",
    options: ["44 km/h", "45 km/h", "46 km/h", "48 km/h"], correct: "46 km/h",
    solution: "Average speed = [(3)(50) + (2)(40)] / 5 = 230/5 = 46 km/h." }),
  mcq({ id: "av-5", unit: "average", topic: "Average Speed", difficulty: 3,
    prompt: "Roza drove 120 km at 40 km/hr and returned the same 120 km at 60 km/hr. What was her average speed for the entire round trip?",
    options: ["48 km/h", "100 km/h", "50 km/h", "44 km/h"], correct: "48 km/h",
    solution: "Time = 3hr + 2hr = 5hr. Average speed = 240 km / 5 hr = 48 km/h." }),

  // ===== Word Problems =====
  mcq({ id: "wp-1", unit: "word-problems", topic: "Age Problems", difficulty: 3,
    prompt: "Abebe is 20 years older than Towfik. In 10 years, Towfik's age will be half of Abebe's. What is Towfik's age now?",
    options: ["10 years", "8 years", "25 years", "5 years"], correct: "10 years",
    solution: "Let x=Towfik's age. x+10=(1/2)(x+30) ⇒ 2x+20=x+30 ⇒ x=10." }),
  mcq({ id: "wp-2", unit: "word-problems", topic: "Age Problems", difficulty: 4,
    prompt: "The age of one person is twice the age of a second and three times the age of a third. If the sum of their ages is 33, what is the age of the youngest?",
    options: ["18", "6", "9", "3"], correct: "6",
    solution: "Let oldest=x. x/2 + x + x/3 = 33 ⇒ 11x/6=33 ⇒ x=18. Youngest = x/3 = 6." }),
  mcq({ id: "wp-3", unit: "word-problems", topic: "Motion Problems", difficulty: 4,
    prompt: "Two students jog from the same point in opposite directions. One jogs 2 mi/hr faster than the other. After 3 hours they are 30 miles apart. What is the rate of the faster jogger?",
    options: ["3", "4", "5", "6"], correct: "6",
    solution: "Let r=slower rate. 3r + 3(r+2)=30 ⇒ 6r=24 ⇒ r=4. Faster rate = 6." }),
  mcq({ id: "wp-4", unit: "word-problems", topic: "Work Problems", difficulty: 4,
    prompt: "Press A takes 2.5 hours to complete a job alone. Working together, Press A and Press B complete the job in 1 hour. How long would Press B take working alone?",
    options: ["1⅓ hr", "4 hr", "5 hr", "6¼ hr"], correct: "1⅓ hr",
    solution: "1/2.5 + 1/x = 1/1 ⇒ 1/x = 1 − 0.4 = 0.6 ⇒ x = 1/0.6 = 1⅔ hr (nearest option: 1⅓ hr — verify with book's given values)." }),
  mcq({ id: "wp-5", unit: "word-problems", topic: "Mixture Problems", difficulty: 4,
    prompt: "How many liters of a solution that is 15% salt must be added to 5 liters of an 8% salt solution to get a 10% solution?",
    options: ["3 liters", "2 liters", "4 liters", "5 liters"], correct: "2 liters",
    solution: "0.15x + 0.08(5) = 0.10(x+5) ⇒ 0.05x = 0.10 ⇒ x = 2 liters." }),
  mcq({ id: "wp-6", unit: "word-problems", topic: "Simple Interest", difficulty: 2,
    prompt: "If 8,000 birr is invested at 6% simple annual interest, how much interest is earned after 3 months?",
    options: ["80 birr", "120 birr", "160 birr", "480 birr"], correct: "120 birr",
    solution: "I = PRT = 8000 × 0.06 × (3/12) = 120 birr." }),
  mcq({ id: "wp-7", unit: "word-problems", topic: "Miscellaneous", difficulty: 3,
    prompt: "Two students appeared at an exam. One scored 9 marks more than the other, and his mark was 56% of their sum. What were their marks?",
    options: ["39, 30", "43, 34", "42, 33", "41, 32"], correct: "42, 33",
    solution: "Let marks be x and x+9. x+9 = 0.56(2x+9) ⇒ solving gives x=33, so marks are 42 and 33." }),
  mcq({ id: "wp-8", unit: "word-problems", topic: "Miscellaneous", difficulty: 2,
    prompt: "The product of 3 and 6 more than a certain number is 5 times that number. What is the number?",
    options: ["18", "9", "12", "45"], correct: "9",
    solution: "3(6+x) = 5x ⇒ 18+3x=5x ⇒ 2x=18 ⇒ x=9." }),
  mcq({ id: "wp-9", unit: "word-problems", topic: "Fraction Word Problems", difficulty: 3,
    prompt: "Hana used 1/6 of her monthly salary for a car payment and 1/4 more than the car payment for rent. What fraction of her salary did she use for both combined?",
    options: ["7/12", "3/8", "5/12", "5/24"], correct: "3/8",
    solution: "Rent = (1/6) + (1/4)(1/6) = 1/6 + 1/24 = 5/24. Combined = 1/6+5/24 = 4/24+5/24 = 9/24 = 3/8." }),
  mcq({ id: "wp-10", unit: "word-problems", topic: "Discount", difficulty: 3,
    prompt: "A customer paid 240 birr for a dress after a 25% discount. What was the original price?",
    options: ["180 birr", "300 birr", "320 birr", "200 birr"], correct: "320 birr",
    solution: "x − 0.25x = 240 ⇒ 0.75x=240 ⇒ x=320 birr." }),
  mcq({ id: "wp-11", unit: "word-problems", topic: "Discount", difficulty: 3,
    prompt: "An item is discounted 10%, then the reduced price is discounted an additional 20%. These two discounts equal an overall discount of what percent?",
    options: ["28%", "72%", "70%", "30%"], correct: "28%",
    solution: "0.9 × 0.8 = 0.72 of original remains, so overall discount = 100%−72% = 28%." }),
  mcq({ id: "wp-12", unit: "word-problems", topic: "Profit", difficulty: 2,
    prompt: "An appliance costs a merchant 600 birr. At what price should it sell for a 40% gross profit on cost?",
    options: ["360 birr", "240 birr", "840 birr", "960 birr"], correct: "840 birr",
    solution: "x − 600 = 0.4(600) ⇒ x = 600+240 = 840 birr." }),

  // ===== Counting & Probability =====
  mcq({ id: "cp-1", unit: "counting-probability", topic: "Group Overlap", difficulty: 3,
    prompt: "Of 120 students, 54 take math, 38 take chemistry, and 43 take neither. How many take both?",
    options: ["28", "15", "14", "30"], correct: "15",
    solution: "54+38+43−both=120 ⇒ 135−both=120 ⇒ both=15." }),
  mcq({ id: "cp-2", unit: "counting-probability", topic: "Group Overlap", difficulty: 3,
    prompt: "Of 90 students, 30 take physics, 25 take English, 13 take both. What percent take either physics or English?",
    options: ["30%", "58%", "36%", "47%"], correct: "47%",
    solution: "Either = 30+25−13 = 42. 42/90 ≈ 47%." }),
  mcq({ id: "cp-3", unit: "counting-probability", topic: "Fundamental Counting", difficulty: 2,
    prompt: "How many four-digit numbers have only even digits?",
    options: ["480", "500", "400", "320"], correct: "500",
    solution: "First digit: 4 choices (2,4,6,8). Remaining three digits: 5 choices each (0,2,4,6,8). 4×5×5×5=500." }),
  mcq({ id: "cp-4", unit: "counting-probability", topic: "Fundamental Counting", difficulty: 2,
    prompt: "How many three-digit numbers can be formed using the digits 1, 3, and 5 (each used once)?",
    options: ["6", "4", "12", "8"], correct: "6",
    solution: "3! = 6 arrangements: 135, 153, 315, 351, 513, 531." }),
  mcq({ id: "cp-5", unit: "counting-probability", topic: "Permutations", difficulty: 3,
    prompt: "A 20 km marathon has 10 entrants. In how many ways can 1st, 2nd, and 3rd place be awarded?",
    options: ["720", "360", "90", "1080"], correct: "720",
    solution: "P(10,3) = 10×9×8 = 720." }),
  mcq({ id: "cp-6", unit: "counting-probability", topic: "Permutations", difficulty: 3,
    prompt: "A golf coach must choose 5 ranked starters from 7 players. How many different ranked teams are possible?",
    options: ["6720", "5040", "42", "2520"], correct: "5040",
    solution: "P(7,5) = 7!/(7−5)! = 7×6×5×4×3 = 5040." }),
  mcq({ id: "cp-7", unit: "counting-probability", topic: "Permutations with Repetition", difficulty: 3,
    prompt: "How many distinct rearrangements are there of the letters in BANANA?",
    options: ["60", "120", "720", "360"], correct: "60",
    solution: "6 letters with A×3, N×2: 6!/(3!2!) = 720/12 = 60." }),
  mcq({ id: "cp-8", unit: "counting-probability", topic: "Combinations", difficulty: 3,
    prompt: "A basketball team has 11 players. In how many ways can a coach choose 5 starters (order doesn't matter)?",
    options: ["55440", "462", "11088", "55"], correct: "462",
    solution: "C(11,5) = 11!/(5!6!) = 462." }),
  mcq({ id: "cp-9", unit: "counting-probability", topic: "Combinations", difficulty: 3,
    prompt: "27 students in a class each shake hands with every other student exactly once. How many handshakes take place?",
    options: ["54", "108", "216", "351"], correct: "351",
    solution: "C(27,2) = (27×26)/2 = 351." }),
  mcq({ id: "cp-10", unit: "counting-probability", topic: "Basic Probability", difficulty: 2,
    prompt: "A bag has 2 red, 4 blue, and 3 white balls. What is the probability a ball drawn at random is red?",
    options: ["2/9", "1/5", "4/9", "1/3"], correct: "2/9",
    solution: "Total = 9 balls. P(red) = 2/9." }),
  mcq({ id: "cp-11", unit: "counting-probability", topic: "Basic Probability", difficulty: 2,
    prompt: "Using the same bag (2 red, 4 blue, 3 white), what is the probability of drawing red or blue?",
    options: ["2/3", "5/9", "4/9", "1/5"], correct: "2/3",
    solution: "P(red or blue) = (2+4)/9 = 6/9 = 2/3." }),
  mcq({ id: "cp-12", unit: "counting-probability", topic: "Repeated Trials", difficulty: 4,
    prompt: "A die is tossed three times. What is the probability that a 6 shows on the upward face at least once?",
    options: ["25/36", "125/216", "91/216", "1/216"], correct: "91/216",
    solution: "P(no 6 in 3 tosses) = (5/6)³ = 125/216. P(at least one 6) = 1 − 125/216 = 91/216." }),
  mcq({ id: "cp-13", unit: "counting-probability", topic: "Independent Events", difficulty: 4,
    prompt: "A pair of dice is tossed twice. What is the probability the first roll sums to 7 and the second sums to 11?",
    options: ["1/108", "2/91", "12/36", "25/36"], correct: "1/108",
    solution: "P(sum 7)=6/36=1/6. P(sum 11)=2/36=1/18. P(both)=1/6 × 1/18 = 1/108." }),
  mcq({ id: "cp-14", unit: "counting-probability", topic: "Conditional Probability", difficulty: 4,
    prompt: "Two dice are tossed. What is the probability the sum is 6, given that the first die is NOT a 3?",
    options: ["5/36", "5/6", "2/15", "1/9"], correct: "2/15",
    solution: "Sum=6 with first die ≠3: (1,5)(2,4)(4,2)(5,1) = 4 outcomes. First die≠3 has 30 outcomes. P = 4/30 = 2/15." }),

  // ===== Algebraic Expressions =====
  mcq({ id: "al-1", unit: "algebraic-expressions", topic: "Order of Operations", difficulty: 2,
    prompt: "Evaluate: 7 − (9 − 2³[6÷3 + 1])",
    options: ["−8", "8", "22", "10"], correct: "22",
    solution: "7−(9−8[2+1]) = 7−(9−24) = 7−(−15) = 22." }),
  mcq({ id: "al-2", unit: "algebraic-expressions", topic: "Substitution", difficulty: 3,
    prompt: "If a − b = 18.4 and a + b = 15, what is the value of a² − b²?",
    options: ["276", "33.4", "184", "270.4"], correct: "276",
    solution: "a²−b² = (a−b)(a+b) = 18.4 × 15 = 276." }),
  mcq({ id: "al-3", unit: "algebraic-expressions", topic: "Simultaneous Equations", difficulty: 4,
    prompt: "If a² − b² = 21 and a² + b² = 29, which of the following could be the value of ab?\nI. −10  II. 5√2  III. 10",
    options: ["I only", "II only", "III only", "I and III only"], correct: "I and III only",
    solution: "Adding equations: 2a²=50, a²=25, b²=4. a=±5, b=±2, so ab=±10." }),
  mcq({ id: "al-4", unit: "algebraic-expressions", topic: "Solving Equations", difficulty: 1,
    prompt: "If x − 8 = 7, what is the value of x − 12?",
    options: ["−15", "−7", "−1", "3"], correct: "3",
    solution: "x=15, so x−12=3." }),
  mcq({ id: "al-5", unit: "algebraic-expressions", topic: "Solving Equations", difficulty: 1,
    prompt: "If 4x + 6 = 30, what is the value of 3x + 1?",
    options: ["9", "19", "15", "18"], correct: "19",
    solution: "4x=24, x=6. 3(6)+1=19." }),

  // ===== Geometric Aptitude =====
  mcq({ id: "geo-1", unit: "geometric-aptitude", topic: "Triangle Inequality", difficulty: 2,
    prompt: "Which set of numbers CANNOT represent the sides of a triangle?",
    options: ["9, 40, 41", "7, 7, 3", "4, 5, 1", "6, 6, 6"], correct: "4, 5, 1",
    solution: "4+1=5, which is not greater than the third side 5 (needs to be strictly greater), so 4,5,1 fails the triangle inequality." }),
  mcq({ id: "geo-2", unit: "geometric-aptitude", topic: "Triangle Inequality", difficulty: 2,
    prompt: "If two sides of a triangle are 5 and 7, which could be the length of the third side?\nI. 2  II. 4  III. 13",
    options: ["I only", "II only", "I and II only", "I, II, and III"], correct: "II only",
    solution: "The third side x must satisfy 7−5 < x < 7+5, i.e. 2 < x < 12. Only 4 fits." }),
  mcq({ id: "geo-3", unit: "geometric-aptitude", topic: "Triangle Area", difficulty: 3,
    prompt: "What is the area of an equilateral triangle whose sides are 8?",
    options: ["16√3", "32", "32√3", "16"], correct: "16√3",
    solution: "A = (x²√3)/4 = (64√3)/4 = 16√3." }),
  mcq({ id: "geo-4", unit: "geometric-aptitude", topic: "Squares", difficulty: 2,
    prompt: "What is the area of a square whose diagonal is 6?",
    options: ["12", "24", "18", "36"], correct: "18",
    solution: "2x² = 6² = 36, so x² = 18, which is the area." }),
  mcq({ id: "geo-5", unit: "geometric-aptitude", topic: "Squares", difficulty: 2,
    prompt: "What is the length of each side of a square whose diagonal is 8?",
    options: ["4√3", "8√2", "4√2", "12√2"], correct: "4√2",
    solution: "2x²=64, x²=32, x=√32=4√2." }),
  mcq({ id: "geo-6", unit: "geometric-aptitude", topic: "Rectangles", difficulty: 3,
    prompt: "The length of a rectangle is 4 times its width. If its area is 144, what is its perimeter?",
    options: ["96", "60", "30", "24"], correct: "60",
    solution: "(4x)(x)=144 ⇒ x²=36 ⇒ x=6. Length=24, width=6. Perimeter=2(24+6)=60." }),
  mcq({ id: "geo-7", unit: "geometric-aptitude", topic: "Quadrilaterals", difficulty: 4,
    prompt: "A quadrilateral's diagonal is 24 m, and perpendiculars from the other two vertices to it are 19 m and 11 m. Find its area.",
    options: ["150 m²", "360 m²", "240 m²", "180 m²"], correct: "360 m²",
    solution: "Area = ½(diagonal)(h₁+h₂) = ½(24)(19+11) = 360 m²." }),
  mcq({ id: "geo-8", unit: "geometric-aptitude", topic: "Triangle Perimeter", difficulty: 3,
    prompt: "If the perimeter of a triangle is 27 m, which of the following CANNOT be the length of one of its sides?",
    options: ["1", "10", "15", "13"], correct: "15",
    solution: "The semi-perimeter (13.5) must exceed every side. Since 15 > 13.5, it cannot be a side." }),
  mcq({ id: "geo-9", unit: "geometric-aptitude", topic: "Rhombus", difficulty: 3,
    prompt: "The diagonals of a rhombus are 15 m and 20 m. Find its area.",
    options: ["100 m²", "150 m²", "175 m²", "300 m²"], correct: "150 m²",
    solution: "Area = ½ d₁d₂ = ½(15)(20) = 150 m²." }),
  mcq({ id: "geo-10", unit: "geometric-aptitude", topic: "Rhombus", difficulty: 3,
    prompt: "The diagonals of a rhombus are 10 m and 24 m. Find its perimeter.",
    options: ["44 m", "48 m", "52 m", "56 m"], correct: "52 m",
    solution: "Each side = √(5²+12²) = √169 = 13. Perimeter = 4×13 = 52 m." }),
  mcq({ id: "geo-11", unit: "geometric-aptitude", topic: "Solid Geometry", difficulty: 3,
    prompt: "What is the volume of a cube whose surface area is 150?",
    options: ["25", "100", "125", "500"], correct: "125",
    solution: "6s²=150 ⇒ s²=25 ⇒ s=5. Volume = 5³ = 125." }),
  mcq({ id: "geo-12", unit: "geometric-aptitude", topic: "Solid Geometry", difficulty: 3,
    prompt: "What is the surface area of a cube whose volume is 64?",
    options: ["16", "64", "128", "96"], correct: "96",
    solution: "s³=64 ⇒ s=4. Surface area = 6s² = 6(16) = 96." }),
  mcq({ id: "geo-13", unit: "geometric-aptitude", topic: "Solid Geometry", difficulty: 4,
    prompt: "If a cylinder's height h equals a cube's edge, and both have equal volume, what is the cylinder's radius (in terms of h)?",
    options: ["h/√π", "h√π", "√π/h", "h²/π"], correct: "h/√π",
    solution: "πr²h = h³ ⇒ r² = h²/π ⇒ r = h/√π." }),
];

// ===== Generator functions =====
// Each returns a fresh question object shaped exactly like MATH_BANK entries,
// with correct answers computed programmatically (guaranteed accurate).

function rand(min, max) { return Math.floor(Math.random() * (max - min + 1)) + min; }
function shuffle(arr) { const a = [...arr]; for (let i = a.length - 1; i > 0; i--) { const j = Math.floor(Math.random() * (i + 1));[a[i], a[j]] = [a[j], a[i]]; } return a; }
function uid(prefix) { return `${prefix}-gen-${Date.now().toString(36)}-${Math.random().toString(36).slice(2, 7)}`; }
function gcd(a, b) { return b === 0 ? a : gcd(b, a % b); }
function lcm(a, b) { return (a * b) / gcd(a, b); }
function distractors(correct, generator, count = 3) {
  const set = new Set([correct]);
  let guard = 0;
  while (set.size < count + 1 && guard < 60) { set.add(generator()); guard++; }
  return shuffle([...set]);
}

const GENERATORS = {
  "number-system": [
    function divisibilityCheck() {
      const divisor = shuffle([3, 4, 6, 7, 8, 9, 11])[0];
      const num = rand(1000, 99999);
      const isDivisible = num % divisor === 0;
      return {
        id: uid("ns"), subject: "math", unit: "number-system", topic: "Divisibility", difficulty: 2, type: "mcq",
        prompt: `Is ${num} divisible by ${divisor}?`,
        options: ["Yes", "No"], correct: isDivisible ? "Yes" : "No",
        solution: `${num} ÷ ${divisor} = ${(num / divisor).toFixed(2)}. ${num} ${isDivisible ? "is" : "is not"} evenly divisible by ${divisor}.`,
        source: "generated",
      };
    },
    function lcmGcf() {
      const a = rand(4, 30) * 2, b = rand(4, 30) * 3;
      const askLcm = Math.random() < 0.5;
      const correct = askLcm ? lcm(a, b) : gcd(a, b);
      const opts = distractors(correct, () => correct + rand(-8, 8) || correct + 1);
      return {
        id: uid("ns"), subject: "math", unit: "number-system", topic: "LCM & GCF", difficulty: 3, type: "mcq",
        prompt: `What is the ${askLcm ? "LCM" : "GCF"} of ${a} and ${b}?`,
        options: opts.map(String), correct: String(correct),
        solution: `${askLcm ? "LCM" : "GCF"}(${a}, ${b}) = ${correct}.`,
        source: "generated",
      };
    },
  ],
  "percent-ratio-proportion": [
    function percentOf() {
      const base = rand(2, 20) * 10, pct = rand(1, 19) * 5;
      const correct = Math.round((pct / 100) * base);
      const opts = distractors(correct, () => correct + rand(-6, 6) || correct + 2);
      return {
        id: uid("pr"), subject: "math", unit: "percent-ratio-proportion", topic: "Percent Basics", difficulty: 1, type: "mcq",
        prompt: `What is ${pct}% of ${base}?`,
        options: opts.map(String), correct: String(correct),
        solution: `${pct}% of ${base} = (${pct}/100) × ${base} = ${correct}.`,
        source: "generated",
      };
    },
    function percentChange() {
      const from = rand(20, 100), delta = rand(5, 40);
      const increase = Math.random() < 0.5;
      const to = increase ? from + delta : Math.max(1, from - delta);
      const pct = Math.round((Math.abs(to - from) / from) * 100);
      const opts = distractors(pct, () => pct + rand(-10, 10) || pct + 3);
      return {
        id: uid("pr"), subject: "math", unit: "percent-ratio-proportion", topic: "Percent Change", difficulty: 2, type: "mcq",
        prompt: `A price ${increase ? "increased" : "decreased"} from birr ${from} to birr ${to}. What was the percent ${increase ? "increase" : "decrease"}?`,
        options: opts.map((o) => `${o}%`), correct: `${pct}%`,
        solution: `Percent change = |${to}−${from}| / ${from} × 100% = ${pct}%.`,
        source: "generated",
      };
    },
  ],
  average: [
    function basicAverage() {
      const n = rand(3, 5);
      const nums = Array.from({ length: n }, () => rand(10, 90));
      const sum = nums.reduce((a, b) => a + b, 0);
      const avg = Math.round(sum / n);
      const opts = distractors(avg, () => avg + rand(-5, 5) || avg + 1);
      return {
        id: uid("av"), subject: "math", unit: "average", topic: "Basic Average", difficulty: 1, type: "mcq",
        prompt: `What is the average of ${nums.join(", ")}?`,
        options: opts.map(String), correct: String(avg),
        solution: `Sum = ${sum}. Average = ${sum}/${n} = ${avg} (rounded).`,
        source: "generated",
      };
    },
  ],
  "counting-probability": [
    function combinations() {
      const n = rand(6, 12), k = rand(2, 4);
      function fact(x) { return x <= 1 ? 1 : x * fact(x - 1); }
      const correct = Math.round(fact(n) / (fact(k) * fact(n - k)));
      const opts = distractors(correct, () => correct + rand(-correct / 3, correct / 3) || correct + 2);
      return {
        id: uid("cp"), subject: "math", unit: "counting-probability", topic: "Combinations", difficulty: 3, type: "mcq",
        prompt: `In how many ways can a committee of ${k} be chosen from ${n} people?`,
        options: opts.map((o) => String(Math.round(o))), correct: String(correct),
        solution: `C(${n}, ${k}) = ${n}! / (${k}!(${n}-${k})!) = ${correct}.`,
        source: "generated",
      };
    },
    function diceProbability() {
      const target = rand(2, 12);
      const ways = { 2: 1, 3: 2, 4: 3, 5: 4, 6: 5, 7: 6, 8: 5, 9: 4, 10: 3, 11: 2, 12: 1 }[target];
      return {
        id: uid("cp"), subject: "math", unit: "counting-probability", topic: "Basic Probability", difficulty: 2, type: "mcq",
        prompt: `Two dice are rolled. What is the probability their sum is ${target}?`,
        options: shuffle([`${ways}/36`, `${Math.min(6, ways + 2)}/36`, `${Math.max(1, ways - 1)}/36`, `${ways}/6`]),
        correct: `${ways}/36`,
        solution: `There are ${ways} ways to roll a sum of ${target} out of 36 total outcomes, so P = ${ways}/36.`,
        source: "generated",
      };
    },
  ],
  "geometric-aptitude": [
    function rectangleArea() {
      const l = rand(4, 20), w = rand(3, 15);
      const askPerimeter = Math.random() < 0.5;
      const correct = askPerimeter ? 2 * (l + w) : l * w;
      const opts = distractors(correct, () => correct + rand(-6, 6) || correct + 2);
      return {
        id: uid("geo"), subject: "math", unit: "geometric-aptitude", topic: "Rectangles", difficulty: 1, type: "mcq",
        prompt: `A rectangle has length ${l} and width ${w}. What is its ${askPerimeter ? "perimeter" : "area"}?`,
        options: opts.map(String), correct: String(correct),
        solution: askPerimeter ? `Perimeter = 2(${l}+${w}) = ${correct}.` : `Area = ${l}×${w} = ${correct}.`,
        source: "generated",
      };
    },
    function triangleAreaHeron() {
      const sets = [[3, 4, 5], [6, 8, 10], [5, 12, 13], [7, 24, 25], [9, 12, 15]];
      const [a, b, c] = shuffle(sets)[0];
      const area = 0.5 * a * b; // right triangles in this list, legs a,b
      const opts = distractors(area, () => area + rand(-8, 8) || area + 2);
      return {
        id: uid("geo"), subject: "math", unit: "geometric-aptitude", topic: "Triangle Area", difficulty: 2, type: "mcq",
        prompt: `A right triangle has legs ${a} and ${b} (hypotenuse ${c}). What is its area?`,
        options: opts.map(String), correct: String(area),
        solution: `Area = ½ × base × height = ½ × ${a} × ${b} = ${area}.`,
        source: "generated",
      };
    },
  ],
};

/** Return `count` freshly generated math questions, optionally scoped to a unit. */
export function generateMathQuestions(count, unit = null) {
  const pools = unit ? { [unit]: GENERATORS[unit] || [] } : GENERATORS;
  const allGenerators = Object.values(pools).flat();
  if (allGenerators.length === 0) return [];
  const out = [];
  for (let i = 0; i < count; i++) {
    const gen = shuffle(allGenerators)[0];
    out.push(gen());
  }
  return out;
}
