Here is the JavaScript code that generates all possible subsets of an array:

function generateSubsets(arr) {
    const subsets = [[]];
    arr.forEach((item, index) => {
        subsets.push(...subsets.map(set => [...set, item]))
    })
    return subsets.sort((a, b) => a.toString().localeCompare(b.toString()))
}

// Test the function
const arr = [1, 2, 3];
console.log(generateSubsets(arr));
This code creates an array `subsets` with the empty set (`[]`), and then for each item in the array, it creates a new subset by adding the current item to each existing subset in the array. This is done by using the `map` function, which applies a function to each item in an array and creates a new array with the results. The `...` operator is used to spread out the subsets from each iteration.

The `sort` function is used to sort the subsets by converting them to strings and comparing them lexicographically. This ensures that the subsets are printed in lexicographical order.

Note: This code does not handle the case where the input array may contain duplicates. To handle this case, you could convert the subsets to a set before returning them, which would ensure that each subset is unique. However, this would not change the ordering of the subsets, since the set data type is ordered.