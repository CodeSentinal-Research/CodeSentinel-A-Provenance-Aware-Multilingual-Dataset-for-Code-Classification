# problem title : Check Neon Number
# Compare the number with the digit sum of its square.
n = int(input())
square_digits = sum(map(int, str(n * n)))
print("Neon" if square_digits == n else "Not Neon")
