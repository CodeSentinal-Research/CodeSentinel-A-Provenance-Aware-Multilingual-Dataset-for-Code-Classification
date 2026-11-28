def connect_sticks(sticks):
    sticks.sort()

    total_cost = 0

    while len(sticks) > 1:
        total_cost += sticks[0] + sticks[1]
        sticks[0] += sticks[1]
        sticks[1] = sticks[0]
        sticks.sort()

    return total_cost

def main():
    N = int(input().strip())
    sticks = list(map(int, input().strip().split()))
    print(connect_sticks(sticks))

if __name__ == "__main__":
    main()