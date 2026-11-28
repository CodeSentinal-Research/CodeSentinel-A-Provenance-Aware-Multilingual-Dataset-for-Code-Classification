def is_one_edit_distance(s, t):
    len_s = len(s)
    len_t = len(t)

    if abs(len_s - len_t) > 1:
        return False

    if len_s == len_t:
        return s == t

    for i in range(min(len_s, len_t)):
        if s[i] != t[i]:
            if len_s == len_t:
                return s[i+1:] == t[i+1:]
            else:
                return s[i:] == t[i+1:]

    return True

def main():
    s = input()
    t = input()
    print('Yes' if is_one_edit_distance(s, t) else 'No')

main()
In the code above, we first check if the strings have the same length. If they are not the same length, we then need to check if the strings are 'close' by adding one character to the shorter string. If the strings are the same length, we simply check if they are the same.