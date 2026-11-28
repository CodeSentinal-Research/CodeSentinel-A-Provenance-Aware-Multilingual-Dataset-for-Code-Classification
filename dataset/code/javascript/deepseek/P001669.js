function verifyPreorderSerialization(preorder) {
    let tokens = preorder.split(' ');
    let open = 1;

    for(let token of tokens) {
        if (token === '#') {
            if (open === 0) {
                return 'NO';
            }
            open--;
        } else {
            open++;
        }
    }

    return open === 0 ? 'YES' : 'NO';
}

let input = process.argv[2] || "9 3 # 4 # # 5";
console.log(verifyPreorderSerialization(input));