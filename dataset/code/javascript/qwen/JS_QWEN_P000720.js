const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const num = lines[0];
        const target = parseInt(lines[1]);
        let res = [];
        function addOps(num, target, index, currentVal, lastNum, expression) {
            if (index === num.length) {
                if (currentVal === target) res.push(expression);
                return;
            }
            for (let i = index; i < num.length; i++) {
                if (i > index && num[index] === '0') break;
                let currStr = num.substring(index, i + 1);
                let currNum = parseInt(currStr);
                if (index === 0) {
                    addOps(num, target, i + 1, currNum, currNum, currStr);
                } else {
                    addOps(num, target, i + 1, currentVal + currNum, currNum, expression + "+" + currStr);
                    addOps(num, target, i + 1, currentVal - currNum, -currNum, expression + "-" + currStr);
                    addOps(num, target, i + 1, currentVal - lastNum + lastNum * currNum, lastNum * currNum, expression + "*" + currStr);
                }
            }
        }
        addOps(num, target, 0, 0, 0, "");
        console.log(res.join("\n"));
        rl.close();
    }
});
