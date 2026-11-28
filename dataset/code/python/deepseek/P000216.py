def find_shortest_subarray():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))

    min_length = float('inf')
    start_index = 0

    current_length = 1
    current_degree = nums[0]

    max_degree = -float('inf')
    max_index = 0

    max_length = 0
    end_index = 0

    for i in range(1, n):
        if nums[i] == nums[i-1]:
            current_length += 1
        else:
            if current_length >= min_length:
                if current_degree > max_degree:
                    max_degree = current_degree
                    max_length = current_length
                    max_index = start_index
                if current_length > max_length:
                    max_length = current_length
                    end_index = i
            current_length = 1
            current_degree = nums[i]
            start_index = i

    if current_length >= min_length:
        if current_degree > max_degree:
            max_degree = current_degree
            max_length = current_length
            max_index = start_index
        if current_length > max_length:
            max_length = current_length
            end_index = i

    print(max_length)

find_shortest_subarray()
This Python program uses a sliding window approach to find the shortest contiguous subarray with the same degree as the entire array. It first initializes the variables min_length, start_index, max_length, end_index and max_degree. Then it iterates through the array, updating the variables as necessary. The variables hold the current length, degree of the current subarray, the minimum length found so far, and the end index of the maximum subarray. The final print statement prints the length of the shortest subarray.