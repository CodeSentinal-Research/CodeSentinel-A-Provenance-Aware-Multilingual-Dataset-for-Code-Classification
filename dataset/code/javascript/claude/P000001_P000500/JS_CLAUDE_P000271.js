const[s1,s2]=require("fs").readFileSync("/dev/stdin","utf8").trim().split(" ");console.log(s1.length===s2.length&&(s1+s1).includes(s2)?"Yes":"No");
