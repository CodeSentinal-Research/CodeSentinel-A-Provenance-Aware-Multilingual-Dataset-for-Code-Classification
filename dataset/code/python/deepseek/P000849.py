Here is a simple Python code that checks if a number is even or odd using bitwise operators.

def check_even_odd(N):
    if N & 1:
        print('Odd')
    else:
        print('Even')

def main():
    N = int(input("Enter a number: "))
    check_even_odd(N)

if __name__ == "__main__":
    main()
In this code, the bitwise AND operator (&) is used. If the least significant bit (LSB) of N is 1, the result will be 1, and if the LSB is 0, the result will be 0. Therefore, if N & 1 is 1, the number is odd, otherwise it's even.