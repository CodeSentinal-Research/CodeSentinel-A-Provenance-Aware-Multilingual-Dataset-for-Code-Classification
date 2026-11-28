function substringsWithAllChars(S) {
    let aCount = (S.match(/a/g) || []).length;
    let bCount = (S.match(/b/g) || []).length;
    let cCount = (S.match(/c/g) || []).length;

    if (aCount > 0 && bCount > 0 && cCount > 0) {
        return Math.pow(aCount, bCount) % 1000000007;
    } else {
        return 0;
    }
}

function main() {
    const [S] = readline().split('\n');
    console.log(substringsWithAllChars(S));
}

process.stdin.resume();
process.stdin.on('data', main);