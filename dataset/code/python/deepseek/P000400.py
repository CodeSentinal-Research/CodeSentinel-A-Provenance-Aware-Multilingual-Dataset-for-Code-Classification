Here is the Python code for the problem:

def search_employees_by_salary_range(employee_records, min_salary, max_salary):
    return [emp for emp in employee_records if min_salary <= emp['salary'] <= max_salary]

def main():
    num_employees = int(input("Enter the number of employees: "))

    min_salary = int(input("Enter the minimum salary: "))
    max_salary = int(input("Enter the maximum salary: "))

    employee_records = [{'name': input(f"Enter the name for employee {i+1}: "), 'salary': int(input(f"Enter the salary for employee {i+1}: "))} for i in range(num_employees)]

    matching_employees = search_employees_by_salary_range(employee_records, min_salary, max_salary)

    print("\nMatching employees:")
    for emp in matching_employees:
        print(f"Name: {emp['name']}, Salary: {emp['salary']}")

if __name__ == "__main__":
    main()

This code first asks for the number of employees and the minimum and maximum salary, then it asks for the name and salary for each employee. After that, it calls the `search_employees_by_salary_range` function with the employee records, the minimum and maximum salary, and prints out all the matching employees.