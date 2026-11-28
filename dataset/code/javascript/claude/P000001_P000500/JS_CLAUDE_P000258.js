console.log([...require("fs").readFileSync("/dev/stdin","utf8").trim()].sort().join(""));
