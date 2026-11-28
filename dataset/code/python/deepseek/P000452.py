Here is the Python code for your problem:

def find_single(arr):
    n = len(arr)
    xor = 0
    for i in range(0, n, 2):
        xor = arr[i] ^ xor
    return xor

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    print(find_single(arr))
In this code, the `find_single` function uses the bitwise XOR operation to find the single element in the sorted array. The XOR operation between two numbers is zero if both numbers are the same, so by XOR-ing every other pair of numbers from the start of the array, we can find the single element. The result is the XOR of all elements that are not paired with another element. The result is the single element that appears only once in the sorted array.

In the main function, we first read the number of elements in the array from the input, and then read the elements of the array. We sort the array first because the XOR operation on sorted elements will result in a different element for pairs of elements. Finally, we print the result of the `find_single` function.