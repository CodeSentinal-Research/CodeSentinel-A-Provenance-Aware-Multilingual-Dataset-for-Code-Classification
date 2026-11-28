function countOfAtoms(formula) {
    const count = new Map();
    const stack = [1];
    let i = 0;

    const add = (a, b) => {
        const cnt1 = count.get(a) || 0;
        const cnt2 = count.get(b) || 0;
        count.set(a, cnt1 + (b || 1));
    };

    const update = () => {
        const cnt = stack[stack.length - 1];
        stack.pop();
        const n = stack.length ? stack[stack.length - 1] : 1;
        for (const [atom, freq] of count.entries())
            count.set(atom, cnt * freq / n);
    };

    const process = (s) => {
        for (let i = 0; i < s.length; i++) {
            if (s[i] === '(') {
                stack.push(1);
            } else if (s[i] === ')') {
                update();
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                let j = i + 1;
                while (j < s.length && s[j] >= '0' && s[j] <= '9')
                    j++;
                add(s[i], parseInt(s.slice(i + 1, j), 10));
                i = j - 1;
            } else {
                stack.push(s[i] - '0' + 1);
            }
        }
    };

    process(formula);

    const result = Array.from(count.entries())
        .sort((a, b) => a[0].localeCompare(b[0]))
        .map(([atom, cnt]) => `${atom}${cnt}`)
        .join('');

    return result;
}
The code works as follows:

- `process` function is responsible for processing the formula. The formula is a string which can contain letters, numbers and parentheses. The letters represent atoms and the numbers represent their multiplicity. The parentheses indicate a nested formula.

- `stack` is a LIFO data structure which is used to track the multiplicity of atoms in a formula.

- `count` is a Map which holds the atom counts in a formula.

- `add` function updates the counts of two atoms by adding their counts.

- `update` function handles the popping of atoms from the stack when a ')' is encountered.

- Finally, the code returns the atom counts in lexicographical order.