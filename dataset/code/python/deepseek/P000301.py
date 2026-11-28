Sure, here is a Python solution using backtracking. This solution iterates over all possible 1-3 digit combinations, then recursively tries all possible combinations of the rest.

def restoreIpAddresses(s):
    def backtrack(s, start, parts, res):
        if len(parts) == 4 and start == len(s):
            res.append('.'.join(parts))
            return
        if len(parts) == 4 and start < len(s):
            return
        for end in range(start + 1, min(start + 4, len(s) + 1)):
            part = s[start:end]
            if part.startswith('0') and len(part) > 1:
                continue
            parts.append(part)
            backtrack(s, end, parts, res)
            parts.pop()

    res = []
    backtrack(s, 0, [], res)
    return res

This function will return all possible valid IP addresses. Here's how to use it:

def main():
    s = input("Enter a string: ")
    print(restoreIpAddresses(s))

if __name__ == "__main__":
    main()

Just run the program and provide the input string. It will print all possible valid IP addresses.