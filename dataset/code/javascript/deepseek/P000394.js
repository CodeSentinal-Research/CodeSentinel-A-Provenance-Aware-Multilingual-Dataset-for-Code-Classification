Here is the JavaScript code for your problem. This code uses an object as a hashmap to store the product records and allows for a more efficient search by brand name.

function searchProductsByBrand(records, brand) {
  // Initialize an empty array to store the matching products
  let matchingProducts = [];

  // Iterate over each product in the records
  for (let product in records) {
    // If the product's brand matches the brand name passed in, add it to the matching products array
    if (records[product].brand === brand) {
      matchingProducts.push(records[product]);
    }
  }

  // Return the array of matching products
  return matchingProducts;
}

// Example usage:
let records = {
  'product1': {name: 'product1', brand: 'brand1'},
  'product2': {name: 'product2', brand: 'brand1'},
  'product3': {name: 'product3', brand: 'brand2'},
  'product4': {name: 'product4', brand: 'brand3'},
  'product5': {name: 'product5', brand: 'brand1'}
};

console.log(searchProductsByBrand(records, 'brand1'));
// Output: [ { name: 'product1', brand: 'brand1' }, { name: 'product5', brand: 'brand1' } ]

This code defines a function `searchProductsByBrand` which takes in a product records object and a brand name. It then iterates over each product in the records, and if the product's brand matches the given brand name, it adds the product to a matching products array. Finally, it returns the array of matching products.

The `records` object is a mock data for this problem, you can replace it with your actual data.