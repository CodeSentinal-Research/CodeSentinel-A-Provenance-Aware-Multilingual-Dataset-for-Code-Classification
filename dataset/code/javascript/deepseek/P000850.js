Here is the JavaScript code:

function checkKthBit(N, K) {
  if (K < 0 || K > 31) {
    return "Invalid input";
  }
  
  return (N & (1 << K)) !== 0;
}
In this code, we use the bitwise operator "&" to check the K-th bit. The left shift operator "<<" is used to set the K-th bit. If the K-th bit is set, it will return 1 (1 << K) otherwise it will return 0. By comparing this result with N, we can determine if the K-th bit is set or not.