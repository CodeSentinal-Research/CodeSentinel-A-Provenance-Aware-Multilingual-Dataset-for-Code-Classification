def isPerfectSquare(n):
    left, right = 0, n
    while left <= right:
        mid = (left + right) // 2
        sqr = mid * mid
        if sqr == n:
            return 'Yes'
        elif sqr < n:
            left = mid + 1
        else:
            right = mid - 1
    return 'No'

def main():
    n = int(input())
    print(isPerfectSquare(n))

if __name__ == "__main__":
    main()