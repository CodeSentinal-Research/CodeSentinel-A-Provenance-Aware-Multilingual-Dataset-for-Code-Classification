const s=require('fs').readFileSync('/dev/stdin','utf8').trim();let r='';for(let i=0;i<s.length;i++)r+=i%2===0?s[i]:String.fromCharCode(s.charCodeAt(i-1)+parseInt(s[i]));console.log(r);
