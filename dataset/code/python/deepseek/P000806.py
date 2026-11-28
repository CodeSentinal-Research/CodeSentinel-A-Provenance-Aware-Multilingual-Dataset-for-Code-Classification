Here's a Python solution using a hashmap to store the prefix sums and the longest length. This solution has O(n) complexity, where n is the length of the input array.

def find_max_length(nums):
    prefix_sums = {0: -1}
    max_length = curr_sum = 0

    for i, num in enumerate(nums):
        curr_sum += num

        if curr_sum not in prefix_sums:
            prefix_sums[curr_sum] = i

        if curr_sum in prefix_sums and i - prefix_sums[curr_sum] > max_length:
            max_length = i - prefix_sums[curr_sum]

    return max_length

The main function to handle input:

def main():
    nums = [1, -1, 5, -7, 2, -3, 3]
    print(find_max_length(nums))  

if __name__ == "__main__":
    main()

In this code, we first initialize the prefix sums and the maximum length to 0. Then we iterate through the input array, adding each number to the current sum. If the current sum is not in the prefix sums dictionary, we store the index in the dictionary. If the current sum is in the dictionary and the difference between the current index and the stored index is greater than the maximum length, we update the maximum length. The maximum length will hold the length of the longest subarray containing an equal number of positive and negative elements.