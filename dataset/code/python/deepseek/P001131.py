def fibonacci(n):
    if n <= 0:
        return "Input should be greater than 0"
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        a = 0
        b = 1
        for i in range(2, n):
            a, b = b, a + b
        return b

n = int(input("Enter a number: "))
print(fibonacci(n))