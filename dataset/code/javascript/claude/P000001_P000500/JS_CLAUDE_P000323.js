const s=require('fs').readFileSync('/dev/stdin','utf8').trim();console.log(s.split('A').length-1<=1&&!s.includes('LLL')?'Yes':'No');
