Here is the Python code:

def is_divisible_by_9(n):
    return n % 9 == 0

def main():
    n = int(input("Enter an integer: "))
    if is_divisible_by_9(n):
        print(True)
    else:
        print(False)

if __name__ == "__main__":
    main()

In this code, the `is_divisible_by_9` function checks if a number is divisible by 9. The `main` function is the entry point of the program. It takes an integer input from the user and checks if it's divisible by 9.