const s=require('fs').readFileSync('/dev/stdin','utf8').trim();console.log(s?s.split(/\s+/).length:0);
