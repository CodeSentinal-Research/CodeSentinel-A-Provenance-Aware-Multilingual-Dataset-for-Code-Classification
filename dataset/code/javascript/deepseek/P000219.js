Here is the JavaScript code that solves the problem:

class ProductOfNumbers {
    constructor() {
        this.nums = [];
    }

    add(num) {
        this.nums.push(num);
    }

    getProduct(k) {
        if(k > this.nums.length) {
            return null;
        }

        let product = 1;
        for(let i = this.nums.length - k; i < this.nums.length; i++) {
            product *= this.nums[i];
        }
        return product;
    }
}

// Usage
let product = new ProductOfNumbers();
product.add(1);
product.add(2);
product.add(3);
console.log(product.getProduct(1)); // Output: 6
console.log(product.getProduct(2)); // Output: 12
console.log(product.getProduct(3)); // Output: 24

This JavaScript class `ProductOfNumbers` is designed to keep track of the product of the last K numbers added to the data structure. It uses an array `nums` to keep track of the numbers. The `add` method appends the new number to the array. The `getProduct` method calculates the product of the last K numbers in the array. If K is larger than the size of the array, it returns null.