Here is the Python code:

def calculate_sum(n):
    sum = 0
    for i in range(1, n+1):
        sum += (2*i-1)
    return sum

def main():
    n = int(input("Enter a positive integer: "))
    if 1 <= n <= 10000:
        print(calculate_sum(n))
    else:
        print("Input should be between 1 and 10000")

if __name__ == "__main__":
    main()

In this code, the main function gets the input from the user. It first checks if the input is within the given constraints. If it is, it calls the calculate_sum function to calculate the sum. Otherwise, it prints an error message.