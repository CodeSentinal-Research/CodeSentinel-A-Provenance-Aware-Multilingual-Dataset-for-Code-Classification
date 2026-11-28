Here is the Python code:

def sum_of_digits(n):
    sum = 0
    while(n > 0):
        sum += n % 10
        n = n // 10
    return sum

n = int(input("Enter a non-negative integer: "))
print("Sum of digits: ", sum_of_digits(n))

This program first takes an input number `n`, and then calls the function `sum_of_digits` with `n` as the argument. The function `sum_of_digits` calculates the sum of digits of `n` by repeatedly dividing `n` by 10 (using integer division) and adding the remainder to the sum. This process repeats until `n` becomes 0. The sum of the digits is then printed out.