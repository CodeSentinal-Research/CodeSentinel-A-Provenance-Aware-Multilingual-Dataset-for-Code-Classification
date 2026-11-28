const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const A=[];for(let i=0;i<n;i++) A.push(lines[i+1].trim().split(' ').map(Number));
for(let layer=0;layer<Math.floor(n/2);layer++){
    const first=layer,last=n-1-layer;
    for(let i=first;i<last;i++){
        const off=i-first,top=A[first][i];
        A[first][i]=A[last-off][first];
        A[last-off][first]=A[last][last-off];
        A[last][last-off]=A[first+off][last];
        A[first+off][last]=top;
    }
}
for(let i=0;i<n;i++) console.log(A[i].join(' '));
