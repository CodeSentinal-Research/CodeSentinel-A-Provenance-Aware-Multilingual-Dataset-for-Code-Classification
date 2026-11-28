const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const nums=lines[1].trim().split(' ').map(Number);
const freq={};
let bestVal=nums[0],bestCnt=0;
for(const x of nums){freq[x]=(freq[x]||0)+1;if(freq[x]>bestCnt){bestCnt=freq[x];bestVal=x;}}
console.log(bestVal);
