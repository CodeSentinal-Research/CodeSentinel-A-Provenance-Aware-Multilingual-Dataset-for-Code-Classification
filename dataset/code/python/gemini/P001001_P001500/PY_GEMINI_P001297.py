from typing import List

def maximize_sum_one_swap(arr: List[int]) -> int:
    n = len(arr)
    base_sum = sum(i * arr[i] for i in range(n))
    max_sum = base_sum

    for i in range(n):
        for j in range(i + 1, n):
            # Swap effect
            gain = (j - i) * arr[i] + (i - j) * arr[j]
            max_sum = max(max_sum, base_sum + gain)

    return max_sum

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(maximize_sum_one_swap(arr))