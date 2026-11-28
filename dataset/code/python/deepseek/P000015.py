def calculate_perimeter(length, breadth):
    if not (1 <= length <= 1000) or not (1 <= breadth <= 1000):
        return "Invalid input. Please enter a number between 1 and 1000."

    perimeter = 2 * (length + breadth)

    return perimeter

print(calculate_perimeter(6, 7))  
print(calculate_perimeter(3, 4))  
print(calculate_perimeter(1001, 5))