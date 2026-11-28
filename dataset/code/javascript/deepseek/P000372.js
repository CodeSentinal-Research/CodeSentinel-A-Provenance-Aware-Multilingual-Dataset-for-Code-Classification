Here is the JavaScript code for the problem.

function searchStudent(records, rollNumber) {
    for (let i = 0; i < records.length; i++) {
        if (records[i].rollNumber === rollNumber) {
            return records[i];
        }
    }
    return "Record Not Found";
}

This code defines a function `searchStudent` that takes in two arguments: an array of student records and a roll number. It then iterates over the records, checking each one to see if it has the same roll number as the provided roll number. If it finds a match, it returns the corresponding student details. If it doesn't find a match, it returns the string "Record Not Found".

This function is designed to handle input data of the given constraints: the number of student records should be between 1 and 10^5, and each student record should contain a `rollNumber` field. The student records should be passed as an array of objects, where each object represents a student and has a `rollNumber` field.