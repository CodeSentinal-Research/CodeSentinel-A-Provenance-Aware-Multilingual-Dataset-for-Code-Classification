const[a,b]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');console.log(a===b?-1:Math.max(a.length,b.length));
