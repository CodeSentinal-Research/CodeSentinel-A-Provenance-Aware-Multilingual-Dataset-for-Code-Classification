const lines=require('fs').readFileSync('/dev/stdin','utf8').trim().split('\n');
const n=parseInt(lines[0]);
const nums=[...new Set(lines[1].trim().split(' ').map(Number))].sort((a,b)=>a-b);
console.log(nums.length>=3?nums[nums.length-3]:nums[nums.length-1]);
