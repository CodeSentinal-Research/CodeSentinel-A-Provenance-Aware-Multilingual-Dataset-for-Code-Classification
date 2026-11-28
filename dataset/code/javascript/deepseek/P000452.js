function findElement(inputArr) {
    let numCounts = {};
    for (let i = 0; i < inputArr.length; i++) {
        if (numCounts[inputArr[i]]) {
            numCounts[inputArr[i]] += 1;
        } else {
            numCounts[inputArr[i]] = 1;
        }
    }
    for (let num in numCounts) {
        if (numCounts[num] === 1) {
            return num;
        }
    }
}
This code works by first counting the occurrence of each number in the input array. It then iterates through the object of counts, and returns the first number to appear only once.