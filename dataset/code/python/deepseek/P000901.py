def check_divisibility_by_11(N):
    return N % 11 == 0

N = int(input("Enter a number: "))
print(check_divisibility_by_11(N))