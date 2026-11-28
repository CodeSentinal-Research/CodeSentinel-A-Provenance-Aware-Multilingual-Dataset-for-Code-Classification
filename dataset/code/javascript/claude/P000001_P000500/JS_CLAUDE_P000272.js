const l=require("fs").readFileSync("/dev/stdin","utf8").trim().split("\n");const n=+l[0];let p=l[1];for(let i=2;i<=n;i++){while(!l[i].startsWith(p))p=p.slice(0,-1);}console.log(p);
