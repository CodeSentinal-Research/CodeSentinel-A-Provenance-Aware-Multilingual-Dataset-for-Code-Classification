// Compare Version Numbers
const fs=require("fs");
const [a,b]=fs.readFileSync(0,"utf8").trim().split(/\s+/);const norm=s=>s.split(".").map(x=>x.replace(/^0+/,"")||"0");const x=norm(a),y=norm(b);let ans=0;for(let i=0;i<Math.max(x.length,y.length);i++){const p=x[i]||"0",q=y[i]||"0";if(p.length!==q.length){ans=p.length>q.length?1:-1;break;}if(p!==q){ans=p>q?1:-1;break;}}console.log(ans);