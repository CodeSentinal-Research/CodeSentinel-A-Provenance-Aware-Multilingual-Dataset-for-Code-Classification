const nodes=require('fs').readFileSync('/dev/stdin','utf8').trim().split(',');
let slots=1;
for(const n of nodes){if(slots===0){console.log('false');process.exit();}slots--;if(n!=='#')slots+=2;}
console.log(slots===0?'true':'false');
