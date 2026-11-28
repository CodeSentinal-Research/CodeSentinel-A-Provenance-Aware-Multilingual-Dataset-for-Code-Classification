function generateAllPaths(N, M) {
    if (N === 1 && M === 1) {
        console.log('[1,1]');
        return;
    }
    const paths = generateAllPathsRecursive(N, M, 1, 1, []);
    paths.sort((a, b) => a.join(',') < b.join(',') ? -1 : 1);
    console.log(paths);
}

function generateAllPathsRecursive(N, M, x, y, path) {
    path.push(x, y);
    if (N === x && M === y) {
        return [path];
    } else if (N === x) {
        return generateAllPathsRecursive(N, M, x, y + 1, path);
    } else if (M === y) {
        return generateAllPathsRecursive(N, M, x + 1, y, path);
    } else {
        return [...generateAllPathsRecursive(N, M, x, y + 1, path), ...generateAllPathsRecursive(N, M, x + 1, y, path)].filter(path => 
            path.every((val, i, arr) => i > 0 && arr[i - 1] !== val)
        );
    }
}
This JavaScript code first defines a function generateAllPaths to take in the two parameters N and M, which are the dimensions of the grid. If N and M are both 1, it prints [1,1] and returns.

Then, it calls the generateAllPathsRecursive function, which is a recursive function that takes four parameters: the dimensions of the grid, the current x and y coordinates, and the current path. The path is initialized as an empty array.

The function then checks if we're at the bottom right corner of the grid. If so, it returns the path. If not, it then checks if we're at the rightmost edge of the grid and if so, it recurses to the bottom row. If not, it recurses to the rightmost column and the next row. If not, it recurses horizontally and vertically until it reaches the bottom right corner.

The results are sorted in lexicographical order and then printed out. The use of recursion in this case allows for efficient generation of all paths, as it avoids the overhead of nested loops.