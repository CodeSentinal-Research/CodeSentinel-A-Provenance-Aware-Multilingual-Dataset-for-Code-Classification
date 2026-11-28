const fs = require('fs');

function main() {
    try {
        const input = fs.readFileSync(0, 'utf-8').trim();
        if (!input) return;
        
        const tokens = input.split(/\s+/);
        if (tokens.length >= 2) {
            const num1Str = tokens[0];
            const num2Str = tokens[1];
            
            // Use BigInt to handle arbitrarily large integers safely
            try {
                const a = BigInt(num1Str);
                const b = BigInt(num2Str);
                console.log((a + b).toString());
            } catch (e) {
                // Fallback to standard Number if BigInt parsing fails (e.g., if floats are provided)
                const a = Number(num1Str);
                const b = Number(num2Str);
                if (!isNaN(a) && !isNaN(b)) {
                    console.log(a + b);
                }
            }
        }
    } catch (err) {
        // Handle potential I/O errors gracefully
    }
}

main();