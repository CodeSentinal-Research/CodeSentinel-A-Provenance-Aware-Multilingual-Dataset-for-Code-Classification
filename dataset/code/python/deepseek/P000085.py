Sure, here is the Python code:

def grade_calculation(marks):
    if marks >= 90:
        return 'A'
    elif marks >= 80:
        return 'B'
    elif marks >= 70:
        return 'C'
    elif marks >= 60:
        return 'D'
    else:
        return 'F'

def main():
    marks = int(input("Enter marks: "))
    grade = grade_calculation(marks)
    print("Grade: ", grade)

if __name__ == "__main__":
    main()

You can run this code, enter your marks, and it will print the corresponding grade.