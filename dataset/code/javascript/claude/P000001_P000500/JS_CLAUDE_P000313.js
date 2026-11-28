const s=require('fs').readFileSync('/dev/stdin','utf8').trim();
console.log(!isNaN(parseFloat(s))&&isFinite(s)?'Yes':'No');
