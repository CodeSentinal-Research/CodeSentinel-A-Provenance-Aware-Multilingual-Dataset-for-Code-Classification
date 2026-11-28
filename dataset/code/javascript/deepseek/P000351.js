Here is the JavaScript code for the problem:

function findElement(N, arr, X) {
    for(let i = 0; i < N; i++) {
        if(arr[i] === X) {
            console.log("Found");
            return;
        }
    }
    console.log("Not Found");
}

This function accepts three parameters: `N` (the length of the array), `arr` (the array itself), and `X` (the number to search for). It then iterates over the array, and if it finds the number, it prints "Found" and terminates. If it does not find the number, it prints "Not Found".

For proper input handling, you should ensure that `N` is an integer within the constraints (1 ≤ N ≤ 10^5), that `arr` is an array of integers, and that `X` is an integer. You can add checks for these conditions as needed, but for the purpose of this exercise, we've already handled these conditions.