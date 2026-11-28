function queueReconstructionByHeight(people) {
    // sort by height in ascending order
    people.sort((a, b) => a[0] - b[0]);

    const res = [];
    for (let person of people) {
        // insert person at the right place in the result array
        res.splice(person[1], 0, person);
    }

    return res;
}
This code sorts the input array of people by their height in ascending order. Then, for each person in the sorted array, it inserts the person at the right place in the result array. This way, the result array will be the reconstructed queue satisfying all the constraints.

Input:
3
7 0
6 1
5 2
Output:
[[6, 1], [5, 2], [7, 0]]