Here's the Python code for your problem:

def search_employees_by_department(records, department_name):
    matching_employees = [record for record in records if record['department'] == department_name]
    if not matching_employees:
        return "No Records Found"
    return matching_employees

def main():
    records = [{'name': 'John', 'department': 'Sales'}, {'name': 'Alice', 'department': 'Marketing'}, {'name': 'Bob', 'department': 'Sales'}]
    department_name = 'Sales'
    print(search_employees_by_department(records, department_name))

if __name__ == "__main__":
    main()

This code defines a function `search_employees_by_department` that takes an employee records list and a department name as input. It returns a list of employees who belong to the given department. If no employees are found, it returns the string "No Records Found".

In the `main` function, it creates a list of employee records, specifies the department name, and calls the `search_employees_by_department` function with these parameters. The result is printed out.

Please modify the `main` function according to your actual input.