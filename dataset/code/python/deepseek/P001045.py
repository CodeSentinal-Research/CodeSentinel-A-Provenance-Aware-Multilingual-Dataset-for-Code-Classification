Sure, here is a Python code for your problem:

def check_heaps(heap1, heap2):
    if heap1 == heap2:
        print('YES')
    else:
        print('NO')

def main():
    N, M = map(int, input().split())
    heap1 = list(map(int, input().split()))
    heap2 = list(map(int, input().split()))

    check_heaps(heap1, heap2)

if __name__ == "__main__":
    main()

In this code, we first define a function `check_heaps` that takes in two heaps and checks if they are identical. The `input` function is used to get the inputs, `map` is used to convert the inputs into integers, and the `==` operator is used to compare the heaps. 

The `main` function is the entry point of the program. It first gets the number of elements in the first heap and the elements themselves. Then it calls the `check_heaps` function with the two heaps. 

The `if __name__ == "__main__"` line is used to ensure the `main` function is only run if the script is run directly, not if it's imported as a module in another script.