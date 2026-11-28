Here is the Python code:

def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

And here is the main function that handles the input:

def main():
    n = int(input("Enter a number: "))
    print(fibonacci(n))

if __name__ == "__main__":
    main()

To use this code, just run it and enter a number when prompted. The program will then print the N-th Fibonacci number.