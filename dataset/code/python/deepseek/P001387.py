Here is the Python code:

def check_array_equality():
    n, m = map(int, input().split())
    array1 = list(map(int, input().split()))
    array2 = list(map(int, input().split()))

    if sorted(array1) == sorted(array2):
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    check_array_equality()

In this code, we first read the number of elements in the first and the second array, then read the elements themselves. We then sort both arrays and check if they are equal. If they are, we print 'YES', otherwise we print 'NO'.