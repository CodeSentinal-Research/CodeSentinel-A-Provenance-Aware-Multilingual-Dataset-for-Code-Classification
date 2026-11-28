console.log(require("fs").readFileSync("/dev/stdin","utf8").trim().replace(/[aeiouAEIOU]/g,""));
