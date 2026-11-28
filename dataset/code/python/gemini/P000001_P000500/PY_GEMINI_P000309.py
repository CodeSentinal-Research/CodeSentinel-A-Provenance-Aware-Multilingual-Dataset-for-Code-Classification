import sys

def multiply(num1: str, num2: str) -> str:
    if num1 == "0" or num2 == "0":
        return "0"
    m, n = len(num1), len(num2)
    pos = [0] * (m + n)
    for i in range(m - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            mul = int(num1[i]) * int(num2[j])
            p1, p2 = i + j, i + j + 1
            total = mul + pos[p2]
            pos[p2] = total % 10
            pos[p1] += total // 10
    idx = 0
    while idx < len(pos) and pos[idx] == 0:
        idx += 1
    return "".join(map(str, pos[idx:])) if idx < len(pos) else "0"

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(multiply(lines[0], lines[1]))

if __name__ == '__main__':
    main()