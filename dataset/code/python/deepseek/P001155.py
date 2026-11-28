def burst_balloons(n, p):
    r = [0] * (n + 2)
    e = [0] * (n + 2)
    r[0] = p[0]
    r[n+1] = p[n-1]
    for i in range(1, n):
        r[i] = max(r[i-1] + p[i-1]*p[i]*p[i+1], r[i-2] + p[i-1]*p[i]*p[n+1])
        e[i] = max(e[i-1] + p[i-1]*p[i]*p[i+1], e[i-2] + p[i-1]*p[i]*p[n+1])
    return max(max(r), e[n-1])

def main():
    n = int(input().strip())
    p = list(map(int, input().strip().split()))
    print(burst_balloons(n, p))

if __name__ == '__main__':
    main()