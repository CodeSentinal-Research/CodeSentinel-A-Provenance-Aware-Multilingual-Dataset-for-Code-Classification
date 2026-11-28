function removeDuplicateLetters(s) {
    const count = new Array(26).fill(0);
    const index = new Array(26).fill(-1);
    const stack = [];

    for (let i = s.length - 1; i >= 0; --i) {
        const c = s.charAt(i) - 'a'.charAt(0);
        ++count[c];
    }

    for (let i = 0; i < s.length; ++i) {
        const c = s.charAt(i) - 'a'.charAt(0);
        --count[c];
        if (index[c] >= 0) {
            continue;
        }

        while (stack.length > 0 && stack[stack.length - 1] > s.charAt(i)) {
            if (index[stack[stack.length - 1] - 'a'.charAt(0)] < i) {
                break;
            }
            const d = stack.pop() - 'a'.charAt(0);
            index[d] = -1;
        }

        index[c] = i;
        stack.push(s.charAt(i));
    }

    return stack.join('');
}