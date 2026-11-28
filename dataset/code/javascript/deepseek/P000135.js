function sortColors(arr) {
    let i = 0;
    let j = 0;
    let k = arr.length;

    while (j < k) {
        switch (arr[j]) {
            case 0:
                [arr[i++], arr[j++]] = [arr[j++], arr[i++]];
                break;
            case 1:
                j++;
                break;
            case 2:
                [arr[j], arr[--k]] = [arr[--k], arr[j]];
                break;
        }
    }

    return arr;
}

console.log(sortColors([0, 1, 2, 0, 1, 2, 1, 0, 0, 2, 1, 1, 0])); // [0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2]