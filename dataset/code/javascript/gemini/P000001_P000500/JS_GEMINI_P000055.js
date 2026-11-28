function main() {
    const arr = [];
    for (let i = 90; i >= 65; i--) arr.push(String.fromCharCode(i));
    console.log(arr.join(' '));
}
main();