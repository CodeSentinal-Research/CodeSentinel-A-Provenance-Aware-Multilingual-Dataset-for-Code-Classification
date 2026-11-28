Sure, here is the Python code for the problem:

def separate_even_odd():
    N = int(input())
    arr = list(map(int, input().split()))
    even = []
    odd = []
    for num in arr:
        if num % 2 == 0:
            even.append(num)
        else:
            odd.append(num)
    print(*even, *odd)

if __name__ == "__main__":
    separate_even_odd()

In this code, we first get the number of elements N from the input. Then, we get the elements of the array. We use two lists, even and odd, to store even and odd numbers separately. For each number in the array, we check if it's even or odd by using the modulo operator (`%`). If it's even, we append it to the `even` list, otherwise we append it to the `odd` list. Finally, we print the elements of the `even` and `odd` lists separated by spaces.