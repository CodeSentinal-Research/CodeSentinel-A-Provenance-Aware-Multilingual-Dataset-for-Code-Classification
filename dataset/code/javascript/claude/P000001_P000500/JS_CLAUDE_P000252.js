const s=require("fs").readFileSync("/dev/stdin","utf8").trim();const r=s.split("").reverse().join("");console.log(s===r?"Yes":"No");
