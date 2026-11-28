Sure, here is the JavaScript code for your problem. This code assumes that the input data is passed as an object within an object in a JSON structure.

function searchEmployeesByDepartment(employees, department) {
    let employeesInDepartment = employees[department];

    if (!employeesInDepartment) {
        return "No Records Found";
    }

    return employeesInDepartment;
}

You can use this function like this:

let employees = {
    'HR': ['John', 'Jane', 'Joe'],
    'Marketing': ['Mike', 'Tom'],
    'Sales': ['Sara', 'David']
};

console.log(searchEmployeesByDepartment(employees, 'HR'));
console.log(searchEmployeesByDepartment(employees, 'Marketing'));
console.log(searchEmployeesByDepartment(employees, 'Sales'));
console.log(searchEmployeesByDepartment(employees, 'IT'));

In this code, `employees` is an object where each key is a department and the value is an array of employees in that department. The `searchEmployeesByDepartment` function takes an employees object and a department name, and returns an array of employees in that department or "No Records Found" if no employees in that department exist.

Please note, this is a simple implementation and does not include input validation or error handling. In a production environment, you should add error handling and input validation.