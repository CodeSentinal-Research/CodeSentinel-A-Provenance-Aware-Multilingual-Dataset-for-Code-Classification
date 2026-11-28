def calculate_volume(length, breadth, height):
    volume = length * breadth * height
    return volume

while True:
    try:
        length = int(input("Enter length of cuboid: "))
        breadth = int(input("Enter breadth of cuboid: "))
        height = int(input("Enter height of cuboid: "))

        if 1 <= length <= 100 and 1 <= breadth <= 100 and 1 <= height <= 100:
            print("Volume of cuboid is: ", calculate_volume(length, breadth, height))
            break
        else:
            print("Invalid input, please enter numbers between 1 and 100.")
    except ValueError:
        print("Invalid input, please enter a number.")