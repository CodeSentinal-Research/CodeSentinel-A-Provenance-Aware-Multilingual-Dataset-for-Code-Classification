import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        target = int(tokens[1])
        arr = sorted(list(map(int, tokens[2:2+n])))
        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                s = arr[i] + arr[l] + arr[r]
                if s == target:
                    print("Yes")
                    return
                elif s < target:
                    l += 1
                else:
                    r -= 1
        print("No")
if __name__ == '__main__':
    main()