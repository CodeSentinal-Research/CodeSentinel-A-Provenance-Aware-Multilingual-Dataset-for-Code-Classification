let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let arr = input.split('\n')[1].split(' ').map(Number);

function longestMountain(arr) {
  let maxLen = 0;
  for(let i = 1; i < arr.length - 1; i++) {
    if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
      let left = i;
      while(left > 0 && arr[left] > arr[left-1]) {
        left--;
      }
      let right = i;
      while(right < arr.length - 1 && arr[right] > arr[right+1]) {
        right++;
      }
      maxLen = Math.max(maxLen, right - left + 1);
    }
  }
  return maxLen;
}

console.log(longestMountain(arr));