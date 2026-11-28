Here's a simple solution using JavaScript's built-in data structure, Map, and object. We use Map to store the history for each window. This data structure will allow for efficient insertion, removal, and retrieval of the browsing history. 

This solution has a time complexity of O(1) for all operations (insert, delete, and access), which is the best time complexity we can achieve for this problem.

class BrowserHistory {
    constructor() {
        this.windows = new Map();
        this.pointer = -1;
    }

    visit(windowId, url) {
        if (!this.windows.has(windowId)) {
            this.windows.set(windowId, []);
        }
        this.pointer++;
        this.windows.get(windowId)[this.pointer] = url;
    }

    back(windowId, steps) {
        this.pointer = Math.max(this.pointer - steps, 0);
    }

    forward(windowId, steps) {
        this.pointer = Math.min(this.pointer + steps, this.windows.get(windowId).length - 1);
    }

    newWindow(homepage) {
        this.windows.set(this.windows.size, [homepage]);
        this.pointer = this.windows.size - 1;
    }

    closeWindow(windowId) {
        this.windows.delete(windowId);
    }

    currentPage(windowId) {
        if (this.windows.has(windowId)) {
            return this.windows.get(windowId)[this.pointer];
        }
        return null;
    }
}

The code above implements the BrowserHistory class with a constructor that initializes an empty Map, and two methods to handle visiting a URL, moving backwards and forwards in the browsing history, creating a new window, and closing an existing window. 

The currentPage method can be used to get the current URL in a specific window.

To use this class:

let browser = new BrowserHistory();
browser.visit(0, 'example1.com');
browser.visit(0, 'example2.com');
browser.visit(0, 'example3.com');
console.log(browser.currentPage(0)); // example3.com
browser.back(0, 1);
console.log(browser.currentPage(0)); // example2.com
browser.forward(0, 1);
console.log(browser.currentPage(0)); // example3.com
browser.newWindow('home.com');
console.log(browser.currentPage(browser.windows.size)); // home.com
browser.closeWindow(browser.windows.size - 1);

This is a very basic example and doesn't include error checking or input validation. In a real application, you'd want to add more robust error checking and input validation.