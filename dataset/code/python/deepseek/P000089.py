Here is a Python solution for the problem:

def find_sqrt(n):
    start = 0
    end = n
    while start < end:
        mid = (start + end + 1) // 2
        square = mid * mid
        if square <= n:
            start = mid
        else:
            end = mid - 1
    return start

print(find_sqrt(int(input())))

This program uses binary search to find the square root. In each iteration of the loop, it calculates the middle point (mid) and checks if the square of this mid is less than or equal to n. If it is, then the mid is the square root. Otherwise, it continues to the left half of the current range. This process continues until the range is reduced to 1 unit.