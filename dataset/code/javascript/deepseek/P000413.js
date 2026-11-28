Here is a simple solution using JavaScript. It assumes that the employee records are in the form of an object, where the keys are the employee ids and the values are the employee records. It also assumes that the department name is a string.

function searchActiveEmployees(employees, department) {
    let matchingEmployees = [];

    for (let employeeId in employees) {
        let employee = employees[employeeId];

        if (employee.department === department && employee.active) {
            matchingEmployees.push(employee);
        }
    }

    return matchingEmployees;
}

In this code, we iterate over all employees in the department. If the employee belongs to the specified department and is currently active, we add them to the list of matching employees.

Please note that this code does not handle input validation. You should ensure that the input is in the correct format before using it. For example, you should check if the employee records and department name are objects, if the department name is a string, and if the number of employees is within the specified range.

Also, the `active` property in the employee record is a boolean. If it's a string, you might want to convert it to a boolean (`employee.active = employee.active === 'true';`).

This code does not handle case insensitivity. If you want case insensitivity, you should convert both the department name and the employee name to the same case (upper or lower) before comparing.

The code assumes that all the employee records are unique and contain the necessary fields. If this is not the case, you should adjust the code accordingly.