Here is the Python code for finding the GCD of an array using the built-in math.gcd() function:

import math

def gcd_array(nums):
    num = nums[0]
    for i in nums[1:]:
        num = math.gcd(num, i)
    return num

def main():
    nums = list(map(int, input().split()))
    print(gcd_array(nums))

if __name__ == "__main__":
    main()

This code first takes an input line, where each line is a space-separated number representing the array. The input is processed by the main() function. The main() function first takes an input and splits it into a list of numbers using the input().split() function. The numbers are then passed to the gcd_array() function, which calculates the GCD of the list.

The gcd_array() function then iterates through each number in the list, calculating the GCD of the current number and the next number using the math.gcd() function. The GCD of all numbers in the list is then returned by the gcd_array() function.

The main() function then prints the result of the gcd_array() function.