def min_max_pair_sum(N, arr):
    arr.sort()
    min_sum = arr[0] + arr[1]
    return min_sum

def main():
    N = int(input().strip())
    arr = [int(i) for i in input().strip().split()]
    print(min_max_pair_sum(N, arr))

main()