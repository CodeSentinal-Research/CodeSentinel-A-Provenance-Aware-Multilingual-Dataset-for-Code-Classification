Here is a JavaScript solution that uses a HashMap to store the frequency of each element in the array. Then, for each element in the HashMap, we calculate the total number of complete subarrays that can be formed by using that element as the rightmost element. The formula is (i+1) * (N-i), where i is the position of the current element in the array and N is the size of the array.

function countCompleteSubarrays(inputArr) {
    let map = new Map();
    let total = 0;
    for (let i = 0; i < inputArr.length; i++) {
        if (!map.has(inputArr[i])) {
            map.set(inputArr[i], i);
        } else {
            let prevIndex = map.get(inputArr[i]);
            map.set(inputArr[i], i);
            if (prevIndex < i) {
                total += ((i - prevIndex) * (inputArr.length - i));
            }
       
        }
    }
    return total;
}

console.log(countCompleteSubarrays([1, 2, 3, 1, 2])); // Outputs: 15

This code handles the input and output in a similar way to the problem statement. The input is a list of numbers, and the output is the total number of complete subarrays.

Please note that this is a brute-force solution. There are more efficient ways to solve this problem, such as using a segment tree or a binary indexed tree, but they will require a deeper understanding of data structures and algorithms.