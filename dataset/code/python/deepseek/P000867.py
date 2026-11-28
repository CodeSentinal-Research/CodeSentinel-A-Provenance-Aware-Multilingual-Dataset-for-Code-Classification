Here is the Python code for the problem:

def hamming_distance(x, y):
    bin_x = bin(x)[2:]
    bin_y = bin(y)[2:]

    max_len = max(len(bin_x), len(bin_y))
    bin_x = bin_x.zfill(max_len)
    bin_y = bin_y.zfill(max_len)

    distance = 0
    for i in range(max_len):
        if bin_x[i] != bin_y[i]:
            distance += 1

    return distance

def main():
    x = int(input("Enter first number: "))
    y = int(input("Enter second number: "))
    print("Hamming distance: ", hamming_distance(x, y))

if __name__ == "__main__":
    main()

In this code, we first convert the numbers to binary and remove the '0b' prefix. Then, we pad the shorter binary representation with leading zeros to make it the same length as the longest binary representation. Then, we calculate the Hamming distance by comparing each bit of the binary representations.