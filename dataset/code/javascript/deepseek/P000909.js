function binomialCoefficient(n, r) {
    if (n < 0 || r < 0 || n < r) {
        return "Invalid input";
    }
    let result = 1;
    for (let i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}