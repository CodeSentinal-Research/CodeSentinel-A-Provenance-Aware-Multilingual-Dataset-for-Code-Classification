function visiblePeople(n, heights) {
    let maxHeight = Math.max(...heights);
    let visible = new Array(n).fill(0);
    let maxRight = 0;

    for(let i=0; i<n; i++){
        if(i === maxRight){
            visible[i] = 1;
            maxRight++;
            while(maxRight<n && heights[maxRight] >= heights[i]){
                visible[i]++;
                maxRight++;
            }
        }else{
            visible[i] = 0;
        }
    }

    return visible;
}

// Test the function
console.log(visiblePeople(5, [3, 6, 3, 4, 3])); // [1, 3, 2, 1, 1]