def sum_of_squares(N):
    return sum(i**2 for i in range(1, N+1))

N = int(input("Enter a positive integer: "))
if 1 <= N <= 1000:
    print(sum_of_squares(N))
else:
    print("Invalid input. Please enter a positive integer between 1 and 1000.")