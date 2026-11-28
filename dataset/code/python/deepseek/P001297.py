def max_sum_after_swap():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))

    def get_max_sum(arr1, arr2):
        max1, max2, pos1, pos2 = float('-inf'), float('-inf'), -1, -1
        for i in range(n):
            if arr1[i] > max1:
                max1 = arr1[i]
                pos1 = i
            if arr2[i] > max2:
                max2 = arr2[i]
                pos2 = i
        return max1 + max2, pos1, pos2

    return get_max_sum(a, b)

print(max_sum_after_swap())