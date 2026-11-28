Here's a Python code snippet that takes care of the given problem:

def is_leap_year(year):
    if year % 4 != 0:
        return False
    elif year % 100 != 0:
        return True
    elif year % 400 != 0:
        return False
    else:
        return True

def main():
    year = int(input("Enter a year (1 ≤ year ≤ 9999): "))
    if year < 1 or year > 9999:
        print("Invalid input!")
    else:
        if is_leap_year(year):
            print("Leap Year")
        else:
            print("Not a Leap Year")

if __name__ == "__main__":
    main()

This program first defines a function is_leap_year(year) that checks whether a given year is a leap year. It then implements a main function that prompts the user to input a year and checks if it is a leap year.