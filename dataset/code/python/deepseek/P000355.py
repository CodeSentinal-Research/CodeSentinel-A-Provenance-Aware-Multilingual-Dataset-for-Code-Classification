Here is the Python code:

def find_missing_value(n, arr, x):
    total_elements = (n + 1)
    total_sum = total_elements * (total_elements + 1) // 2
    arr_sum = sum(arr)
    missing = total_sum - arr_sum
    if missing == x:
        print("Missing")
    else:
        print("Present")

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    x = int(input().strip())
    find_missing_value(n, arr, x)

if __name__ == "__main__":
    main()
This program first takes the number of elements in the array, then the array itself and the target value as inputs. It calculates the sum of all numbers from 1 to N and subtracts the sum of the elements in the array to find the missing value. It then prints "Missing" if the missing value is the target value, otherwise it prints "Present".