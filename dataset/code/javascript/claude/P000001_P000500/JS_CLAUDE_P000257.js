const[s1,s2]=require("fs").readFileSync("/dev/stdin","utf8").trim().split(" ");const sort=s=>[...s].sort().join("");console.log(sort(s1)===sort(s2)?"Yes":"No");
