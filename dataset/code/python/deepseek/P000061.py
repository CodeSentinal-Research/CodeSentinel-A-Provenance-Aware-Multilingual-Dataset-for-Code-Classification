def count_odd_digits(n):
    count = 0
    while n > 0:
        digit = n % 10
        if digit % 2 == 1:
            count += 1
        n = n // 10
    return count

def main():
    n = int(input("Enter a non-negative integer: "))
    while n < 0:
        print("Invalid input. Please enter a non-negative integer.")
        n = int(input("Enter a non-negative integer: "))
    print("The count of odd digits is:", count_odd_digits(n))

if __name__ == "__main__":
    main()