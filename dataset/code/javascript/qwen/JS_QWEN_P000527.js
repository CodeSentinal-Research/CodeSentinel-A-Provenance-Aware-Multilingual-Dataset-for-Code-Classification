const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    function evalExpr(i) {
        let args = [];
        while(i<s.length && s[i]!==')') {
            if(s[i]==='!') {
                i++;
                let [val, ni] = evalExpr(i+1);
                args.push(!val);
                i=ni;
            } else if(s[i]==='&' || s[i]==='|') {
                let op = s[i];
                i+=2; // skip op(
                let subArgs = [];
                while(s[i]!==')') {
                    if(s[i]>='a') {
                        subArgs.push(s[i]==='t');
                        i++;
                    } else {
                        let [val, ni] = evalExpr(i);
                        subArgs.push(val);
                        i=ni;
                    }
                    if(s[i]===',') i++;
                }
                i++; // skip )
                if(op==='&') args.push(subArgs.every(x=>x));
                else args.push(subArgs.some(x=>x));
            } else if(s[i]==='t' || s[i]==='f') {
                args.push(s[i]==='t');
                i++;
            } else {
                i++;
            }
        }
        return [args[0], i+1];
    }
    console.log(evalExpr(0)[0] ? "true" : "false");
    rl.close();
});
