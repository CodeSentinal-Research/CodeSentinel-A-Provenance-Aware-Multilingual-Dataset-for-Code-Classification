const[s1,s2]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');const a=new Set(s1),b=new Set(s2);console.log(a.size===b.size&&[...a].every(c=>b.has(c))?'Yes':'No');
