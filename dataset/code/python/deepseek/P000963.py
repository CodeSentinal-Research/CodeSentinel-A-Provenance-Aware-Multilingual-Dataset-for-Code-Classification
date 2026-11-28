Sure, here is a simple python code to solve this problem.

def is_possible(a, b, n):
    if n % 2 == 0 and a + b == n:
        return True
    else:
        return False

def main():
    a = int(input("Enter the value for A: "))
    b = int(input("Enter the value for B: "))
    n = int(input("Enter the value for N: "))

    if is_possible(a, b, n):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()

This program will prompt the user to enter the values for A, B, and N. Then it will check if exactly N items can be purchased using any non-negative combination of the two package sizes (A and B). If it's possible, it will print "True", otherwise it will print "False".