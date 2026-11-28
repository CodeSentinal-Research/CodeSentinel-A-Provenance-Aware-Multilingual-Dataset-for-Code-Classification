class CombinationIterator {
    constructor(characters, combinationLength) {
        this.combinations = [];
        this.idx = 0;

        const backtrack = (start, cur) => {
            if (cur.length === combinationLength) {
                this.combinations.push(cur);
                return;
            }
            for (let i = start; i < characters.length; i++) {
                backtrack(i + 1, cur + characters[i]);
            }
        };

        backtrack(0, "");
    }

    next() {
        return this.combinations[this.idx++];
    }

    hasNext() {
        return this.idx < this.combinations.length;
    }
}

module.exports = { CombinationIterator };