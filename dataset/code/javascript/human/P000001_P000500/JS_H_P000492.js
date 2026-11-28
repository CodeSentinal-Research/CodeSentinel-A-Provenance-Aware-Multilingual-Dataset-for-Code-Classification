// Question 10: Simplify path
// You are given an absolute Unix-style file path and need to simplify it.
// The rules are:
// A single . means stay in the current directory → ignore it.
// A double .. means go back one directory → remove the previous directory.
// Multiple consecutive / characters should be treated as a single /.
// Any sequence of dots that isn't exactly . or .. is treated as a normal directory name.
// The returned path must:
// Start with /
// Have exactly one / between directory names
// Not end with / unless the path is simply /

// Example 1
// Input:
// "/home/"
// Output:
// "/home"
// Because the trailing / is unnecessary.

// Example 2
// Input:
// "/home//foo/"
// Output:
// "/home/foo"
// Multiple / are treated as one.

// Example 3
// Input:
// "/home/user/../documents"
// Output:
// "/home/documents"
// Because:
// /home/user
//        ↑
//       ..
// means go back from user to home.

// Example 4
// Input:
// "/a/./b/../../c/"
// Output:
// "/c"
// Let's break it down:
// /a
// /a/./b       → "." ignored
// /a/b/..      → remove b
// /a/../c      → remove a
// /c

// Example 5
// Input:
// "/../"
// Output:
// "/"
// You cannot go above the root directory.

// Example 6
// Input:
// "/a//b////c/d//././/.."
// Output:
// "/a/b/c"

const simplifyPath = (complexPath) => {
    const pathStack = [];
    let directoryName = "";
    const finalPath = complexPath.trim().split("/");

    for (let i = 0; i < finalPath.length; i++) {
        const path = finalPath[i];

        if (path === "..") {
            pathStack.pop();
        } else if (path === "." || path === "//" || !path) {
            continue;
        } else {
            pathStack.push(path);
        }
    }

    if (pathStack.length === 0) {
        return "/";
    }
    for (const path of pathStack) {
        directoryName += "/" + path;
    }

    return directoryName;
}

// Example usage:
console.log(simplifyPath("/home/"));
console.log(simplifyPath("/home//foo/"));
console.log(simplifyPath("/home/user/../documents"));
console.log(simplifyPath("/a/./b/../../c/"));
console.log(simplifyPath("/../"));
console.log(simplifyPath("/a//b////c/d//././/.."));

// Output:
// "/home"
// "/home/foo"
// "/home/documents"
// "/c"
// "/"
// "/a/b/c"