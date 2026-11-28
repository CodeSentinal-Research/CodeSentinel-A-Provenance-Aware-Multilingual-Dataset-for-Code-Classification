Here is a Python solution for your problem.

def recover_original_array(input_array):
    total_sum = sum(input_array)
    for i in range(len(input_array)):
        for j in range(i, len(input_array)):
            if abs(sum(input_array[i:j+1]) - (total_sum - sum(input_array[i:j+1]))) == 0:
                return input_array[i:j+1]

def main():
    N = int(input().strip())
    input_array = list(map(int, input().strip().split()))
    result = recover_original_array(input_array)
    print(result)

if __name__ == "__main__":
    main()

This program first calculates the total sum of the original array, and then for each possible subarray of the original array, it checks if the sum of the elements in the subarray is equal to the sum of the original array minus the sum of the elements in the subarray. If it is, then the subarray is a valid result of adding and subtracting an unknown positive integer K from every element of the original array. 

The `main` function is the entry point of the program, and it reads the number of elements N and the elements of the original array from the standard input. It then calls the `recover_original_array` function with the original array as the argument, and prints the result.

Please note that the code may not work as expected if there is more than one valid result for the given input array. In such cases, it will return the first valid result it encounters.