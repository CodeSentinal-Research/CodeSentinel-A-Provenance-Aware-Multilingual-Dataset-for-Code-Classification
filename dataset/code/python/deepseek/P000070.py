def check_valid_triangle(a, b, c):
    if a == 0 or b == 0 or c == 0:
        return 'Invalid'

    if a > (b + c) or b > (a + c) or c > (a + b):
        return 'Invalid'

    return 'Valid'

while True:
    try:
        a, b, c = map(int, input("Enter three positive numbers (a, b, c): ").split())
        print(check_valid_triangle(a, b, c))
    except ValueError:
        print("Invalid input. Please enter three positive numbers (a, b, c).")