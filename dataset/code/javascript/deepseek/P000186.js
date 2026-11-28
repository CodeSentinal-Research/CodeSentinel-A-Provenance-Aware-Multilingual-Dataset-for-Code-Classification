function maxPositiveProductSubarray() {
    let input = process.argv[2];
    input = input.split(' ').map(Number);

    function maxPositiveProduct(arr) {
        let maxProduct = arr[0], minProduct = arr[0], result = arr[0];
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] < 0) {
                let temp = maxProduct;
                maxProduct = minProduct;
                minProduct = temp;
            }
            maxProduct = Math.max(arr[i], maxProduct * arr[i]);
            minProduct = Math.min(arr[i], minProduct * arr[i]);
            result = Math.max(result, maxProduct);
        }
        return result;
    }

    console.log(maxPositiveProduct(input));
}

maxPositiveProductSubarray();