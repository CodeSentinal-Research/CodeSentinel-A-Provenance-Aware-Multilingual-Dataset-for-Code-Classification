Here is a JavaScript solution using quick sort algorithm. It is a more efficient sorting algorithm than the standard bubble sort and insertion sort.

function partition(arr, low, high) {
    let pivot = arr[high];
    let i = (low - 1);

    for (let j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }
    [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
    return (i + 1);
}

function quickSort(arr, low, high) {
    if (low < high) {
        let pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

function sortColors(inputs) {
    let N = inputs[0];
    let arr = inputs[1].split(' ').map(Number);

    quickSort(arr, 0, N - 1);

    console.log(arr.join(' '));
}
This function takes an array of inputs and splits the array based on space, then it calls the quick sort function to sort the array. The quick sort function works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.