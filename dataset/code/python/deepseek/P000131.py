Here is the Python code for the given problem:

def find_leaders():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    leaders = []
    max_from_right = arr[N-1]

    for i in range(N-1, -1, -1):
        if i == N-1:
            if arr[i] > max_from_right:
                leaders.append(arr[i])
            max_from_right = arr[i]
        else:
            if arr[i] > max_from_right:
                leaders.append(arr[i])
            max_from_right = max(max_from_right, arr[i])

    for leader in leaders:
        print(leader)

if __name__ == "__main__":
    find_leaders()

This program first reads the number of elements N from the first line of input. It then reads the elements of the array from the second line. 

Then it initializes an empty list `leaders` to store the leaders. It also initializes a variable `max_from_right` with the maximum element in the array from the right.

The program then iterates over the array from right to left. For each element, it checks if it is greater than the `max_from_right`. If it is, it appends the element to the `leaders` list. It also updates the `max_from_right` to be the maximum of the current element and `max_from_right`.

Finally, it prints the leaders from left to right.