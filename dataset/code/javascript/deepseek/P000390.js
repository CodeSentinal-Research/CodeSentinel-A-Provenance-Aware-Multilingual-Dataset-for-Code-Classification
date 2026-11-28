Sure, here's a simple JavaScript function that does what you're asking for:

function searchProducts(products, min, max) {
    if (!Array.isArray(products) || products.length === 0) {
        throw new Error('Invalid input: products must be an array');
    }
    if (typeof min !== 'number' || typeof max !== 'number') {
        throw new Error('Invalid input: minimum and maximum prices must be numbers');
    }
    if (min > max) {
        throw new Error('Invalid input: minimum price must be less than or equal to maximum price');
    }

    return products.filter(product => product.price >= min && product.price <= max);
}

This function uses the `filter` method to create a new array with only the products for which the condition `product.price >= min && product.price <= max` is true.

Please note that this code assumes that the `products` array contains objects with a `price` property. If your data is structured differently, you'll need to adjust the code accordingly.