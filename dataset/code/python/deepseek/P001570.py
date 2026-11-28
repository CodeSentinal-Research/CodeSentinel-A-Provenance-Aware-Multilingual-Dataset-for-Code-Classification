Here is the Python code for the given problem:

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    max_length = positive_product(nums)
    print(max_length)

def positive_product(nums):
    max_length = 0
    cur_product = 1
    for num in nums:
        if num == 0:
            cur_product = 1
            continue
        cur_product *= num
        if cur_product > 0:
            max_length = max(max_length, len(cur_product))
    cur_product = 1
    for num in reversed(nums):
        cur_product *= num
        if cur_product > 0:
            max_length = max(max_length, len(cur_product))
    return max_length

if __name__ == "__main__":
    main()

This code first reads the number of elements in the input array (N) and the elements themselves. It then calls the `positive_product` function with these inputs, and prints the result. The `positive_product` function works by iterating through the array, multiplying each element to the current product, and keeping track of the maximum length of a subarray with a positive product. The code also handles the case where a number is 0, in which case the product is reset to 1 and continues with the next number.