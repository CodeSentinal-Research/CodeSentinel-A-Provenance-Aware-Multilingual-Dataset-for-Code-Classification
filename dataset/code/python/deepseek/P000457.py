Here is the Python code for the given problem:

def find_smallest_divisor(N, threshold, numbers):
    numbers.sort()
    left, right = 1, sum(numbers)
    while left <= right:
        mid = (left + right) // 2
        if sum(number // mid for number in numbers) <= threshold:
            right = mid - 1
        else:
            left = mid + 1
    return left

N, threshold = map(int, input().split())
numbers = list(map(int, input().split()))
print(find_smallest_divisor(N, threshold, numbers))

This program works by binary searching for the smallest divisor. It starts with a left limit of 1 and a right limit equal to the sum of all numbers. In each iteration of the binary search, it calculates the midpoint. If the sum of the division of each number by the midpoint is less than or equal to the threshold, it adjusts the right limit to mid - 1. Otherwise, it adjusts the left limit to mid + 1. This process continues until the left limit exceeds the right limit, which is the smallest divisor that satisfies the condition.