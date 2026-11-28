Here is the Python code:

import math

def is_perfect_square(n):
    sqrt = int(math.sqrt(n))
    return sqrt*sqrt == n

def main():
    n = int(input("Enter a positive integer: "))
    while n <= 0:
        n = int(input("Enter a positive integer: "))

    if is_perfect_square(n):
        print("Perfect Square")
    else:
        print("Not Perfect Square")

if __name__ == "__main__":
    main()
In this code, we first import the math module to use the sqrt function. We then define a function is_perfect_square that checks whether a number is a perfect square. This is done by first finding the square root of the number, and then checking if squaring the integer part of the square root gives us back the original number.

Then in the main function, we handle input from the user. We then call is_perfect_square with the input number. If the result is True, we print "Perfect Square"; otherwise, we print "Not Perfect Square".

Finally, if the script is run as a script, we call the main function.