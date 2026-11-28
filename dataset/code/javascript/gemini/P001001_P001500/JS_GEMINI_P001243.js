// Helper function to evaluate lemonadechange for problem constraints.
function lemonadeChange(bills) {
    let five = 0, ten = 0;
    for (const b of bills) {
        if (b === 5) {
            five++;
        } else if (b === 10) {
            if (five === 0) return false;
            five--;
            ten++;
        } else {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

module.exports = { lemonadeChange };