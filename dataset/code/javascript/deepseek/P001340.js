Here is the JavaScript code to solve the Fair Distribution of Cookies problem.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter number of bags and children: ', (nk) => {
    const [N, K] = nk.split(' ').map(num => parseInt(num));

    if (!(1 <= N && N <= 8) || !(1 <= K && K <= N)) {
        rl.close();
        return;
    }

    rl.question('Enter number of cookies in each bag: ', (cookieInput) => {
        const cookies = cookieInput.split(' ').map(num => parseInt(num));

        const unfairness = cookies.sort((a, b) => b - a).slice(0, K).reduce((a, b) => a + b, 0);

        console.log(unfairness);

        rl.close();
    });
});

In this code, we first ask for the number of bags and children. If the input is invalid, we close the readline interface. If the input is valid, we ask for the number of cookies in each bag. We sort the cookies in descending order and take the first `K` cookies to minimize the unfairness.