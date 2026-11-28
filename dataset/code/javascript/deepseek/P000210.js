// Read the size of three arrays
const [size1, size2, size3] = readline().split(" ").map(Number);

// Read the arrays
const arr1 = readline().split(" ").map(Number);
const arr2 = readline().split(" ").map(Number);
const arr3 = readline().split(" ").map(Number);

// Find common elements
const commonElements = findCommonElements(arr1, arr2, arr3, size1, size2, size3);

// Function to find common elements
function findCommonElements(arr1, arr2, arr3, size1, size2, size3) {
    let i = 0, j = 0, k = 0;
    const result = [];
    while(i < size1 && j < size2 && k < size3){
        if(arr1[i] === arr2[j] && arr2[j] === arr3[k]){
            result.push(arr1[i]);
            i++;
            j++;
            k++;
        } else if(arr1[i] < arr2[j] || arr1[i] < arr3[k] || arr2[j] < arr3[k]){
            if(arr1[i] < arr2[j] && arr1[i] < arr3[k]){
                i++;
            } else if(arr2[j] < arr3[k] && arr2[j] < arr1[i]){
                j++;
            } else {
                k++;
            }
        } else {
            if(arr2[j] < arr3[k] && arr2[j] < arr1[i]){
                j++;
            } else if(arr3[k] < arr1[i] && arr3[k] < arr2[j]){
                k++;
            } else {
                i++;
            }
        }
    }
    return result;
}
This solution uses three pointers (i, j, k) to traverse the three sorted arrays. The common elements are pushed into the result array only if they are in a specific order. For example, if arr1[i] === arr2[j] && arr2[j] === arr3[k], then arr1[i] is a common element. If not, the pointer is moved according to its value to find the next common element.