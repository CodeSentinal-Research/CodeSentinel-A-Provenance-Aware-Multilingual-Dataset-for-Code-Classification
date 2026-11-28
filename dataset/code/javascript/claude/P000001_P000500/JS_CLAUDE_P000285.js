const[s1,s2]=require("fs").readFileSync("/dev/stdin","utf8").trim().split(" ");let i=0;for(const c of s2)if(i<s1.length&&c===s1[i])i++;console.log(i===s1.length?"Yes":"No");
