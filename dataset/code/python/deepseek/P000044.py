def print_numbers(n):
    for i in range(n, 0, -1):
        print(i, end=' ')

while True:
    n = input("Enter a positive integer: ")
    if n.isdigit() and 1 <= int(n) <= 1000:
        print_numbers(int(n))
        break
    else:
        print("Invalid input. Please enter a positive integer between 1 and 1000.")