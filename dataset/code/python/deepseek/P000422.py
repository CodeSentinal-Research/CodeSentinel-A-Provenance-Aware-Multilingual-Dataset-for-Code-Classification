Sure, here's a Python solution that can solve the problem:

def search_students(students, min_cgpa, max_income):
    eligible_students = []
    for student in students:
        cgpa = student['cgpa']
        income = student['income']
        if cgpa >= min_cgpa and income <= max_income:
            eligible_students.append(student)
    return eligible_students

This function takes a list of student dictionaries as input. Each dictionary contains the student's CGPA and annual income. It uses a for loop to iterate over each student in the list. If the student's CGPA is greater than or equal to the minimum CGPA and the student's income is less than or equal to the maximum income, the student is added to the list of eligible students. Finally, the function returns the list of eligible students.

Please note that the given problem is quite complex and requires database operations which are not possible in this problem. I'm assuming the students' information is available in the list of dictionaries. 

The function can be used like this:

students = [
    {'cgpa': 3.6, 'income': 50000},
    {'cgpa': 3.8, 'income': 60000},
    {'cgpa': 3.5, 'income': 70000},
    {'cgpa': 3.9, 'income': 80000},
    {'cgpa': 3.7, 'income': 90000}
]
min_cgpa = 3.0
max_income = 70000
print(search_students(students, min_cgpa, max_income))

This will print out the students who have a CGPA of 3.0 or higher and an annual income less than or equal to 70000.