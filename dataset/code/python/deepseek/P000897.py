Here is a Python solution for the problem:

def lcm(a, b):
    def gcd(a, b):
        if b == 0:
            return a
        return gcd(b, a % b)

    return a * b // gcd(a, b)

def lcm_of_list(lst):
    result = 1
    for num in lst:
        result = lcm(result, num) % (10**9 + 7)
    return result

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(lcm_of_list(nums))

if __name__ == "__main__":
    main()

This code first defines a helper function `gcd(a, b)` to calculate the greatest common divisor (gcd) of `a` and `b`. Then it uses this gcd function to compute the least common multiple (lcm) of `a` and `b`. The lcm of a list of numbers is calculated by iterating over the list, and for each number, it updates the result with the lcm of the current result and the number.

In the main function, it first reads the number `N` and the list of numbers `nums` from the input. It then prints the lcm of the list with the lcm of each pair of consecutive numbers.

Note: In Python, the `%` operator is used for modular arithmetic. It computes the remainder of the division of the first argument by the second. This is handy for determining the result modulo a large number.