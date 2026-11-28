Here is the Python code with input handling and main function:

def tribonacci(n):
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        a, b, c = 0, 1, 1
        for _ in range(3, n + 1):
            a, b, c = b, c, a + b + c
        return c

def main():
    n = int(input("Enter the value of n: "))
    print(f"The {n}th Tribonacci number is {tribonacci(n)}")

if __name__ == "__main__":
    main()

You can run the program and input a number to get the Tribonacci number for that number.