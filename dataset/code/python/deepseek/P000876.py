Here is the Python code for the given problem:

def find_complement(num):
    return num ^ ((1<<32) - 1)

def main():
    num = int(input("Enter a number: "))
    print("The complement of", num, "is", find_complement(num))

if __name__ == "__main__":
    main()

This code first defines a function `find_complement` which finds the binary complement of a given number. The complement is achieved by bitwise XOR operation with the binary representation of the max integer. The max integer is 1 followed by 31 zeros. Hence, (1<<32) - 1 will give us the max integer which is equivalent to 1 followed by 31 zeroes.

The main function asks for the input number, finds its binary complement and prints the result.

You can run this program by providing an input in the console.

The time complexity of this code is O(1), i.e., constant time, as the number of bits in the integer is fixed.