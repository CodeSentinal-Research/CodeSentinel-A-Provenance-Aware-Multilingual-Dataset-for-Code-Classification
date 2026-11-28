const readline = require('readline');

function main() {
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
        terminal: false
    });

    let inputData = '';

    rl.on('line', (line) => {
        inputData += line + ' ';
    });

    rl.on('close', () => {
        const tokens = inputData.trim().split(/\s+/).filter(token => token.length > 0);
        if (tokens.length >= 2) {
            try {
                // Use BigInt to handle arbitrarily large integers safely
                const a = BigInt(tokens[0]);
                const b = BigInt(tokens[1]);
                console.log((a + b).toString());
            } catch (e) {
                // Fallback to standard Number if BigInt parsing fails (e.g., floating point inputs)
                const a = Number(tokens[0]);
                const b = Number(tokens[1]);
                if (!isNaN(a) && !isNaN(b)) {
                    console.log(a + b);
                }
            }
        }
    });
}

main();