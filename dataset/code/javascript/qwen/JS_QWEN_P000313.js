const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let i=0, seenDot=false, seenE=false, seenDigit=false;
    while(i<s.length && s[i]===' ') i++;
    if(i<s.length && (s[i]==='+'||s[i]==='-')) i++;
    while(i<s.length) {
        if(s[i]>='0' && s[i]<='9') seenDigit=true;
        else if(s[i]==='.') { if(seenDot || seenE) { console.log("Invalid"); rl.close(); return; } seenDot=true; }
        else if(s[i]==='e' || s[i]==='E') { if(seenE || !seenDigit) { console.log("Invalid"); rl.close(); return; } seenE=true; seenDigit=false; i++; if(i<s.length && (s[i]==='+'||s[i]==='-')) i++; continue; }
        else break;
        i++;
    }
    while(i<s.length && s[i]===' ') i++;
    console.log(i===s.length && seenDigit ? "Valid" : "Invalid");
    rl.close();
});
