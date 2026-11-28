function solve() {
    let N = parseInt(readline());
    let arr = readline().split(' ').map(Number).sort((a, b) => a - b);

    // Count frequencies
    let freq = {};
    for (let num of arr) {
        if (freq[num]) {
            freq[num]++;
        } else {
            freq[num] = 1;
        }
    }

    // Sort by frequency then number
    arr.sort((a, b) => {
        if (freq[b] - freq[a] !== 0) {
            return freq[b] - freq[a];
        } else {
            return a - b;
        }
    });

    console.log(arr.join(' '));
}
This JavaScript code reads the number of elements N, followed by the elements themselves, sorted in ascending order. It then counts the frequency of each element in the array, sorts the array by this frequency first and then by the element value itself.