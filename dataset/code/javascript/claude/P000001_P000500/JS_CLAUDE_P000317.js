const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const pat=lines[0].trim(),words=lines[1].trim().split(' ');
if(pat.length!==words.length){console.log('No');process.exit();}
const mp={},mw={};
for(let i=0;i<pat.length;i++){
    const c=pat[i],w=words[i];
    if(!mp[c])mp[c]=w;if(!mw[w])mw[w]=c;
    if(mp[c]!==w||mw[w]!==c){console.log('No');process.exit();}
}
console.log('Yes');
