Here is the Python code for the given problem:

def count_even_odd_digits(n):
    even_count = 0
    odd_count = 0
    
    for digit in str(n):
        if int(digit) % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
    
    return even_count, odd_count

def main():
    n = int(input("Enter a non-negative integer: "))
    
    while not (0 <= n <= 10**18):
        print("Invalid input. Please enter a non-negative integer less than or equal to 10^18.")
        n = int(input("Enter a non-negative integer: "))
    
    even_count, odd_count = count_even_odd_digits(n)
    
    print(f"The number of even digits: {even_count}")
    print(f"The number of odd digits: {odd_count}")

if __name__ == "__main__":
    main()

In this code, the main function first gets the input from the user. Then, it enters a loop that continues until the user enters a non-negative integer less than or equal to 10^18. The `count_even_odd_digits` function counts the number of even and odd digits in the given integer. The main function then prints the number of even and odd digits.