Here is a simple python program that computes Euler's Totient Function for given N.

def euler_totient(N):
    result = N
    p = 2
    while(p * p <= N):
        if(N % p == 0):
            while(N % p == 0):
                N //= p
            result -= result // p
        p += 1
    if(N > 1):
        result -= result // N
    return result

while True:
    try:
        N = int(input("Enter a positive integer N (1 <= N <= 10^12): "))
        if 1 <= N <= 10**12:
            print("The value of φ(N) is:", euler_totient(N))
            break
        else:
            print("Invalid input, please enter a positive integer N (1 <= N <= 10^12).")
    except ValueError:
        print("Invalid input, please enter a positive integer N (1 <= N <= 10^12).")

This program uses the mathematical concept that for any given integer N, Euler's Totient Function φ(N) is equal to N if N is a prime number. But if N is a composite number, then φ(N) is the product of all prime factors of N. The program computes the φ(N) iteratively by dividing N by prime factors starting from 2. The while loop continues until the square of the prime factor is less than or equal to N, and the prime factor is not divisible further in N.