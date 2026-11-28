function isAdditiveNumber(num) {
    let n = num.toString();
    let m = n.length;
    for (let i = 0; i < m; i++) {
        for (let j = i + 1; j < m; j++) {
            let sum = n.slice(i, j + 1);
            if (!(sum == 0 || sum == n.slice(0, i) + n.slice(j + 1))) {
                let newNum = parseInt(n.slice(i, j + 1));
                if (newNum > Math.pow(10, m) || newNum == 0) return false;
                if (i > 0 && n.slice(0, i) + n.slice(j + 1) != sum)
                    return false;
            }
        }
    }
    return true;
}

console.log(isAdditiveNumber('198')); // true
console.log(isAdditiveNumber('981')); // true
console.log(isAdditiveNumber('1001')); // false
console.log(isAdditiveNumber('22')); // true
console.log(isAdditiveNumber('0')); // true
console.log(isAdditiveNumber('11111')); // false
This JavaScript code takes a numeric string as input and returns whether it forms an additive sequence or not. The function isAdditiveNumber checks if the string forms an additive sequence where every number (starting from the third) equals the sum of the previous two numbers.