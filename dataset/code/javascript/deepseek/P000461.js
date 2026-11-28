Here is the JavaScript code:

function findTransitionPoint() {
  let n = parseInt(readline());
  let arr = readline().split(' ').map(Number);
  let left = 0;
  let right = n - 1;

  while (left < right) {
    let mid = Math.floor((left + right) / 2);
    if (arr[mid] === 1) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  if (arr[left] === 1) {
    console.log(left);
  } else {
    console.log(-1);
  }
}

This function reads the input and finds the transition point in the binary sorted array. The binary search is used to find the transition point, as the array is sorted and binary search can find the middle element in O(log n) time. If the middle element is 1, then the transition point is in the left half of the array, so we update `right` to `mid`. Otherwise, if the middle element is not 1, then the transition point is in the right half of the array, so we update `left` to `mid + 1`. The function finally outputs the index of the transition point or -1 if no 1 exists.