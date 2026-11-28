def backspace_compare(s1, s2):
    def build_string(s):
        stack = []
        for c in s:
            if c == '#':
                if stack:
                    stack.pop()
            else:
                stack.append(c)
        return ''.join(stack)

    return build_string(s1) == build_string(s2)


if __name__ == "__main__":
    s1 = input().strip()
    s2 = input().strip()
    print('YES' if backspace_compare(s1, s2) else 'NO')
This Python code first defines a helper function `build_string` that builds a string after processing all backspaces. Then it uses this function to build the two strings `s1` and `s2`, and compares them. The `if __name__ == "__main__"` part is for input handling. In this case, the input is read from the standard input, which is typically the command line or script.