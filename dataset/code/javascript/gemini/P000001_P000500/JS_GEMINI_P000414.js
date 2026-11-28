const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const flights = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { flights.push({name: tokens[idx], price: parseFloat(tokens[idx+1]), status: (tokens[idx+2]||'').toLowerCase()}); idx += 3; }
        const budget = parseFloat(tokens[idx]);
        flights.filter(f => f.price <= budget && ["available", "true", "1", "yes"].includes(f.status)).forEach(f => console.log(f.name));
    }
}
main();