Here is the JavaScript code for the problem:

let [N, K] = process.argv.slice(2);

N = parseInt(N);
K = parseInt(K);

if (!(1 <= N && N <= 100000) || !(N <= K && K <= 26 * N)) {
  console.log("Invalid input");
  process.exit(1);
}

let result = '';
while (K > 0) {
  if (K < 26 && K > 0) {
    result = String.fromCharCode(97 + K - 1) + result;
    K = 0;
  } else {
    result = 'z' + result;
    K -= 25;
  }
}

console.log(result);

In this code, we first read the input values N and K. Then, we ensure that the input values are within the constraints. Next, we create an empty string for the result.

Then, in a while loop, we subtract 25 from K as long as K is greater than or equal to 26, then add 'a' to the result. If K is less than 26, we subtract it from K and add 'z' to the result. This process is repeated until K is 0.

Finally, we print the result.