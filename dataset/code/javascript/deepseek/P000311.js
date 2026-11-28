function addStrings(num1, num2) {
  let carry = 0;
  let result = '';

  while(num1.length || num2.length || carry){
      let n1 = num1.length ? num1[num1.length - 1] - '0' : 0;
      let n2 = num2.length ? num2[num2.length - 1] - '0' : 0;

      let sum = n1 + n2 + carry;
      carry = Math.floor(sum / 10);
      result = (sum % 10).toString() + result;

      num1 = num1.length ? num1.substring(0, num1.length - 1) : num1;
      num2 = num2.length ? num2.substring(0, num2.length - 1) : num2;
  }

  return result.length ? result : '0';
}