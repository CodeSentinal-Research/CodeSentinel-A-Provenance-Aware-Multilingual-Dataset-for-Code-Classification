const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        
        function mergeSort(arr, l, r) {
            if(l>=r) return;
            let m = Math.floor((l+r)/2);
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
        function merge(arr, l, m, r) {
            let n1 = m-l+1, n2 = r-m;
            let L = arr.slice(l, m+1), R = arr.slice(m+1, r+1);
            let i=0, j=0, k=l;
            while(i<n1 && j<n2) {
                if(L[i]<=R[j]) arr[k++]=L[i++];
                else arr[k++]=R[j++];
            }
            while(i<n1) arr[k++]=L[i++];
            while(j<n2) arr[k++]=R[j++];
        }
        mergeSort(arr, 0, n-1);
        console.log(arr.join(" "));
        rl.close();
    }
});
