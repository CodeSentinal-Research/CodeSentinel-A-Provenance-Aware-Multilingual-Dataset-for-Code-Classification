const l=require("fs").readFileSync("/dev/stdin","utf8").split("\n");const n=+l[0];for(let i=0;i<n;i++){if(l[i+1]===""){console.log(i);process.exit();}}console.log(-1);
