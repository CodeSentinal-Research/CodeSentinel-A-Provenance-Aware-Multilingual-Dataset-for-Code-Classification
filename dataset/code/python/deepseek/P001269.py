def can_partition(N, K, numbers):
    if N < K or N > N * K:
        return 'NO'

    if sum(numbers) % K != 0:
        return 'NO'

    return 'YES'

def main():
    N, K = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(can_partition(N, K, numbers))

if __name__ == '__main__':
    main()