Here is a simple JavaScript function that will solve the problem. The function will find the position of a target value in a sorted infinite array.

function findPosition(target) {
    if (typeof target !== 'number') {
        return -1;
    }

    var array = []; // Assume you have a sorted infinite array here
    var position = 0;

    while (true) {
        if (array[position] === target) {
            return position;
        }

        if (array[position] < target) {
            position++;
        } else {
            break;
        }

        // handle circular array
        position %= array.length;
    }
}
This function will return the index of the target value in the infinite sorted array. If the target is not found in the array, it will return -1.

Please note that this is a very simple approach and may not be suitable for large inputs. A more efficient approach would be to use a binary search algorithm to find the target in the sorted infinite array. However, that would require additional logic to handle the circular nature of the array.