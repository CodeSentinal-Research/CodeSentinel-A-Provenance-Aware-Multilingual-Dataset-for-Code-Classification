const fs = require('fs');

/**
 * Swaps two integers and prints them to stdout.
 * Uses ES6 destructuring assignment for idiomatic variable swapping.
 *
 * @param {number|string} a - The first integer.
 * @param {number|string} b - The second integer.
 */
function swapAndPrint(a, b) {
    let numA = typeof a === 'bigint' ? a : Number(a);
    let numB = typeof b === 'bigint' ? b : Number(b);

    // Swap using destructuring assignment
    [numA, numB] = [numB, numA];

    console.log(`${numA} ${numB}`);
}

function main() {
    try {
        const input = fs.readFileSync(0, 'utf-8').trim();
        if (!input) return;

        const tokens = input.split(/\s+/);
        if (tokens.length >= 2) {
            swapAndPrint(tokens[0], tokens[1]);
        }
    } catch (error) {
        console.error('Error reading input:', error.message);
    }
}

if (require.main === module) {
    main();
}

module.exports = { swapAndPrint };