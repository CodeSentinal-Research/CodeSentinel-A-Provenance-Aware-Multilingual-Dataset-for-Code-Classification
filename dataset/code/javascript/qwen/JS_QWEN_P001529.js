const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        function atMostK(distinctK) {
            let count = 0;
            let map = {};
            let left = 0;
            for (let right = 0; right < n; right++) {
                map[nums[right]] = (map[nums[right]] || 0) + 1;
                while (Object.keys(map).length > distinctK) {
                    map[nums[left]]--;
                    if (map[nums[left]] === 0) delete map[nums[left]];
                    left++;
                }
                count += (right - left + 1);
            }
            return count;
        }
        
        console.log(atMostK(k) - atMostK(k - 1));
        rl.close();
    }
});
