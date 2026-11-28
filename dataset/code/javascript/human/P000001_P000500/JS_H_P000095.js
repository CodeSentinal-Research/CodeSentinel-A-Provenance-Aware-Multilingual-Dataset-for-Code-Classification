// 1. HCF/GCD.

// Description: The Highest Common Factor (HCF) or Greatest Common Divisor
// (GCD) of two numbers is the largest number that divides both numbers
// without leaving a remainder.

// Example:
// 7 Input: a = 12, b = 1,
// 7 Output: '
// 7 Explanation: Factors of 12: {1,2,3,4,6,12}, Factors of 18: {1,2,3,6,9,18}.
// Common factors: {1,2,3,6}. The highest is 6.

// Hint: Use the Euclidean algorithm: GCD(a, b) = GCD(b, a % b).

// function findGCD(a, b) {
//   if (a === 0) {
//     return b;
//   }
//   return findGCD(b % a, a);
// }

// let a = 35;
// let b = 15;
// let g = findGCD(a, b);
// console.log(g);

// 2. Harshad Number

// Description: A number is a Harshad number if it is divisible by the sum of its
// digits.

// Example\
// P Input: 1+
// P Output: Harshad Numbea
// P Explanation: Sum of digits (1 + 8) = 9, and 18 is divisible by 9.

// Hint: Extract digits using modulo (%) and integer division (//).

// let num = Number(prompt("Enter a number to check harshad Number or not"));
// let n = num;
// let sum = 0;
// while (num >= 1) {
//   let rem = num % 10;
//   sum = sum + rem;
//   num = Math.floor(num / 10);
// }

// if (n % sum === 0) {
//   console.log(`yes ${n} is Harshad Number`);
// } else {
//   console.log(`No ${n} is not a Harshad Number`);
// }

// 3. Perfect Square

// Description: A number is a perfect square if it is the square of an integer.

// Example\
// P Input: 2X
// P Output: Perfect SquarN
// P Explanation: 5 × 5 = 25.

// Hint: Use sqrt(N), check if it’s an integer.

// let num = Number(prompt("Enter a number for check perfect sqaure or not"));

// function perfectSqrt(n) {
//   if (n <= 0 || typeof n !== "number") {
//     return false;
//   } else {
//     const sqrt = Math.sqrt(n);
//     return Number.isInteger(sqrt);
//   }
// }

// const p = perfectSqrt(num);
// console.log(`${num} is perfect square ${p}`);

// 4. Abundant Number

// Description: A number is abundant if the sum of its proper divisors is greater
// than the number itself.

// Example\
// P Input: 12
// P Output: Abundant Numbea
// P Explanation: Proper divisors: 1, 2, 3, 4, 6 → Sum = 16 (greater than 12).

// Hint: Use a loop to find proper divisors

// let num = Number(
//   prompt("enter a number to check it is abundant number or not")
// );
// let sum = 0;
// for (let i = 1; i <= num / 2; i++) {
//   if (num % i === 0) {
//     sum = sum + i;
//   }
// }

// if (sum > num) {
//   console.log(`yes ${num} is a Abundant Number`);
// } else {
//   console.log(`no ${num} is not a Abundant Number`);
// }

// 5. Find the Sum of Even Digits in a Number

// Description: Find the sum of all even digits in a given number.

// Example5
// i Input: 2382
// i Output: 14

// Hint: Extract digits using % 10, check if even (digit % 2 == 0), add to sum.

// let num = Number(prompt("Enter a number for sum of even digits"));
// const n = num;
// let sum = 0;
// while (num > 0) {
//   let rem = num % 10;
//   if (rem % 2 === 0) {
//     sum = sum + rem;
//   }
//   num = Math.floor(num / 10);
// }

// console.log(`sum of ${n} is ${sum}`);

// 6. Calculate Area using Switch Statement

// Description: Find the area of a circle, rectangle, or triangle using switch.

// Example(
// & Input: Choice = Circle, Radius = M
// & Output: Area = 78.5

// Hint: Use switch with case statements.

// let choice = prompt(
//   "Choose Area of selected figure: Cirle, Triangle, Rectangle"
// );

// switch (choice) {
//   case "Circle":
//     let r = Number(prompt("Enter radius"));
//     let Area = Math.PI * r * r;
//     console.log(`Area of circle ${Area}`);
//     break;
//   case "Triangle":
//     let base = Number(prompt("Enter base"));
//     let height = Number(prompt("Enter height"));
//     let TriArea = (1 / 2) * base * height;
//     console.log(`Area of Triangle ${TriArea}`);
//     break;
//   case "Rectangle":
//     let l = Number(prompt("Enter length"));
//     let b = Number(prompt("Enter breadth"));
//     let RecArea = l * b;
//     console.log(`Area of Rectangle ${RecArea}`);
//     break;
//   default:
//     console.log("Invalid choice");
// }

// 7. Neon Number

// Description: A number where the sum of digits of its square equals the
// number itself.

// Example(
// & Input: 9
// & Output: Neon Numbe;
// & Explanation: 9² = 81, sum of digits = 9.

// Hint: Find square, sum digits, compare.

// let num = Number(prompt("Enter digits to check neon number or not"));
// let sum = 0;
// let sq = num * num;

// while (sq > 0) {
//   let rem = sq % 10;
//   sum = sum + rem;
//   sq = Math.floor(sq / 10);
// }

// if (num === sum) {
//   console.log("yes it is neon number");
// } else {
//   console.log("no it is not a neon number");
// }

// 8. Number of Days in a Month

// Description: Find the number of days in a given month and year (to handle leap
// years).

// Example:
// Input: Month = 2, Year = 2024
// Output: 29

// Hint: Use conditions
// 31 Days: Jan, Mar, May, Jul, Aug, Oct, Dec$
// 30 Days: Apr, Jun, Sep, Nov$
// February: 28 or 29 (check for leap year using year % 4 == 0 but not year %
// 100 != 0 unless year % 400 == 0).

// let month = prompt(
//   "Enter month name for days: Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec"
// );
// let year = Number(
//   prompt("Enter year for checking leap year feburary month days:")
// );

// if (
//   month === "Jan" ||
//   month === "Mar" ||
//   month === "May" ||
//   month === "Jul" ||
//   month === "Aug" ||
//   month === "Oct" ||
//   month === "Dec"
// ) {
//   console.log(`${month}, have 31 days`);
// } else if (
//   month === "Apr" ||
//   month === "Jun" ||
//   month === "Sep" ||
//   month === "Nov"
// ) {
//   console.log(`${month}, have 30 days`);
// } else if (month === "Feb") {
//   if ((year % 4 === 0 && year % 100 !== 0) || year % 400 === 0) {
//     console.log(`${month}, have 29 days`);
//   } else {
//     console.log(`${month}, have 28 days`);
//   }
// }

// 9. Fibonacci Series using Loop

// Description: Print Fibonacci series up to N terms using a loop.

// Example/
// b Input: N = 5
// b Output: 0, 1, 1, 2, 3, 5

// Hint: Use a loop and store previous two numbers.

// let num = Number(prompt("enter a number of terms:"));
// let n1 = 0;
// let n2 = 1;
// let next;

// console.log("Fibonacci series:");

// for (let i = 0; i <= num; i++) {
//   console.log(n1);
//   next = n1 + n2;
//   n1 = n2;
//   n2 = next;
// }

// 10. Find LCM of Two Numbers

// Description: Find the Least Common Multiple (LCM) of two numbers.

// Example5
// i Input: a = 12, b = 1S
// i Output: 60

// Hint: LCM can be found using the formula: LCM(a, b) = (a × b) / GCD(a, b).

// function findGCD(a, b) {
//   if (a === 0) {
//     return b;
//   }
//   return findGCD(b % a, a);
// }

// let a = 12;
// let b = 15;
// let g = findGCD(a, b);
// let l = Math.abs((a * b) / g);
// console.log(`LCM of (${a}, ${b}) is ${l}`);

// 11.. Find the Largest Digit in a Number
// Description: Find the largest digit in a given number.

// Example5
// i Input: 5482.
// i Output: 9

// Hint: Extract digits using modulo (% 10) and compare.

// let num = Number(prompt("enter a number to check largest number in it...."));
// let maxdigit = 0;

// function printLargestnum(n) {
//   n = Math.abs(n);
//   while (n > 0) {
//     let digit = n % 10;
//     maxdigit = Math.max(maxdigit, digit);
//     n = Math.floor(n / 10);
//   }
//   return maxdigit;
// }

// let max = printLargestnum(num);
// console.log(`Largest number in ${num} is ${max}`);