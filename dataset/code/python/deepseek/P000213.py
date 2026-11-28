Here is the Python code for the problem:

def third_maximum_number():
    n = int(input().strip())
    numbers = list(map(int, input().strip().split()))
    unique_numbers = list(set(numbers))
    if len(unique_numbers) < 3:
        return max(unique_numbers)
    else:
        unique_numbers.sort()
        return unique_numbers[-3]

if __name__ == "__main__":
    print(third_maximum_number())

This Python program takes an input of N numbers, and finds the third distinct maximum number in the list. If there are less than 3 unique numbers, it returns the maximum of the unique numbers. Otherwise, it sorts the unique numbers and returns the third maximum number.

You can run this program in a local environment or an online Python compiler to test it. 

Please replace the placeholder "input().strip()" with your actual input.