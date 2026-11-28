const fs = require("fs");
const [a, b, c] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000065 - Find LCM of Three Numbers
function gcd(x, y) { while (y) { [x, y] = [y, x % y]; } return x; }
function lcm(x, y) { return (x / gcd(x, y)) * y; }
console.log(lcm(lcm(a, b), c));
