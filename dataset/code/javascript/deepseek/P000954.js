Here is the JavaScript code using Extended Euclidean Algorithm.

function extendedEuclidean(a, b) {
    if (b == 0) {
        return [a, 1, 0]
    } else {
        let [g, x, y] = extendedEuclidean(b, a % b)
        return [g, y - (a / b) * x, x]
    }
}

console.log(extendedEuclidean(18, 24));
This program will print the values X, Y and GCD when you run it with input 18 and 24.