const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the first version: ', (version1) => {
    rl.question('Enter the second version: ', (version2) => {
        const compareVersions = (v1, v2) => {
            const arr1 = v1.split('.');
            const arr2 = v2.split('.');
            for (let i = 0; i < 3; i++) {
                const num1 = parseInt(arr1[i]);
                const num2 = parseInt(arr2[i]);
                if (num1 !== num2) {
                    return num1 > num2 ? 1 : -1;
                }
            }
            return 0;
        };
        console.log(compareVersions(version1, version2));
        rl.close();
    });
});