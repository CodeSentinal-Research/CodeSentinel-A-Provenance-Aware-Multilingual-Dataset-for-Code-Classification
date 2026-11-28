// Helper function to evaluate canfinish for problem constraints.
function canFinish(numCourses, prerequisites) {
    const adj = Array.from({ length: numCourses }, () => []);
    const inDeg = new Array(numCourses).fill(0);
    for (const [course, pre] of prerequisites) {
        adj[pre].push(course);
        inDeg[course]++;
    }
    const q = [];
    for (let i = 0; i < numCourses; i++) {
        if (inDeg[i] === 0) q.push(i);
    }
    let count = 0;
    while (q.length > 0) {
        const u = q.shift();
        count++;
        for (const v of adj[u]) {
            if (--inDeg[v] === 0) q.push(v);
        }
    }
    return count === numCourses;
}

module.exports = { canFinish };