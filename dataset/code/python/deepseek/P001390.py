Sure, here is the Python code:

def find_longest_zerosum_subarray(arr):
    max_length = 0
    cum_sum_dict = {0: -1}
    cum_sum = 0

    for i in range(len(arr)):
        cum_sum += arr[i]

        if cum_sum in cum_sum_dict:
            max_length = max(max_length, i - cum_sum_dict[cum_sum])
        else:
            cum_sum_dict[cum_sum] = i

    return max_length

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(find_longest_zerosum_subarray(arr))

if __name__ == "__main__":
    main()

This code uses a dictionary to store the cumulative sum of the array and the index of the first occurrence of each cumulative sum. If a cumulative sum is encountered that is already in the dictionary, it means that we have found a subarray sum equals to zero, and the length of this subarray can be calculated as the difference between the index of the current cumulative sum and the index of the last occurrence of the cumulative sum. The maximum length is updated if necessary.