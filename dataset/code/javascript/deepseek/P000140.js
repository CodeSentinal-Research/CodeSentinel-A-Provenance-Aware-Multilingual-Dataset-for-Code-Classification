function unionOfArrays() {
    const input = process.argv[2];
    const arr1 = input.split(' ').map(Number);
    const arr2 = input.split(' ').slice(3).map(Number);

    const set1 = new Set(arr1);
    const set2 = new Set(arr2);

    const unionSet = new Set([...set1, ...set2]);

    return Array.from(unionSet).sort((a, b) => a - b);
}

console.log(unionOfArrays());
This code takes as input a line of numbers, separated by spaces, and processes the two arrays separately. It creates sets from the two arrays, and then finds the union of these sets. It then sorts the union in ascending order and logs it to the console.