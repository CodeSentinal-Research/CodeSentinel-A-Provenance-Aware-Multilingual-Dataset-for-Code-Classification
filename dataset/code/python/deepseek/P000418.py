Here is a Python solution for the problem. In this code, we use a dictionary to map each employee's ID to their record. We then iterate through the dictionary, checking if the joining date of each employee is earlier than the specified date.

def search_employees(employee_records, date):
    return [record for record in employee_records.values() if record[2] < date]

def main():
    employee_records = [(1, 'John', '2000-01-01'), (2, 'Mike', '2001-02-01'), (3, 'Sara', '2002-03-01')]
    date = '2002-02-01'

    from datetime import datetime
    date_obj = datetime.strptime(date, '%Y-%m-%d')

    matched_employees = search_employees(employee_records, date_obj)

    for record in matched_employees:
        print(record)

if __name__ == "__main__":
    main()

In the `main` function, we first convert the date string to a `datetime` object using the `strptime` function. Then we call the `search_employees` function with the `employee_records` and `date_obj` as arguments. The result is a list of tuples representing the matched employees. We then print each employee's record.