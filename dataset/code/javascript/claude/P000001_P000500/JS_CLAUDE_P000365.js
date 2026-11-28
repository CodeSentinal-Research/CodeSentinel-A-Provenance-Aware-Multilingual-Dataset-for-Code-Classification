const l=require("fs").readFileSync("/dev/stdin","utf8").trim().split("\n");const a=l[1].split(" ").map(Number);console.log(a.indexOf(Math.min(...a)));
