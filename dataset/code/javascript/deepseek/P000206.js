function findMedianSortedArrays(arr1, arr2) {
    var mergedArray = arr1.concat(arr2);
    mergedArray.sort(function(a, b){return a - b});

    var length = mergedArray.length;

    if(length % 2 === 0) {
        return (mergedArray[length / 2 - 1] + mergedArray[length / 2]) / 2;
    } else {
        return mergedArray[Math.floor(length / 2)];
    }
}

// Input:
// Read the two arrays from standard input
var arr1 = JSON.parse(process.argv[2]);
var arr2 = JSON.parse(process.argv[3]);

console.log(findMedianSortedArrays(arr1, arr2));