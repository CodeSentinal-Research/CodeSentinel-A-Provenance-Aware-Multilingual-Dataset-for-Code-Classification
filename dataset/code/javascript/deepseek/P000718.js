Here is a JavaScript solution for the given problem. 

function grayCode(n) {
    if(n === 0){
        return ['0'];
    }
    if(n === 1){
        return ['0', '1'];
    }

    let prev = grayCode(n-1);
    let curr = [];

    for(let i = 0; i < prev.length; i++){
        curr.push(prev[i]);
    }

    for(let i = 0; i < prev.length; i++){
        let padded = prev[i].padStart(n-1, '0') + '1';
        curr.push(padded);
    }

    return curr;
}

console.log(grayCode(3));

This code will generate the 2^n-1 Gray codes for n bits. The recursive function `grayCode` generates all Gray codes for n bits. It starts by checking for base cases where n is 0 or 1, in which case it simply returns a list with a single string. For larger inputs, it recursively generates all Gray codes for n-1 bits, pushes the result onto the current list, pads the current list with zeros to match the number of bits, and appends '1' to each element in the current list. Finally, it returns the current list.

You can run this code in a JavaScript environment.