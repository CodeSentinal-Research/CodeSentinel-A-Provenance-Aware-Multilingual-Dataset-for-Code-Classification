import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0]
        m = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total = 0
        for i in range(len(s)):
            if i + 1 < len(s) and m[s[i]] < m[s[i+1]]:
                total -= m[s[i]]
            else:
                total += m[s[i]]
        print(total)
if __name__ == '__main__':
    main()