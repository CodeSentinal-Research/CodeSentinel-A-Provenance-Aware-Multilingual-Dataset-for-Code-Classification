def job_sequencing(N, arr):
    max_profit = [0 for _ in range(N+1)]
    deadline = [0 for _ in range(N+1)]

    max_profit[0] = 0
    deadline[0] = 0

    for i in range(1, N+1):
        max_profit[i] = max(max_profit[i-1], arr[i-1])
        deadline[i] = i

    if deadline[N] <= N:
        return max_profit[N]

    return 0

def main():
    N = int(input().strip())

    arr = []
    for i in range(N):
        deadline, profit = map(int, input().strip().split())
        arr.append((profit, deadline))

    arr.sort(key=lambda x: (-x[0], x[1]))

    print(job_sequencing(N, arr))

if __name__ == "__main__":
    main()