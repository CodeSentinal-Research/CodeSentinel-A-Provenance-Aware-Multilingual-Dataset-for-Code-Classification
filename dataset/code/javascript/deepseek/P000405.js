Here is the JavaScript code for the given problem. This code assumes that we have a JSON object array of course records, where each course record is an object with properties `instructor` and `courseID`.

function searchCoursesByInstructor(courses, instructor) {
    return courses.filter(course => course.instructor === instructor);
}

// Sample input
var courses = [
    { instructor: 'John', courseID: 'C1' },
    { instructor: 'John', courseID: 'C2' },
    { instructor: 'Jane', courseID: 'C3' },
    { instructor: 'John', courseID: 'C4' },
    { instructor: 'Jane', courseID: 'C5' },
    { instructor: 'John', courseID: 'C6' },
    { instructor: 'Jane', courseID: 'C7' },
    { instructor: 'John', courseID: 'C8' },
    { instructor: 'Jane', courseID: 'C9' },
    { instructor: 'John', courseID: 'C10' }
];

var instructorName = 'John';

console.log(searchCoursesByInstructor(courses, instructorName));

In this code, the `searchCoursesByInstructor` function takes an array of course records and an instructor name, and returns all courses taught by the specified instructor. The `filter` method is used to create a new array with all elements that pass a test (provided as a function). In this case, the test is whether the course's instructor matches the specified instructor.

The `console.log` statement is used to print the resulting array of matching courses.