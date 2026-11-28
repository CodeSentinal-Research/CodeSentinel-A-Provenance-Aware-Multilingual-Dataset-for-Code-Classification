const[s,t]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
const ms={},mt={};if(s.length!==t.length){console.log('No');process.exit();}
for(let i=0;i<s.length;i++){
    if(!ms[s[i]])ms[s[i]]=t[i];if(!mt[t[i]])mt[t[i]]=s[i];
    if(ms[s[i]]!==t[i]||mt[t[i]]!==s[i]){console.log('No');process.exit();}
}
console.log('Yes');
