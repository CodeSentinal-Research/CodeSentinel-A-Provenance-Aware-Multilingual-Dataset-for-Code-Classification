Here's a Python solution using binary search:

def min_attempts(E, F):
    left, right = 0, F
    while left < right:
        mid = (left + right + 1) // 2
        if mid == 0: 
            return 0
        if (E-1)**(mid-1) < F: 
            left = mid
        else: 
            right = mid - 1
    return left

def main():
    E, F = map(int, input().split())
    print(min_attempts(E, F))

if __name__ == "__main__":
    main()

In this code, we use binary search to find the minimum number of attempts to identify the highest safe floor. In each iteration of the binary search, we check if it's possible to identify the highest safe floor with `(mid-1)` attempts. If it's possible, we update our search range to the left half of the current range (`left = mid`). Otherwise, we update our search range to the right half of the current range (`right = mid - 1`). This process continues until our search range is small enough (`left == right`) and returns the smallest number of attempts.