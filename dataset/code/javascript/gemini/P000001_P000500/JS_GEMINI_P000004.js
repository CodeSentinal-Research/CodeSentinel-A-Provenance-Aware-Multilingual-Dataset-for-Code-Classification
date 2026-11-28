const fs = require('fs');

function main() {
    try {
        const input = fs.readFileSync(0, 'utf-8');
        const tokens = input.trim().split(/\s+/);
        if (tokens.length >= 2) {
            const aStr = tokens[0];
            const bStr = tokens[1];
            try {
                const a = BigInt(aStr);
                const b = BigInt(bStr);
                console.log((a / b).toString());
            } catch (e) {
                const a = Number(aStr);
                const b = Number(bStr);
                if (b === 0) {
                    console.log(a / b); // Prints Infinity, -Infinity, or NaN
                } else {
                    const res = Math.trunc