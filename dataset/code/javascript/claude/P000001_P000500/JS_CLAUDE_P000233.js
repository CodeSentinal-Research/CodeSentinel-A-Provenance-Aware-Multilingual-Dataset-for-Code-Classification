const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const[r,c]=l[0].split(' ').map(Number);
const mh=h=>{const st=[];let mx=0;[...h,0].forEach((v,i)=>{while(st.length&&h[st[st.length-1]]>=v){const ht=h[st.pop()];const w=st.length?i-st[st.length-1]-1:i;mx=Math.max(mx,ht*w);}st.push(i);});return mx;};
const h=new Array(c).fill(0);let ans=0;
for(let i=0;i<r;i++){const row=l[i+1].split(' ').map(Number);for(let j=0;j<c;j++)h[j]=row[j]?h[j]+1:0;ans=Math.max(ans,mh([...h]));}
console.log(ans);
