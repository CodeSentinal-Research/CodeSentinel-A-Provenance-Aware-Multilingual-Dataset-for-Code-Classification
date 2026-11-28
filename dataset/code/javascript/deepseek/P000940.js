Here is the JavaScript code for the problem:

function misereNim(N, piles) {
    if (N == 1) {
        console.log("First");
    } else {
        console.log("Second");
    }
}

let N = parseInt(prompt("Enter the number of piles: "));
let piles = [];
for (let i = 0; i < N; i++) {
    let pile = parseInt(prompt(`Enter the number of stones in pile ${i + 1}: `));
    piles.push(pile);
}
misereNim(N, piles);

In this code, we are first defining the function `misereNim` that takes two parameters - `N` and `piles`. We then check if `N` is 1, if it is we print "First", otherwise we print "Second".

Next, we get the number of piles from the user and then for each pile, we get the number of stones in it. We push these numbers into an array `piles`.

Finally, we call the `misereNim` function with `N` and `piles` as parameters.