const fs = require('fs');

function simplifyPath(path) {
    const parts = path.split('/');
    const stack = [];
    for (const p of parts) {
        if (p === '' || p === '.') continue;
        if (p === '..') {
            if (stack.length > 0) stack.pop();
        } else {
            stack.push(p);
        }
    }
    return '/' + stack.join('/');
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        console.log(simplifyPath(input[0]));
    }
}

main();