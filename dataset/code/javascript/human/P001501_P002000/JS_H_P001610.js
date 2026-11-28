// Product except self

function productExceptSelf(arr) {
    const result = [];

    for (let i = 0; i < arr.length; i++) {
        result.push(
            arr.reduce((acc, cur, index) => {
                if (index !== i) {
                    acc *= cur;
                }
                return acc;
            }, 1)
        );
    }

    return result;
}


function productExceptSelf(arr) {
    const productArr = [];

    for (let i = 0; i < arr.length; i++) {
        let product = 1;

        for (let j = 0; j < arr.length; j++) {
            if (i !== j) {
                product *= arr[j];
            }
        }

        productArr.push(product);
    }

    return productArr;
}

console.log(productExceptSelf([2,4,6]));
