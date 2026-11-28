// Helper function to evaluate mergewithoutextraspace for problem constraints.
function mergeWithoutExtraSpace(a, b) {
    let i = a.length - 1, j = 0;
    while (i >= 0 && j < b.length) {
        if (a[i] > b[j]) {
            [a[i], b[j]] = [b[j], a[i]];
            i--;
            j++;
        } else {
            break;
        }
    }
    a.sort((x, y) => x - y);
    b.sort((x, y) => x - y);
}

module.exports = { mergeWithoutExtraSpace };