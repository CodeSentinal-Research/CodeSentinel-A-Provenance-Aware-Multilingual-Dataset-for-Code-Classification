Here's the Python code for the problem:

N = int(input())
numbers = list(map(int, input().split()))

even_numbers = [num for num in numbers if num % 2 == 0]
odd_numbers = [num for num in numbers if num % 2 != 0]

print(even_numbers + odd_numbers)

In this code, we first take the number of elements N as input. Then, we take the list of numbers as input. We use a list comprehension to segregate the even and odd numbers and then print the combined list of even and odd numbers.