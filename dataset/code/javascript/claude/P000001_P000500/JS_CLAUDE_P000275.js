const s=require("fs").readFileSync("/dev/stdin","utf8").trim();let r="",i=0;while(i<s.length){let cnt=1;while(i+cnt<s.length&&s[i+cnt]===s[i])cnt++;r+=s[i]+(cnt>1?cnt:"");i+=cnt;}console.log(r);
