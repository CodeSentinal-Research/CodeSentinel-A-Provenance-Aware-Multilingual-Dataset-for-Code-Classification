Here is the Python code for the problem:

def calculate_perimeter(side):
    if 1 <= side <= 1000:
        perimeter = 4 * side
        return perimeter
    else:
        return "Invalid input. Please enter a number between 1 and 1000."

def main():
    side = float(input("Enter side length of the square: "))
    result = calculate_perimeter(side)
    if isinstance(result, float):
        print(f"The perimeter of the square is {result}")
    else:
        print(result)

if __name__ == "__main__":
    main()
In this program, the calculate_perimeter function calculates the perimeter of a square given its side length. If the input is not within the range of 1 to 1000, it returns an error message. The main function handles the user input and output.