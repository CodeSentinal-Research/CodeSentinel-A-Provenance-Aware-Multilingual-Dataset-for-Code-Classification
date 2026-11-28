const[a,b]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
const pa=a.split('.').map(Number),pb=b.split('.').map(Number);
const n=Math.max(pa.length,pb.length);
for(let i=0;i<n;i++){const va=pa[i]||0,vb=pb[i]||0;if(va<vb){console.log(-1);process.exit();}if(va>vb){console.log(1);process.exit();}}console.log(0);
