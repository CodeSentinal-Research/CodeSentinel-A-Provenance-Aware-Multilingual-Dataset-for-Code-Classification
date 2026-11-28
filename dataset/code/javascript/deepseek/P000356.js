function searchCharacter(S, C) {
    for(let i = 0; i < S.length; i++) {
        if(S.charAt(i) === C) {
            return i;
        }
    }
    return -1;
}