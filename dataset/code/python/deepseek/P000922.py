def sum_of_digits(L, R):
    total_sum = 0
    for num in range(L, R + 1):
        total_sum += sum(int(digit) for digit in str(num))
    return total_sum

L = int(input("Enter the lower range: "))
R = int(input("Enter the upper range: "))

print(sum_of_digits(L, R))