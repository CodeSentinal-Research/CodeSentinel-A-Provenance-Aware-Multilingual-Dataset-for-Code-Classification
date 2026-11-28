// Helper function to evaluate findorder for problem constraints.
function findOrder(numCourses, prerequisites) {
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
    const order = [];
    while (q.length > 0) {
        const u = q.shift();
        order.push(u);
        for (const v of adj[u]) {
            if (--inDeg[v] === 0) q.push(v);
        }
    }
    return order.length === numCourses ? order : [];
}

module.exports = { findOrder };