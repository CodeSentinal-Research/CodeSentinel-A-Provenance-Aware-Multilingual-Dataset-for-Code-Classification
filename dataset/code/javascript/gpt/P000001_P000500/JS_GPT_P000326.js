// Number of Segments in a String
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();console.log(s?s.split(/\s+/).length:0);