function atoi(s) {
    var sign = 1;
    var result = 0;
    var i = 0;

    // Skip whitespace
    while (s[i] == ' ') {
        i++;
    }

    // Check sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Convert digits
    for (; i < s.length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
        } else {
            break;
        }
    }

    return sign * result;
}