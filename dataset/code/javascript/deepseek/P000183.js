// JavaScript solution for count distinct elements in every window

// Reading inputs
var N = parseInt(readline());
var K = parseInt(readline());
var arr = readline().split(' ').map(Number);

// Function to calculate the count of distinct elements in a window
function countDistinct(window) {
    return new Set(window).size;
}

// Function to process all windows of size K
function processAllWindows() {
    for(let i = 0; i <= N - K; i++) {
        let window = arr.slice(i, i + K);
        console.log(countDistinct(window));
    }
}

// Processing all windows
processAllWindows();