def atoi(s):
    if not s:
        return 0

    sign = 1
    i = 0
    res = 0

    while s[i] == ' ':
        i += 1

    if s[i] == '-':
        sign = -1
        i += 1

    while i < len(s) and s[i].isdigit():
        res = res * 10 + int(s[i])
        i += 1

    return sign * res