Sure, here is the Python code:

def reverse_number(n):
    reverse = 0
    while n > 0:
        remainder = n % 10
        reverse = (reverse * 10) + remainder
        n = n // 10
    return reverse

n = int(input("Enter a number: "))
print("Reversed number: ", reverse_number(n))
This code first gets an input from the user, then calls the `reverse_number` function with the input. This function uses a while loop to extract the last digit of the number, appends it to the reversed number and then removes the last digit from the original number. This loop continues until all digits of the original number are processed. The reversed number is then returned.