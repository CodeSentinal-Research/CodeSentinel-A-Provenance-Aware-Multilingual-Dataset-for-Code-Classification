const fs = require("fs");
let secs = Number(fs.readFileSync(0, "utf8").trim());
// P000079 - Convert Seconds to Hours Minutes Seconds
const hours = Math.trunc(secs / 3600);
secs = secs % 3600;
const minutes = Math.trunc(secs / 60);
const remSecs = secs % 60;
console.log(hours, minutes, remSecs);
