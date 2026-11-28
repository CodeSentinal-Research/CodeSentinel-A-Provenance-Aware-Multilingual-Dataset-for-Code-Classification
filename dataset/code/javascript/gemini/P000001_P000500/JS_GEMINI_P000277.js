const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        const set = new Set();
        let left = 0, maxLen = 0;
        // Expand window to the right
        for (let right = 0; right < s.length; right++) {
            // Shrink window from the left while duplicate exists
            while (set.has(s[right])) set.delete(s[left++]);
            set.add(s[right]);
            maxLen = Math.max(maxLen, right - left + 1);
        }
        console.log(maxLen);
    }
}
main();