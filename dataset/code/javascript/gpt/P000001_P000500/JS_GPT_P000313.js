// Valid Number
const fs=require("fs");
const s=fs.readFileSync(0,"utf8").trim();console.log(/^[+-]?((\d+(\.\d*)?)|(\.\d+))([eE][+-]?\d+)?$/.test(s)?"Valid":"Invalid");