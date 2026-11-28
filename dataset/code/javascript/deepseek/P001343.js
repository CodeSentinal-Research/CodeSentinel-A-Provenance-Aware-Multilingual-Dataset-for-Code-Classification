Here is the JavaScript code:

function generateGray(n) {
  if(n <= 0 || n > 16) {
    console.error('Invalid input. Input should be between 1 and 16.');
    return;
  }

  // Function to convert binary to gray code
  function binaryToGray(binary, n) {
    if (n === 1) return binary;

    return binary + binary[n - 1] === '01' ? '11' : '00';
  }

  let gray = '';
  let binary = '0';

  // Generate n-bit binary numbers
  for (let i = 1; i < n; i++) {
    binary = binaryToGray(binary, i);
    gray = gray + binary;
  }

  return gray;
}

console.log(generateGray(5));
This code firstly validates the input. Then, for each bit from the 2nd bit up to the Nth bit, it calculates the next bit in the Gray code and concatenates it to the Gray code string. The `binaryToGray` function is used to convert a binary number to Gray code. If the next bit is '01' (i.e., the current bit is '0' and the next bit is '1'), the Gray code is '11', otherwise, it's '00'. 

Please note that this is a simple implementation and might not be optimal for large inputs. For large inputs, more efficient algorithms would be needed.