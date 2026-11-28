Here is the Python code that solves the problem:

def find_duplicate(n):
    read_values = input().split()
    num_set = set()

    for value in read_values:
        if value in num_set:
            return value
        num_set.add(value)

print("Enter the size of the array and the elements:")
n = int(input().strip())
print("Enter array elements:")
print(find_duplicate(n))

This program reads the array size n and the elements, then calls the `find_duplicate` function. The `find_duplicate` function uses a set to keep track of the values that have been read so far, and returns the first duplicate it encounters.