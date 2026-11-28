# problem title : Check Harshad Number
# A Harshad number is divisible by the sum of its decimal digits.
n = int(input())
digit_sum = sum(map(int, str(n)))
print("Harshad" if n % digit_sum == 0 else "Not Harshad")
