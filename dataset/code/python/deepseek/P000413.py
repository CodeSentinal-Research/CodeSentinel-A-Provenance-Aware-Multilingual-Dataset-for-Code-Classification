def search_employees(records, department):
    return [record for record in records if record['department'] == department and record['active']]

def main():
    records = [{'name': 'John', 'department': 'Sales', 'active': True},
               {'name': 'Mary', 'department': 'Sales', 'active': False},
               {'name': 'Steve', 'department': 'IT', 'active': True},
               {'name': 'Lisa', 'department': 'IT', 'active': False},
               {'name': 'Tom', 'department': 'Sales', 'active': True}]
    department = input("Enter the department name: ")
    result = search_employees(records, department)
    print("Employees in the department: ", department)
    for record in result:
        print(record['name'])

if __name__ == "__main__":
    main()

In this code, the main function first asks for the department name. Then, it passes the employee records and the department name to the `search_employees` function. The `search_employees` function uses list comprehension to find all employees in the specified department and are currently active. The result is a list of active employees in that department. The main function then prints these active employees.