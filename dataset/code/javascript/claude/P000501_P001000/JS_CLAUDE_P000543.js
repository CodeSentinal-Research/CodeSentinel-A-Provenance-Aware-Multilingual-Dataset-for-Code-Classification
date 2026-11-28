/* P000543: Data Stream as Disjoint Intervals */
const l=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const q=+l[0];let ivs=[];
function add(v){
    let nl=v,nh=v;const rem=[];
    for(let i=0;i<ivs.length;i++){if(ivs[i][1]<v-1||ivs[i][0]>v+1)continue;
        nl=Math.min(nl,ivs[i][0]);nh=Math.max(nh,ivs[i][1]);rem.push(i);}
    ivs=ivs.filter((_,i)=>!rem.includes(i));
    ivs.push([nl,nh]);ivs.sort((a,b)=>a[0]-b[0]);
}
for(let i=1;i<=q;i++){const parts=l[i].trim().split(' ');
    if(parts[0]==='addNum')add(+parts[1]);
    else console.log(ivs.map(([a,b])=>`[${a},${b}]`).join(' '));}
