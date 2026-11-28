const l=require("fs").readFileSync("/dev/stdin","utf8").trim().split("\n");const a=l[1].split(" ").map(Number);const x=+l[2];console.log(a.filter(v=>v===x).length);
