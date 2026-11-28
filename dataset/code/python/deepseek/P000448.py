def find_square_root(n):
    start = 0
    end = n

    while start <= end:
        mid = (start + end) // 2

        if mid * mid == n:
            return mid
        elif mid * mid < n:
            start = mid + 1
        else:
            end = mid - 1

    return end

def main():
    n = int(input("Enter a non-negative integer: "))

    if n < 0:
        print("Invalid input! Please enter a non-negative integer.")
    else:
        print("The square root of", n, "is", find_square_root(n))

if __name__ == "__main__":
    main()