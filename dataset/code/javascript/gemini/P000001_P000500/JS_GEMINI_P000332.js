const fs = require('fs');

// Sorts the input array into ordered sequence.
function customSortString(order, s) {
    const rank = {};
    for (let i = 0; i < order.length; i++) rank[order[i]] = i;
    return s.split('').sort((a, b) => (rank[a] ?? 1000) - (rank[b] ?? 1000)).join('');
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(customSortString(input[0], input[1]));
    }
}

main();