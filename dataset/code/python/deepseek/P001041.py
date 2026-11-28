def mincosttoHireKworkers(quality, wage, k):
    ratio = [w/q for w, q in zip(wage, quality)]
    ratio.sort()
    min_cost = float('inf')
    for i in range(k):
        min_cost = min(min_cost, ratio[i])
    return min_cost

def main():
    N, K = map(int, input().split())
    quality = list(map(int, input().split()))
    wage = list(map(int, input().split()))
    print(mincosttoHireKworkers(quality, wage, K))

if __name__ == "__main__":
    main()