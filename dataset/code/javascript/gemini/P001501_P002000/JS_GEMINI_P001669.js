// Helper function to evaluate isvalidserialization for problem constraints.
function isValidSerialization(preorder) {
    const nodes = preorder.split(',');
    let slots = 1;

    for (const node of nodes) {
        slots--;
        if (slots < 0) return false;
        if (node !== '#') slots += 2;
    }
    return slots === 0;
}

module.exports = { isValidSerialization };