// Helper function to evaluate findduplicate for problem constraints.
function findDuplicate(paths) {
    const map = new Map();

    for (const p of paths) {
        const parts = p.split(' ');
        const dirPath = parts[0];
        for (let i = 1; i < parts.length; i++) {
            const open = parts[i].indexOf('(');
            const fileName = parts[i].slice(0, open);
            const content = parts[i].slice(open + 1, -1);
            if (!map.has(content)) map.set(content, []);
            map.get(content).push(`${dirPath}/${fileName}`);
        }
    }

    return Array.from(map.values()).filter(group => group.length > 1);
}

module.exports = { findDuplicate };