process.stdin.resume();
process.stdin.on('data', (chunk) => {
    const N = parseInt(chunk.toString(), 10);
    const courses = [];
    for (let i = 0; i < N; i++) {
        const [duration, deadline] = process.stdin.read()
            .toString()
            .split(/\s/);
        courses.push({ duration: parseInt(duration, 10), deadline: parseInt(deadline, 10) });
    }
    process.stdout.write(JSON.stringify(maxCourses(courses)) + '\n');
});

function maxCourses(courses) {
    courses.sort((a, b) => b.deadline - a.deadline);
    let maxCount = 0;
    let currentDeadline = 0;
    for (const course of courses) {
        if (course.deadline > currentDeadline) {
            maxCount++;
            currentDeadline = course.duration + currentDeadline;
        }
    }
    return maxCount;
}

This code reads the input data from stdin, processes it, and writes the result to stdout. The input is expected to be a list of N courses with their duration and deadline, and the output is the maximum number of courses that can be completed.

The function maxCourses is defined to sort the courses by their deadlines in descending order and then iterate over the sorted list, checking if the next course's deadline is after the current course's deadline. If it is, it means the next course can be finished before the current course, so it increments the count and updates the current deadline.

This function assumes that all durations are positive integers, and all deadlines are positive integers, as well as that they fall within the constraints specified in the problem.