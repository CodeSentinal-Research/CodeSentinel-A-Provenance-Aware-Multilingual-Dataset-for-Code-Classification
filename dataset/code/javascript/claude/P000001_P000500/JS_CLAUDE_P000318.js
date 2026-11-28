const[word,abbr]=require('fs').readFileSync('/dev/stdin','utf8').trim().split(' ');
let i=0,j=0,n=word.length,m=abbr.length;
while(i<n&&j<m){
    if(abbr[j]>='0'&&abbr[j]<='9'){
        if(abbr[j]==='0'){console.log('No');process.exit();}
        let num=0;while(j<m&&abbr[j]>='0'&&abbr[j]<='9')num=num*10+parseInt(abbr[j++]);i+=num;
    }else{if(word[i]!==abbr[j]){console.log('No');process.exit();}i++;j++;}
}
console.log(i===n&&j===m?'Yes':'No');
