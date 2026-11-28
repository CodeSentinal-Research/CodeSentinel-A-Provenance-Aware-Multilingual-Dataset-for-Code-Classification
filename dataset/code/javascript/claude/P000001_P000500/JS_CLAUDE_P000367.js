const l=require("fs").readFileSync("/dev/stdin","utf8").trim().split("\n");const n=+l[0];const w=l.slice(1,n+1);let mi=0;for(let i=1;i<n;i++)if(w[i].length<w[mi].length)mi=i;console.log(mi);
