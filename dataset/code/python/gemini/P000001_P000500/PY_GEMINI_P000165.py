import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        n = int(lines[0])
        arr = [int(x) for x in lines[1:n+1]]
        max_prod = min_prod = ans = arr[0]
        for x in arr[1:]:
            if x < 0:
                max_prod, min_prod = min_prod, max_prod
            max_prod = max(x, max_prod * x)
            min_prod = min(x, min_prod * x)
            ans = max(ans, max_prod)
        print(ans)
if __name__ == '__main__':
    main()