Here is the Python code for the problem. 

def product_except_self(nums):
    length = len(nums)
    output = [1] * length

    left = [1] * length
    right = [1] * length

    for i in range(1, length):
        left[i] = nums[i - 1] * left[i - 1]

    for i in range(length - 2, -1, -1):
        right[i] = nums[i + 1] * right[i + 1]

    for i in range(length):
        output[i] = left[i] * right[i]

    return output


def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(product_except_self(nums))


if __name__ == "__main__":
    main()

This code first reads the size of the input array from the standard input. Then it reads the elements of the array from the standard input. The `product_except_self` function then computes and returns the output array. The `main` function handles the input-output interaction.