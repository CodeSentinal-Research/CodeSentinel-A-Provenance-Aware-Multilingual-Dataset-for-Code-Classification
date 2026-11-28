Here is the Python code for the problem:

def findKthPositive(nums, k):
    missing = []
    expected = set(range(1, nums[-1] + 2)) - set(nums)
    for num in expected:
        missing.append(num)
    return missing[k - 1] if k - 1 < len(missing) else None


def main():
    nums = [1, 2, 3, 4, 6, 7, 8, 9]
    k = 5
    print(findKthPositive(nums, k))


if __name__ == "__main__":
    main()

In this code, we first generate a set of expected positive integers within the range of the last number in the array and the total numbers in the array. The difference between these two sets gives us the missing positive integers. We then return the k-th element of the list of missing positive integers.