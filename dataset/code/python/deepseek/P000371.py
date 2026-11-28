Here's the Python code for the given problem:

def search_employee(employee_records, employee_id):
    for employee in employee_records:
        if employee['id'] == employee_id:
            return employee
    return "Record Not Found"

def main():
    employee_records = [{'id': 1, 'name': 'John', 'salary': 50000}, {'id': 2, 'name': 'Sara', 'salary': 60000}]

    employee_id = int(input("Enter employee ID: "))
    result = search_employee(employee_records, employee_id)
    
    if isinstance(result, str):
        print(result)
    else:
        print('Employee Details:')
        print('ID:', result['id'])
        print('Name:', result['name'])
        print('Salary:', result['salary'])

if __name__ == "__main__":
    main()
In this code, the `search_employee` function iterates over each employee record in the `employee_records` list, and checks if the employee ID in the current record matches the input `employee_id`. If a match is found, it returns the current record. If no match is found after checking all records, it returns "Record Not Found".

The `main` function gets the employee ID from the user, calls the `search_employee` function with the employee records and the employee ID, and prints the result. If the result is a string ("Record Not Found"), it prints that message. Otherwise, it prints the employee details.

Remember to replace the `employee_records` variable in `main` with your actual employee records.