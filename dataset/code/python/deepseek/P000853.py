Sure, here is a simple Python code snippet that does exactly what you've described:

def toggle_kth_bit(n, k):
    return n ^ (1 << k)

def main():
    n = int(input("Enter an integer: "))
    k = int(input("Enter an integer for K: "))
    print("Modified Integer: ", toggle_kth_bit(n, k))

if __name__ == "__main__":
    main()

This code first takes an integer N as input, and then an integer K as input. It then performs a XOR operation with a number that is one shifted left by K bits. The reason for this is that, in binary representation, the K-th bit is the rightmost bit of the 32-bit binary representation of the number. By performing an XOR operation with this shifted number, we can effectively toggle the K-th bit.

The main function just handles input and calls the toggle_kth_bit function, and then prints the result.