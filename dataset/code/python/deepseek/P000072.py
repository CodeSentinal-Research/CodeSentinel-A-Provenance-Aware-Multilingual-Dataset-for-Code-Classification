def calculate_volume_of_cube(side):
    if 1 <= side <= 100:
        return side ** 3
    else:
        return 'Invalid input. Please enter a number between 1 and 100.'

print(calculate_volume_of_cube(3))  
print(calculate_volume_of_cube(101))