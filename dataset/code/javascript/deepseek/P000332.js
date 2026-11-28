Here is the JavaScript code for the given problem:

function customSortString(order, S) {
    var orderMap = new Map();
    for (var i = 0; i < order.length; i++) {
        orderMap.set(order[i], i);
    }

    var arr = S.split('').sort(function(a, b) {
        return orderMap.get(a) - orderMap.get(b);
    });

    return arr.join('');
}
This function works by first constructing a map (orderMap) where each character in the order string is a key and its index in the order string is the corresponding value. 

Then, the input string (S) is split into an array of characters (arr), and the sort function is used to sort the array based on the values in the orderMap. The sort function uses a comparator function that retrieves the correct index from the orderMap for each character in the array.

Finally, the sorted array is joined back into a string and returned. This will give the permuted string as output.