console.log(require("fs").readFileSync("/dev/stdin","utf8").trim().split(" ").map(w=>w?w[0].toUpperCase()+w.slice(1).toLowerCase():w).join(" "));
