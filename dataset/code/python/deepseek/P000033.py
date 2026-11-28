def solve(n):
    sum = 0
    for i in range(1, n + 1):
        if i % 2 == 0:
            sum += i
    return sum

def main():
    n = int(input("Enter a positive integer: "))
    if 1 <= n <= 10000:
        print(solve(n))
    else:
        print("Invalid input, please enter a positive integer between 1 and 10000.")

if __name__ == "__main__":
    main()