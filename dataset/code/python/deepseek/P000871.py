Here is the Python code for your problem:

def rangeBitwiseAnd(left: int, right: int) -> int:
    shift = 0
    while ((right >> shift) >> shift) > 0:
        shift += 1

    while shift >= 0:
        if ((left >> shift) & ((1 << 1) | right >> shift)) == 0:
            left &= ~((1 << shift) | right << shift)
        else:
            break
        shift -= 1
    return left

def main():
    left = int(input("Enter left: "))
    right = int(input("Enter right: "))
    print("Bitwise AND of numbers in the range is:", rangeBitwiseAnd(left, right))

if __name__ == "__main__":
    main()

In this code, we're finding the maximum power of 2 that is less than or equal to 'right'. This allows us to keep only the range of 'left' and 'right' that we're interested in. Then, for each bit position in the range, we're checking whether that bit is set in both 'left' and 'right'. If it is, we're setting the corresponding bit in 'left' to 0; otherwise, we're breaking out of the loop.