def sum_of_alternate_elements(N, A, Q, L, R):
    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i + 1] = prefix_sum[i] + A[i]

    for _ in range(Q):
        l, r = map(int, input().split())
        print(prefix_sum[r] - prefix_sum[l - 1])


def main():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    Q = int(input().strip())
    L, R = map(int, input().strip().split())
    sum_of_alternate_elements(N, A, Q, L, R)


if __name__ == "__main__":
    main()