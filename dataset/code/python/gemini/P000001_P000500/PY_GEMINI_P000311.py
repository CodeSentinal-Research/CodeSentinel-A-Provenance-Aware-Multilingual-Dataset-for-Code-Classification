import sys

def add_strings(num1: str, num2: str) -> str:
    i, j, carry = len(num1) - 1, len(num2) - 1, 0
    res = []
    while i >= 0 or j >= 0 or carry:
        total = carry
        if i >= 0:
            total += int(num1[i])
            i -= 1
        if j >= 0:
            total += int(num2[j])
            j -= 1
        res.append(str(total % 10))
        carry = total // 10
    return "".join(reversed(res))

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(add_strings(lines[0], lines[1]))

if __name__ == '__main__':
    main()