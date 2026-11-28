Here is the JavaScript code using JavaScript objects to implement the All One Data Structure. 

class AllOne {
    constructor() {
        this.count = {};
        this.keys = {};
    }

    inc(key) {
        if (this.count[key]) {
            this.dec(key);
        }
        this.count[key] = (this.count[key] || 0) + 1;
        this.keys[this.count[key]].push(key);
    }

    dec(key) {
        if (this.count[key] === 1) {
            delete this.count[key];
            delete this.keys[1][key];
            if (Object.keys(this.keys[1]).length === 0) {
                delete this.keys[1];
            }
        } else {
            this.count[key]--;
            this.keys[this.count[key] + 1].push(key);
        }
    }

    getMaxKey() {
        return this.keys[Math.max(...Object.keys(this.count))].pop();
    }

    getMinKey() {
        return this.keys[Math.min(...Object.keys(this.count))].pop();
    }
}

// Test the code
let allOne = new AllOne();

function processQueries(queries) {
    queries.forEach((query) => {
        let [operation, key] = query.split(' ');
        switch (operation) {
            case 'inc':
                allOne.inc(key);
                break;
            case 'dec':
                allOne.dec(key);
                break;
            case 'getMaxKey':
                console.log(allOne.getMaxKey());
                break;
            case 'getMinKey':
                console.log(allOne.getMinKey());
                break;
        }
    });
}

// Test the function with an array of queries
processQueries(['inc a', 'inc b', 'inc c', 'dec b', 'dec a', 'dec a', 'getMaxKey', 'getMinKey']);

This code first defines a class AllOne with methods for incrementing and decrementing a key's count and retrieving the key with the maximum and minimum count. Then, a test is provided with an array of queries.

Please note, this is a basic implementation and may need to be enhanced based on your specific use-case.