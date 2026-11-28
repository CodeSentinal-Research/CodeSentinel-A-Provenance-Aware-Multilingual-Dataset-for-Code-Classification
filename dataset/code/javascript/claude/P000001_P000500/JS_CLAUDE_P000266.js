const l=require("fs").readFileSync("/dev/stdin","utf8").trim().split(" ");console.log(l[0].split(l[1]).join(""));
