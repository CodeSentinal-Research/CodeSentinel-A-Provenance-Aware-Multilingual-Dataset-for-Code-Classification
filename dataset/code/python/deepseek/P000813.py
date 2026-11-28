def square_root(x):
    if x < 0:
        raise ValueError("x must be non-negative")
    if x == 0:
        return 0
    left, right = 0, x
    while left < right:
        mid = (left + right + 1) // 2
        if mid * mid <= x:
            left = mid
        else:
            right = mid - 1
    return left

def main():
    x = int(input("Enter a non-negative integer x: "))
    try:
        print("The integer square root is: ", square_root(x))
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()