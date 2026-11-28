def calculate_sum(n):
    return n * (n + 1) // 2

if __name__ == "__main__":
    n = int(input("Enter a positive integer N: "))
    if 1 <= n <= 10000:
        print(calculate_sum(n))
    else:
        print("Invalid input. Please enter a positive integer between 1 and 10000.")