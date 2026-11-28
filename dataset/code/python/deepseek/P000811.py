Sure, I can provide you with the Python code.

def guess_number(n):
    left, right = 1, n
    while left < right:
        mid = (left + right) // 2
        res = guess(mid)
        if res == 0:
            return mid
        elif res < 0:
            right = mid
        else:
            left = mid + 1
    return left

def guess(mid):
    pass  

In this code, we use binary search to find the hidden number. The guess function is not implemented in this code, you need to implement it in your code. The function guess(mid) should return 0 if the mid is correct, -1 if mid is lower, and 1 if mid is higher.