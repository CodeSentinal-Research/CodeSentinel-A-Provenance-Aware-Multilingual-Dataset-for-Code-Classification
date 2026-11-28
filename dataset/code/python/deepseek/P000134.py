Here is the Python code:

def sort_array_by_parity():
    n = int(input().strip())
    a = [int(i) for i in input().strip().split()]
    
    even = [i for i in a if i % 2 == 0]
    odd = [i for i in a if i % 2 != 0]
    
    even.sort()
    
    result = even + odd
    print(' '.join(map(str, result)))

sort_array_by_parity()

This program first reads the number of elements in the array. Then it reads the array elements. The even and odd numbers are then separated and sorted in two different lists. The sorted even numbers are combined with the sorted odd numbers to get the final sorted array.