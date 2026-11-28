const fs = require('fs');

// Solves 'Find Remainder' by applying optimal Basic logic.
function solve() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) return;

    const tokens = input.split(/\s+/);
    let idx = 0;

    const numTokens = tokens.length;
    const possibleT = parseInt(tokens[0], 10);

    // If the input starts with T test cases followed by 2*T integers
    if (numTokens === 1 + 2 * possibleT) {
        idx = 1;
    }

    const results = [];
    while (idx + 1 < numTokens) {
        const a = parseInt(tokens[idx], 10);
        const b = parseInt(tokens[idx + 1], 10);
        
        if (b === 0) {
            results.