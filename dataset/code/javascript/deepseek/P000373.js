Here is the JavaScript code for your problem. It uses a simple for loop to find the product with the provided product code.

function searchProduct(productRecords, productCode) {
    for(let i = 0; i < productRecords.length; i++) {
        if(productRecords[i].productCode === productCode) {
            return productRecords[i];
        }
    }
    return "Product Not Found";
}

In this code, the `searchProduct` function takes two parameters: an array of product records and the product code to search for. The function iterates over the product records, comparing each product's product code with the provided product code. If a match is found, the function returns the matching product. If no match is found after iterating through all product records, the function returns the string "Product Not Found".

Note: The product code and details are assumed to be objects with properties productCode and details. In your actual code, the properties might be named differently. Also, the product code is case-sensitive. If you want to make it case-insensitive, convert both productCode and productCode in the comparison to the same case before comparison.