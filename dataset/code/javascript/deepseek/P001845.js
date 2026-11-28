Here is a basic implementation of the problem using JavaScript. This code uses a recursive approach to generate all possible BSTs and then filters out the duplicates.

function uniqueBST(sequences) {
    const counts = new Set();
    const cache = {};

    function countBST(seq) {
        if (cache[seq]) return cache[seq];

        if (seq.length === 0) return 1;

        let count = 0;
        for (let i = 0; i < seq.length; i++) {
            const left = seq.slice(0, i);
            const right = seq.slice(i + 1);

            const leftCount = countBST(left);
            const rightCount = countBST(right);

            count += leftCount * rightCount;
        }

        cache[seq] = count;
        return count;
    }

    for (let i = 0; i < sequences.length; i++) {
        counts.add(countBST(sequences[i]));
    }

    return counts.size;
}

This code assumes that the sequences are provided as inputs in an array of arrays. Each inner array represents a sequence of keys. The function `uniqueBST` first initializes a set to store the counts of unique BSTs. The set is used because sets in JavaScript can only contain unique values, so we can easily add the count of a BST to the set and then get the size of the set to get the number of unique BSTs.

The function `countBST` is a recursive function that counts the number of distinct BSTs for a given sequence. It uses a cache to store the counts of already computed sequences to avoid repeated computations. The function iterates over the sequence, for each key, it creates a new sequence that includes the key, and then recursively counts the number of BSTs for the two resulting sequences. The count of a BST is the product of the counts of the two resulting sequences.

Finally, the function iterates over the sequences, calls `countBST` for each sequence, and adds the count to the set of counts.