Here is the Python code for the problem:

def singleNumber(nums):
    res = 0
    for i in range(32):
        count = 0
        for num in nums:
            if ((num >> i) & 1):
                count += 1
        res |= (count % 3) << i
    if (res >= 2**31):
        res -= 2**32
    return res

def main():
    nums = []
    while True:
        n = int(input("Enter a number (or 'q' to quit): "))
        if n == 'q':
            break
        nums.append(n)
    print(singleNumber(nums))

if __name__ == "__main__":
    main()

In the code above, we use bit manipulation to find the single number. The algorithm works by iterating over each bit position and counting the number of occurrences of each bit. The single number is the bit position where the count is not divisible by 3. We use the bitwise OR operator (`|`) to set the bit in the result. If the result is too large to fit in 32 bits, we subtract 2^32 to get the actual result. 

Please note that this solution only works for numbers in the range from -2^31 to 2^31 - 1. If you are working with a different range, you may need to adjust the code accordingly.