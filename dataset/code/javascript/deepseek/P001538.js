let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter string S1: ', (S1) => {
    rl.question('Enter string S2: ', (S2) => {
        if (S1.length > S2.length) {
            console.log('NO');
            rl.close();
            return;
        }

        let map = new Map();
        for (let i = 0; i < S1.length; i++) {
            map.set(S1[i], (map.get(S1[i]) || 0) + 1);
        }

        for (let i = 0; i < S2.length - S1.length + 1; i++) {
            let subMap = new Map();
            for (let j = 0; j < S1.length; j++) {
                subMap.set(S2[i + j], (subMap.get(S2[i + j]) || 0) + 1);
            }

            if (map.size === subMap.size) {
                let keysAreEqual = true;
                for (let [key, value] of subMap) {
                    if (map.get(key) !== value) {
                        keysAreEqual = false;
                        break;
                    }
                }

                if (keysAreEqual) {
                    console.log('YES');
                    rl.close();
                    return;
                }
            }
        }

        console.log('NO');
        rl.close();
        return;
    });
});