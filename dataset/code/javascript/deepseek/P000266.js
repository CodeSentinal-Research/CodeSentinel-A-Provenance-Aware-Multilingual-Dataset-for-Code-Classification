Here is the JavaScript code:

function removeAllOccurrences(S, C) {
    return S.split(C).join('');
}

In this code, we're using the `split()` method to split the string `S` at each occurrence of character `C` and then join them back into a string using `join('')`.