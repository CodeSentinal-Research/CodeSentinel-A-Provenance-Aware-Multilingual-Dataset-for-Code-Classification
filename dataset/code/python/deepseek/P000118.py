Here is the Python code for the problem:

def move_zeros_to_end():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    non_zero_elements = [i for i in arr if i != 0]
    zero_elements = arr.count(0)
    result = non_zero_elements + [0]*zero_elements
    print(*result, sep=' ')

move_zeros_to_end()

This code first reads the number of elements in the array and the array itself. It then uses list comprehension to create a new list with the non-zero elements of the original list followed by zeroes.