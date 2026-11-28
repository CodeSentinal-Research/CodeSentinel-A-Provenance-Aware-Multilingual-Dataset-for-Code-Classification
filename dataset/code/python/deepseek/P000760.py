def generate_numbers(n):
    for i in range(1, 10):
        number = int(f'{i}{i}{i}{i}{i}{i}{i}{i}{i}')
        yield number

def generate_all_increasing_numbers(n):
    if n == 1:
        print(1)
    else:
        first_number = 1
        for i in range(1, 10):
            first_number = 10 * first_number + 1
        yield from generate_numbers(n)
        for number in generate_all_increasing_numbers(n - 1):
            yield number - first_number + first_number

def main():
    n = int(input("Enter a number: "))
    for number in generate_all_increasing_numbers(n):
        print(number)

if __name__ == "__main__":
    main()
This code generates all N-digit numbers in increasing order. It generates all numbers of one digit first and then subtracts the first number from each generated number to get the remaining numbers. This is done for the remaining digits. The `generate_numbers` function generates all N-digit numbers and the `generate_all_increasing_numbers` function uses the `generate_numbers` function to generate all the numbers.

In the main function, it reads the number of digits and prints all N-digit numbers.