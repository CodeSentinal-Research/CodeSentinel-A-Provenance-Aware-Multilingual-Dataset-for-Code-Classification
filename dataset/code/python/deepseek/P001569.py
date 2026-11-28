def maxSubArraySum(A):
    max_sum = current_sum = A[0]
    for num in A[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    return max_sum

def main():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    print(maxSubArraySum(A))

if __name__ == "__main__":
    main()