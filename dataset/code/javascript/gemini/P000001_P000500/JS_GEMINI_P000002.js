const fs = require('fs');

function main() {
    try {
        const input = fs.readFileSync(0, 'utf-8').trim();
        if (!input) return;
        const parts = input.split(/\s+/);
        if (parts.length >= 2) {
            try {
                const a = BigInt(parts[0]);
                const b = BigInt(parts[1]);
                console.log((a - b).toString());
            } catch (e) {
                // Fallback to standard Number if BigInt is not applicable (e.g., floating point numbers)
                const a = Number(parts[0]);
                const b = Number(parts[1]);
                if (!isNaN(a) && !isNaN(b)) {
                    console.log(a - b);
                }
            }
        }
    } catch (err) {
        // Handle potential I/O errors gracefully
    }
}

main();