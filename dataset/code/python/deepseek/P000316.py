Here is the Python code:

def are_isomorphic(s, t):
    if len(s) != len(t):
        return False
    
    map_s_t = {}
    map_t_s = {}
    
    for i in range(len(s)):
        if s[i] not in map_s_t and t[i] not in map_t_s:
            map_s_t[s[i]] = t[i]
            map_t_s[t[i]] = s[i]
        elif map_s_t.get(s[i]) != t[i] or map_t_s.get(t[i]) != s[i]:
            return False
    return True

def main():
    s = input()
    t = input()
    print('Yes' if are_isomorphic(s, t) else 'No')

if __name__ == "__main__":
    main()

In this code, we create two dictionaries (`map_s_t` and `map_t_s`) to map each character from string `s` to a character in string `t` and vice versa. We iterate through each character in `s` and `t`, checking if the current characters are already mapped to the same character in the correct mapping. If not, we return `False` as the strings are not isomorphic. If we iterate through the entire string and the dictionaries do not contain any conflicts, we return `True`.