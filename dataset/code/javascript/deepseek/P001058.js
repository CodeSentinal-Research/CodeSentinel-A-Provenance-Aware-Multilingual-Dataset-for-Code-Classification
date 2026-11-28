Here is the JavaScript code for the Frequency Stack problem:

class FreqStack {
    constructor() {
        this.freq = new Map();
        this.group = new Map();
        this.maxfreq = 0;
    }

    push(x) {
        this.freq.set(x, (this.freq.get(x) || 0) + 1);
        this.group.set(this.freq.get(x), (this.group.get(this.freq.get(x)) || new Set()).add(x);
        this.maxfreq = Math.max(this.maxfreq, this.freq.get(x));
    }

    pop() {
        let x = this.group.get(this.maxfreq).values().next().value;
        this.freq.set(x, this.freq.get(x) - 1);
        if (!this.group.get(this.maxfreq).values().next().done) {
            this.maxfreq = Math.max(...this.freq.values());
        }
        return x;
    }
}

This code creates a class `FreqStack` which holds a `map` `freq` where the keys are the elements and the values are their frequencies. Another `map` `group` is used to store elements grouped by their frequency. The `maxfreq` variable keeps track of the maximum frequency found so far.

The `push` method updates the frequency map and group map, and updates the `maxfreq` if needed.

The `pop` method removes and returns the most frequently occurring element from the group map. It also updates the frequency map if the pop operation removed the last element from the frequency map.