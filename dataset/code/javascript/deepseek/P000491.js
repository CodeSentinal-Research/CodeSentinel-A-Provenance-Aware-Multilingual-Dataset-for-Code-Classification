function buildArray(m, n) {
    var target = [];
    var operations = [];
    for(var i = 1; i <= n; i++){
        target.push('Push');
        if(i < m){
            target.push('Pop');
        }
    }
    return target;
}
This function buildArray accepts two parameters m and n. It initializes an empty array target and an empty array operations. Then, for each number i from 1 to n, it pushes the string 'Push' into target array and if i is less than m, it pushes 'Pop' into target array. Finally, it returns the target array.