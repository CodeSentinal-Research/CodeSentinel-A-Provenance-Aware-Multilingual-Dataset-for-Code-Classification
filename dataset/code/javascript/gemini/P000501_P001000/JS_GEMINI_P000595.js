const fs = require('fs');
function main() {
    const lines = fs.readFileSync(0, 'utf-8').trim().split('\n');
    if (lines.length > 0 && lines[0].trim()) {
        let l1 = lines[0].trim().split(/\s+/).map(Number);
        let l2 = lines.length > 1 ? lines[1].trim().split(/\s+/).map(Number) : [];
        if (l1.length > 0 && l1.length - 1 === l1[0]) l1 = l1.slice(1);
        if (l2.length > 0 && l2.length - 1 === l2[0]) l2 = l2.slice(1);
        let carry = 0, i = 0, j = 0;
        const res = [];
        while (i < l1.length || j < l2.length || carry > 0) {
            const v1 = i < l1.length ? l1[i] : 0;
            const v2 = j < l2.length ? l2[j] : 0;
            const sum = v1 + v2 + carry;
            res.push(sum % 10);
            carry = Math.floor(sum / 10);
            i++; j++;
        }
        console.log(res.join(' '));
    }
}
main();