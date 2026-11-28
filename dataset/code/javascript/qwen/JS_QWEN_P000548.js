const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const r = parseInt(lines[0]);
        let routes = [];
        for(let i=1; i<=r; i++) routes.push(lines[i].split(/\s+/).map(Number));
        const [source, target] = lines[r+1].split(/\s+/).map(Number);
        if(source===target) { console.log(0); rl.close(); return; }
        let stopToRoute = {};
        for(let i=0; i<r; i++) {
            for(let stop of routes[i]) {
                if(!stopToRoute[stop]) stopToRoute[stop]=[];
                stopToRoute[stop].push(i);
            }
        }
        let q = [[source, 0]];
        let visitedStops = new Set([source]);
        let visitedRoutes = new Set();
        while(q.length) {
            let [stop, buses] = q.shift();
            if(stop===target) { console.log(buses); rl.close(); return; }
            if(stopToRoute[stop]) {
                for(let routeIdx of stopToRoute[stop]) {
                    if(!visitedRoutes.has(routeIdx)) {
                        visitedRoutes.add(routeIdx);
                        for(let nextStop of routes[routeIdx]) {
                            if(!visitedStops.has(nextStop)) {
                                visitedStops.add(nextStop);
                                q.push([nextStop, buses+1]);
                            }
                        }
                    }
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
