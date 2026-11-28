const fs = require('fs');

function main() {
    try {
        const input = fs.readFileSync(0, 'utf-8').trim();
        if (!input) return;
        const tokens = input.split(/\s+/);
        if (tokens.length < 2) return;
        
        try {
            const a = BigInt(tokens[0]);
            const b = BigInt(tokens[1]);
            console.log((a * b).toString());
        } catch (err) {
            // Fallback to standard Number if BigInt is not supported or parsing fails
            const a = Number(tokens[0]);
            const b = Number(tokens[1]);
            console.log(a * b);
        }
    } catch (e) {
        // Handle any unexpected I/O errors
    }
}

main();