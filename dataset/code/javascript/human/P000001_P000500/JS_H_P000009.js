// Find Maximum of Two Numbers

function maxOfTwoNums(num1, num2) {
  if (num1 > num2) {
    return num1;
  } else {
    return num2;
  }
}

// using ternary operator
function maxOfTwoNums(num1, num2) {
  return num1 > num2 ? num1 : num2;
}

console.log(maxOfTwoNums(5, 13)); // 13
