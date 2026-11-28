const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const [s, n, m] = input.split(/\s+/).map(Number);
    
    if(m > n) { console.log(-1); rl.close(); return; }
    
    let days = Math.ceil(s / m);
    let totalDays = days + Math.floor((days-1) * (m-n) / (n-m)); // Simplified logic for survival
    
    // Correct logic:
    // We need s food. We can buy max n per day. We eat m per day.
    // If m > n, impossible unless we have enough stock.
    // Actually, standard problem: Buy on some days, eat every day.
    // Max stock we can hold? Usually unlimited or limited. Assuming unlimited.
    // We need to buy enough to last S days.
    // Total needed = S * M.
    // Max buy per day = N.
    // Min days to buy = ceil(S*M / N).
    // But we can only buy on days we are alive.
    // This is a classic greedy/math problem.
    
    if (m > n && s > 1) { 
         // If we consume more than we can buy, we starve eventually unless S is small
         // Actually if M > N, we lose N-M each day we buy.
         // We can only survive if we buy enough in advance.
    }
    
    // Standard solution for "Survival on Island":
    if (m > n) {
        if (s <= n) console.log(1);
        else console.log(-1);
    } else {
        let totalFood = s * m;
        let daysToBuy = Math.ceil(totalFood / n);
        console.log(daysToBuy);
    }
    rl.close();
});
