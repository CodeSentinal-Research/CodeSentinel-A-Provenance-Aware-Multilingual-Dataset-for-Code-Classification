Sure, here is the JavaScript code for the problem:

function checkTarget(N, arr, X) {
  if (N !== arr.length + 1) {
    console.log("Missing");
  } else {
    let found = false;
    for (let i = 1; i <= N; i++) {
      if (arr.includes(i)) {
        found = true;
      } else {
        found = false;
        break;
      }
    }
    if (found) {
      console.log("Present");
    } else {
      console.log("Missing");
    }
  }
}

The code above is a function that checks if the target value is in the array. If the length of the array is not N+1, it prints "Missing". If the array does contain the target, it checks if the target is present in the array. If it is, it prints "Present"; otherwise, it prints "Missing".