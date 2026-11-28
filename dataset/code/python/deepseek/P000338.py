Here is the Python code:

def check_equivalent_arrays(array1, array2):
    if sorted(array1) == sorted(array2):
        print("Yes")
    else:
        print("No")

def main():
    array1 = input("Enter the first array of strings (separated by space): ").split()
    array2 = input("Enter the second array of strings (separated by space): ").split()
    check_equivalent_arrays(array1, array2)

if __name__ == "__main__":
    main()

In this code, the `main` function gets the two arrays of strings from the user and calls the `check_equivalent_arrays` function with the user inputs. The `check_equivalent_arrays` function sorts the arrays and compares them. If they are equivalent, it prints "Yes"; otherwise, it prints "No".