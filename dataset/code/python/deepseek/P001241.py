def find_start_station(N, gas, cost):
    total_gas = 0
    curr_gas = 0
    start_index = 0
    for i in range(N):
        total_gas += gas[i]
        curr_gas += gas[i]
        if curr_gas < cost[i]:
            if i == N - 1:
                return -1
            start_index = i + 1
            curr_gas = 0
    return start_index if total_gas >= cost[start_index%N] else -1

if __name__ == "__main__":
    N = int(input().strip())
    gas = list(map(int, input().strip().split()))
    cost = list(map(int, input().strip().split()))
    print(find_start_station(N, gas, cost))