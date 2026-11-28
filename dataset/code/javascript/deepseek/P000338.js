function checkEquivalentArrays(arr1, arr2) {
    if (arr1.length !== arr2.length) {
        console.log("No");
        return;
    }
    
    let map1 = new Map(), map2 = new Map();

    for (let i = 0; i < arr1.length; i++) {
        if (!map1.has(arr1[i])) map1.set(arr1[i], 1);
        else map1.set(arr1[i], map1.get(arr1[i]) + 1);

        if (!map2.has(arr2[i])) map2.set(arr2[i], 1);
        else map2.set(arr2[i], map2.get(arr2[i]) + 1);
    }

    for (let key of map1.keys()) {
        if (!map2.has(key) || map2.get(key) !== map1.get(key)) {
            console.log("No");
            return;
        }
    }

    console.log("Yes");
}