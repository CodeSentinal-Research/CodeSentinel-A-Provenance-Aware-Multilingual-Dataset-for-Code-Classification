function calculate(a, op, b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b !== 0 ? a / b : 'Division by zero';
        default: return 'Invalid';
    }
}

module.exports = { calculate };
