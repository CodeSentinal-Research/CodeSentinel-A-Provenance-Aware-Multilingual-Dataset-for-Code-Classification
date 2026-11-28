function findIntersection(a, b) {
    const s = new Set(a);
    return [...new Set(b.filter(x=>s.has(x)))].sort((x,y)=>x-y);
}
module.exports = { findIntersection };
