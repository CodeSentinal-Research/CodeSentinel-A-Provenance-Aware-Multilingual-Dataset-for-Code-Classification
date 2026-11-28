def search_students(students, threshold):
    result = [student for student in students if student['gpa'] >= threshold]
    return result

def handle_input():
    students = []
    while True:
        student = input("Enter student data (format: name, gpa, major): ")
        if student == '':
            break
        name, gpa, major = student.split(',')
        students.append({
            'name': name,
            'gpa': float(gpa),
            'major': major
        })
    threshold = float(input("Enter GPA threshold: "))
    return students, threshold

def main():
    students, threshold = handle_input()
    result = search_students(students, threshold)
    for student in result:
        print(f"{student['name']}, {student['gpa']}, {student['major']}")

if __name__ == "__main__":
    main()

This Python code defines a function `search_students` which takes a list of students and a threshold GPA, and returns a list of students who have a GPA greater than or equal to the threshold. The main function `handle_input` takes user input for student data and a GPA threshold, and returns the list of students and the threshold. The main function then calls `search_students` with these inputs and prints the results.