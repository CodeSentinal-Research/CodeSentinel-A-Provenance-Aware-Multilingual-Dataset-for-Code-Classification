function reduceFraction(numerator, denominator) {
    var gcd = function(a, b) {
        if (!b) {
            return a;
        }
        return gcd(b, a % b);
    };
    var divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    return [numerator, denominator];
}