Here is a simple solution in JavaScript. The solution assumes that the student records are stored in an array of objects, with each object representing a student. Each student has properties for name, CGPA, and annual income.

function getEligibleStudents(studentRecords, minCGPA, maxIncome) {
    return studentRecords.filter(student => student.CGPA >= minCGPA && student.annualIncome <= maxIncome);
}

// Example usage:
const studentRecords = [
    { name: 'John', CGPA: 3.7, annualIncome: 50000 },
    { name: 'Anna', CGPA: 3.8, annualIncome: 60000 },
    { name: 'Peter', CGPA: 3.9, annualIncome: 70000 },
    { name: 'Linda', CGPA: 3.6, annualIncome: 55000 }
];

const minCGPA = 3.5;
const maxIncome = 60000;

console.log(getEligibleStudents(studentRecords, minCGPA, maxIncome));

This function uses the `filter()` method in JavaScript to create a new array with all elements that pass the test implemented by the provided function. In this case, the test is whether the student's CGPA is greater than or equal to the minimum CGPA and their annual income is less than or equal to the maximum income.

The example usage in the question is a simplified representation of what the data might look like, and might need to be adapted to your specific use case.