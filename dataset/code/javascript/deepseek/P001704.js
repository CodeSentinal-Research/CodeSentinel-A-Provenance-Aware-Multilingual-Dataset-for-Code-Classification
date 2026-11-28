Here is the JavaScript code to solve the problem:

function readTree() {
    let n = readline();
    let children = [];
    for(let i = 0; i < n; i++) {
        children.push(readline().split(' '));
    }
    return children;
}

function isIsomorphic(t1, t2) {
    if(t1.length !== t2.length) return false;
    if(t1.length === 0) return true;
    let map1 = {}, map2 = {};
    for(let i = 0; i < t1.length; i++) {
        if(!map1[t1[i][0]] && !map2[t2[i][1]]) {
            map1[t1[i][0]] = t2[i][1];
            map2[t2[i][1]] = t1[i][0];
        } else if(map1[t1[i][0]] !== t2[i][1] || map2[t2[i][1]] !== t1[i][0]) {
            return false;
        }
    }
    return true;
}

let t1 = readTree();
let t2 = readTree();

if(isIsomorphic(t1, t2)) {
    print('YES');
} else {
    print('NO');
}

This code reads in two trees and checks if they are isomorphic. The `readline()` function reads a line from the input, and the `split(' ')` function splits the line into an array of strings. The `print()` function is used to print the result.

Please note that this code assumes that the input is a tree represented as a list of children. Each child is a pair of parent-child values.