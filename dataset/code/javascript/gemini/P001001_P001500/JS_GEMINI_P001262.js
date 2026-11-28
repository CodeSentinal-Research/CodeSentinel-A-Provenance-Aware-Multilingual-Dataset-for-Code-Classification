// Helper function to evaluate schedulecourse for problem constraints.
function scheduleCourse(courses) {
    courses.sort((a, b) => a[1] - b[1]);
    const pq = [];
    let time = 0;

    for (const [duration, lastDay] of courses) {
        time += duration;
        pq.push(duration);
        if (time > lastDay) {
            pq.sort((a, b) => b - a);
            time -= pq.shift();
        }
    }
    return pq.length;
}

module.exports = { scheduleCourse };