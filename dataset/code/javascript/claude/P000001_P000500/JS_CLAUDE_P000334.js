const[source,target]=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
let j=0,cnt=0,tl=target.length;
while(j<tl){const prev=j;for(let i=0;i<source.length&&j<tl;i++)if(source[i]===target[j])j++;if(j===prev){console.log(-1);process.exit();}cnt++;}console.log(cnt);
