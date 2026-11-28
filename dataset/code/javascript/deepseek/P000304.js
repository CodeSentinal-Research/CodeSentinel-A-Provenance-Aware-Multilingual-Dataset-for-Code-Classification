Here is the JavaScript code to solve the problem:

function simplifyPath(path) {
    const stack = [];
    const parts = path.split('/');

    for(let part of parts) {
        if (part === '..') {
            if (stack.length > 0) {
                stack.pop();
            }
        } else if (part === '.' || part === '') {
            continue;
        } else {
            stack.push(part);
        }
    }

    return '/' + stack.join('/');
}

This code works by iterating over each part of the input path. If the part is '..', it pops the last part from the stack (which is a directory up). If the part is '.', or is an empty string, it just ignores it. Otherwise, it pushes the part to the stack. Finally, it joins the parts of the stack into a single path string.

You can use this function like this:

console.log(simplifyPath("/home/")); // "/home"
console.log(simplifyPath("/../home/")); // "/home"
console.log(simplifyPath("/home/user")); // "/home/user"
console.log(simplifyPath("/a/b/c/d/../e")); // "/e"