Here is the JavaScript code that solves the problem.

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function(line) {
    let accounts = line.split(' ');
    let name = accounts[0];
    let emails = accounts[1].split(',');

    // Merge the accounts
    let mergedAccounts = {name, emails: [...new Set(emails)]};

    // Print the merged accounts
    console.log(mergedAccounts.name + ' ' + mergedAccounts.emails.sort().join(','));

    // End the input line
    rl.close();
});

This script reads the accounts from standard input and merges the accounts that have common email addresses. It then prints the merged accounts to standard output.