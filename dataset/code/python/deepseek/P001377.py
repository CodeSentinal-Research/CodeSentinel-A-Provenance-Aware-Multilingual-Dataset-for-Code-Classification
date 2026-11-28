Here is the Python code for the problem:

def is_isomorphic(s, t):
    mapping_s_t = {}
    mapping_t_s = {}

    for c_s, c_t in zip(s, t):
        if c_s in mapping_s_t and mapping_s_t[c_s] != c_t:
            return False
        if c_t in mapping_t_s and mapping_t_s[c_t] != c_s:
            return False
        mapping_s_t[c_s] = c_t
        mapping_t_s[c_t] = c_s

    return True

def main():
    s = input().strip()
    t = input().strip()
    print('YES' if is_isomorphic(s, t) else 'NO')

if __name__ == '__main__':
    main()

This program first checks if the two strings are isomorphic. It does this by creating two dictionaries: `mapping_s_t` and `mapping_t_s`, which keep track of the mapping from the first string to the second string and vice versa. It then iterates over the characters of the two strings, checking if the current characters in the strings are already mapped to the same character in the other string. If they are not, the strings are not isomorphic. If they are, the strings are not isomorphic. If they are mapped to the same character, then the characters are already mapped to the same character in the other string, so the strings are isomorphic.