let n=+require('fs').readFileSync('/dev/stdin','utf8').trim();let res='';while(n){n--;res=String.fromCharCode(65+n%26)+res;n=Math.floor(n/26);}console.log(res);
