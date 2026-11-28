process.stdin.on('data', function(data) {
    var input = data.toString().split('\n');
    var N = parseInt(input[0]);
    var arr1 = input[1].split(' ').map(Number);
    var M = parseInt(input[2]);
    var arr2 = input[3].split(' ').map(Number);
    
    // Sorting the arrays
    arr1.sort(function(a, b){return a - b});
    arr2.sort(function(a, b){return a - b});
    
    if(N != M){
        console.log('NO');
    }
    else{
        for(let i = 0; i < N; i++){
            if(arr1[i] != arr2[i]){
                console.log('NO');
                return;
            }
        }
        console.log('YES');
    }
});