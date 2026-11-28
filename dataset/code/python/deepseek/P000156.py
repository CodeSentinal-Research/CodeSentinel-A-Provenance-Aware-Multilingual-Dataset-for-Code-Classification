Here's the Python code for the problem:

def max_zeros():
    N = int(input().strip())
    binary_array = list(map(int, input().strip().split()))
    
    max_zeros = 0
    current_zeros = 0
    
    for num in binary_array:
        if num == 0:
            current_zeros += 1
            max_zeros = max(max_zeros, current_zeros)
        else:
            current_zeros = 0
    
    return max_zeros

if __name__ == "__main__":
    print(max_zeros())

In this program, the user will be prompted to enter the number of elements in the binary array and then the elements themselves. The program will then iterate through the binary array, keeping track of the maximum number of consecutive zeros.