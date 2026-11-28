Here is the Python code for the problem:

def findMaxLength(nums):
    count_map = {0: [-1]}  
    max_len = 0  
    count = 0  

    for i, num in enumerate(nums):
        count += 1 if num == 0 else -1
        if count in count_map:
            max_len = max(max_len, i - count_map[count][0])
        else:
            count_map[count] = [i, count]

    return max_len

def main():
    nums = [0,1,0,1,0,1,1]
    print(findMaxLength(nums))

if __name__ == "__main__":
    main()

This code works by using a dictionary to store the count of 0s in the array. If the count of 0s is seen for the first time, it is stored in the dictionary along with the index. For every other count of 0s, it checks if the current index minus the first index of the count in the dictionary is greater than the maximum length. If it is, the maximum length is updated.

In the main function, the array [0,1,0,1,0,1,1] is given, and the function will print the maximum length of the subarray with equal numbers of 0s and 1s.