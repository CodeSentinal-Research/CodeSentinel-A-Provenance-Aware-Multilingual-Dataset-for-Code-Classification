const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const r = parseInt(tokens[0], 10);
        let idx = 1;
        const routes = [];
        const stopToRoutes = new Map();
        for (let i = 0; i < r; i++) {
            const k = parseInt(tokens[idx++], 10);
            const route = tokens.slice(idx, idx + k).map(Number);
            idx += k;
            routes.push(route);
            for (const stop of route) {
                if (!stopToRoutes.has(stop)) stopToRoutes.set(stop, []);
                stopToRoutes.get(stop).push(i);
            }
        }
        const source = parseInt(tokens[idx], 10);
        const target = parseInt(tokens[idx+1], 10);
        if (source === target) { console.log(0); return; }
        const q = [[source, 0]];
        const visStops = new Set([source]);
        const visRoutes = new Array(r).fill(false);
        let ans = -1;
        while (q.length > 0) {
            const [stop, buses] = q.shift();
            for (const bus of (stopToRoutes.get(stop) || [])) {
                if (!visRoutes[bus]) {
                    visRoutes[bus] = true;
                    for (const nxt of routes[bus]) {
                        if (nxt === target) { ans = buses + 1; break; }
                        if (!visStops.has(nxt)) {
                            visStops.add(nxt);
                            q.push([nxt, buses + 1]);
                        }
                    }
                }
                if (ans !== -1) break;
            }
            if (ans !== -1) break;
        }
        console.log(ans);
    }
}
main();