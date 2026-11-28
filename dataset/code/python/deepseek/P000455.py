Here is the Python code for the given problem:

def find_least_weight_capacity():
    N, D = map(int, input().split())
    weights = list(map(int, input().split()))
    weights.sort()
    l, r = weights[0], sum(weights) // D
    while l < r:
        mid = (l + r) // 2
        if sum(weight // mid for weight in weights) > D:
            l = mid + 1
        else:
            r = mid
    return l

print(find_least_weight_capacity())

This code first reads the number of packages and the number of days from the input. It then reads the weights of the packages from the input. The weights are sorted in ascending order.

The code then uses binary search to find the least weight capacity of the ship. It starts with the weight of the heaviest package and tries to find the midpoint where the total weight of the packages divided by the midpoint is not more than the number of days. If the total weight of the packages divided by the midpoint is more than the number of days, it means that the midpoint is too small and it tries to find the heaviest possible midpoint. If the total weight of the packages divided by the midpoint is less than the number of days, it means that the midpoint is too large and it tries to find the smallest possible midpoint.

Finally, the least weight capacity is returned.