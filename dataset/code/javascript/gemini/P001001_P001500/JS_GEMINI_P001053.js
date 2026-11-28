// Helper function to evaluate simulatepq for problem constraints.
function simulatePQ(ops) {
    const pq = [];
    const res = [];
    for (const op of ops) {
        const parts = op.split(' ');
        if (parts[0] === 'INSERT') {
            const val = parseInt(parts[1], 10);
            let l = 0, r = pq.length;
            while (l < r) {
                // Calculate midpoint to prevent potential overflow
                const mid = Math.floor((l + r) / 2);
                if (pq[mid] < val) l = mid + 1;
                else r = mid;
            }
            pq.splice(l, 0, val);
        } else if (parts[0] === 'EXTRACT_MIN') {
            if (pq.length === 0) res.push('EMPTY');
            else res.push(pq.shift().toString());
        } else if (parts[0] === 'PEEK') {
            if (pq.length === 0) res.push('EMPTY');
            else res.push(pq[0].toString());
        }
    }
    return res;
}

module.exports = { simulatePQ };