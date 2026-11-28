Here is the JavaScript code for the problem:

function canWin(state) {
    if (state.includes('--')) {
        return false;
    }

    return state.includes('++');
}

This function takes the state of the string as input and checks if it can be flipped such that the first player can force a win. It does this by checking if the state includes '--' and returns false if it does. Otherwise, it returns true if '++' is found in the state.