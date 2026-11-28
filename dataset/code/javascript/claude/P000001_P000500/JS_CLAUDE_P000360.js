const l=require("fs").readFileSync("/dev/stdin","utf8").trim().split("\n");const a=l[1].split(" ").map(Number);const i=a.findIndex(x=>x%2===0);console.log(i);
