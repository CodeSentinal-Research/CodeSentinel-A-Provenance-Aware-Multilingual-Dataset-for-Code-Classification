const s=require("fs").readFileSync("/dev/stdin","utf8").trim().toLowerCase();const v="aeiou";let cnt=0;for(const c of s)if(/[a-z]/.test(c)&&!v.includes(c))cnt++;console.log(cnt);
