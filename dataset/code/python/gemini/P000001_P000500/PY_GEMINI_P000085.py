def calculate_grade(marks: float) -> str:
    if marks >= 90:
        return 'A'
    elif marks >= 80:
        return 'B'
    elif marks >= 70:
        return 'C'
    elif marks >= 60:
        return 'D'
    elif marks >= 50:
        return 'E'
    else:
        return 'F'

if __name__ == '__main__':
    marks = float(input())
    print(calculate_grade(marks))