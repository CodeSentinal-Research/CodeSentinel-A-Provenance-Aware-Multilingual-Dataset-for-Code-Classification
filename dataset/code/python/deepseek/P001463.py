Here is the Python code:

def remove_element(array, value):
    array = [element for element in array if element != value]

    print(len(array))

    print(*array)


def main():
    n, value = map(int, input().split())
    array = list(map(int, input().split()))

    remove_element(array, value)


if __name__ == "__main__":
    main()

This code will take the input for N and the value, then read the N integers for the array. It will then call the `remove_element` function, passing the array and the value as arguments. This function will remove all occurrences of the value from the array and print the new length followed by the array.