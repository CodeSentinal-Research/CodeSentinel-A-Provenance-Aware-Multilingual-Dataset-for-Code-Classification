Here is the JavaScript code to solve the problem:

function searchEmployeesBySalaryRange(employeeRecords, minSalary, maxSalary) {
    let matchingEmployees = employeeRecords.filter(employee => employee.salary >= minSalary && employee.salary <= maxSalary);
    return matchingEmployees;
}

// Example usage:
let employees = [
    { name: 'John', salary: 30000 },
    { name: 'Emma', salary: 50000 },
    { name: 'Kelly', salary: 60000 },
    { name: 'Lucas', salary: 75000 }
];

let result = searchEmployeesBySalaryRange(employees, 50000, 75000);
console.log(result); // Expected output: [ { name: 'John', salary: 30000 }, { name: 'Lucas', salary: 75000 } ]

This function uses the `filter` method in JavaScript to create a new array with all employees whose salaries fall within the specified range. The `filter` method creates a new array with all elements that pass the test implemented by the provided function. In this case, it checks if the employee's salary falls within the provided range.