Here is the JavaScript code that fulfills the problem requirements:

let N = parseInt(readline());
let arr = readline().split(' ').map(Number).sort((a, b) => a - b);

let isMissing = (num) => {
    for(let i = 0; i < arr.length; i++) {
        if (arr[i] == num) return false;
    }
    return true;
}

let missingNum = 0;
for(let i = 0; i <= N; i++) {
    if(isMissing(i)) {
        missingNum = i;
        break;
    }
}

console.log(missingNum);

In the above code, readline() function is used to get user input. map() function is used to convert the input into an array. sort() function is used to sort the array. The isMissing function checks if a number is missing in the array. Finally, we loop from 0 to N (inclusive) and check if each number is missing using isMissing function. If we find a missing number, we break the loop and print it out.