def cut_rod(prices, N):
    r = [0] + [-1*100000]*N
    for i in range(1, N+1):
        q = -100000
        for j in range(1, i+1):
            q = max(q, prices[j] + r[i-j])
        r[i] = q
    return r[N]

def main():
    N = int(input())
    prices = list(map(int, input().split()))
    print(cut_rod(prices, N))

if __name__ == "__main__":
    main()