function productOfDigits(n) {
    let product = 1;
    while (n) {
        product *= n % 10;
        n = Math.floor(n / 10);
    }
    return product;
}