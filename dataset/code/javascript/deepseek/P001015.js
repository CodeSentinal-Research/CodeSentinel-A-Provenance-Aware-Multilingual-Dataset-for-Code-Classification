function topKFrequentElements(arr, k) {
    let count = {};
    let freq = [];

    for (let num of arr) {
        count[num] = (count[num] || 0) + 1;
    }

    for (let num in count) {
        freq.push([num, count[num]]);
    }

    freq.sort((a, b) => b[1] - a[1]);

    let result = [];
    for (let i = 0; i < k; i++) {
        result.push(freq[i][0]);
    }

    return result;
}

This function first counts the frequency of each number in the array using a hashmap (count). Then it creates an array from the hashmap, with each element being an array of two elements. The first element is the number, and the second element is the count. The array is sorted in descending order based on the count. Finally, the top k frequent elements are extracted from the sorted array.