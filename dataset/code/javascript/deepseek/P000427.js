Sure, here is a simple way to solve this problem using JavaScript. This code assumes that the products are represented as objects with properties "price" and "name". The function findProducts eligibleForFreeShipping will take an array of products and a minimum price as input, and return an array of products that meet the minimum price requirement for free shipping.

function findProductsEligibleForFreeShipping(products, minimumPrice) {
    return products.filter(product => product.price >= minimumPrice);
}

In this function, we use the JavaScript Array.prototype.filter method to create a new array with all products that satisfy the condition defined by the arrow function. This arrow function checks if the price of each product is greater than or equal to the minimum price. If it is, the product is included in the new array. If it's not, the product is filtered out.

This function does not handle the input and does not provide any output, as it's a standalone function.

Here is how you can use this function:

let products = [
    {name: "Product1", price: 10},
    {name: "Product2", price: 20},
    {name: "Product3", price: 30},
    {name: "Product4", price: 40},
    {name: "Product5", price: 50}
];

let eligibleProducts = findProductsEligibleForFreeShipping(products, 20);

console.log(eligibleProducts); // Output: [ { name: 'Product2', price: 20 }, { name: 'Product4', price: 40 } ]

In the above example, we create an array of products and then call the function with this array and a minimum price of 20. The function will return an array of products that meet the minimum price requirement for free shipping.