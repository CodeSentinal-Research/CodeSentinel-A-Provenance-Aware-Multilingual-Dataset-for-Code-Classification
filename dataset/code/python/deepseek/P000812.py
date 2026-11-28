Here is the Python code for the problem:

def isPerfectSquare(num: int) -> bool:
    left, right = 0, num
    while left <= right:
        mid = (left + right) // 2
        square = mid * mid
        if square == num:
            return True
        elif square < num:
            left = mid + 1
        else:
            right = mid - 1
    return False

def main():
    num = int(input("Enter a number: "))
    if isPerfectSquare(num):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()

In this code, we are using a binary search algorithm to find the square root of the input number. If the square of mid is less than the input number, then the square of mid (i.e., the square of mid + 1) will be greater than the input number. Otherwise, the square of mid will be less than the input number. We keep doing this until the left pointer is less than or equal to the right pointer. If the number cannot be divided evenly by mid, then the number is not a perfect square and we return False. If the number can be divided evenly by mid, then mid itself is the square root of the number and we return True.