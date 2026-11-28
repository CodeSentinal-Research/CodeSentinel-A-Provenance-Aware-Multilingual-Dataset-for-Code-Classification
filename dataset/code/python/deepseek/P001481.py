def minBoats(n, limit, weights):
    boats = 0
    weights.sort()
    i = 0
    j = n - 1
    while i <= j:
        if i == j or (weights[j] <= limit and i < j):
            j -= 1
            boats += 1
        else:
            i += 1
            boats += 1
    return boats

def main():
    n = int(input().strip())
    limit = int(input().strip())
    weights = list(map(int, input().strip().split()))
    print(minBoats(n, limit, weights))

main()