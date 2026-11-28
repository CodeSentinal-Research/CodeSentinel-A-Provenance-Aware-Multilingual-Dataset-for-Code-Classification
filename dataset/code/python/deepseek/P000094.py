Here is the Python code:

def check_harshad(n):
    sum_digits = sum(int(digit) for digit in str(n))
    if n % sum_digits == 0:
        print("Harshad")
    else:
        print("Not Harshad")

def main():
    n = int(input("Enter a positive integer: "))
    check_harshad(n)

if __name__ == "__main__":
    main()

This program will ask for a positive integer input from the user and then check if the given number is a Harshad number. If it is, the program will print "Harshad", otherwise it will print "Not Harshad". The function `check_harshad` performs the actual checking, and the main function is the entry point of the program.