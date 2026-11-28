const[a,b]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
const m=a.length,n=b.length,pos=new Array(m+n).fill(0);
for(let i=m-1;i>=0;i--)for(let j=n-1;j>=0;j--){
    const mul=(a.charCodeAt(i)-48)*(b.charCodeAt(j)-48),p1=i+j,p2=i+j+1,tot=mul+pos[p2];
    pos[p2]=tot%10;pos[p1]+=Math.floor(tot/10);
}
const res=pos.join('').replace(/^0+/,'');console.log(res||'0');
