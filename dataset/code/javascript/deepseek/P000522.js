Here is a simple implementation using JavaScript:

class BrowserHistory {
  constructor() {
    this.historyStack = [0];
    this.forwardStack = [];
    this.currentPage = 0;
  }

  visit(url) {
    this.historyStack.push(url);
    this.currentPage = url;
    console.log(this.currentPage);
  }

  back(steps) {
    for (let i = 0; i < steps; i++) {
      if (this.historyStack.length > 1) {
        this.forwardStack.push(this.historyStack.pop());
      }
    }
    this.currentPage = this.historyStack.pop();
    console.log(this.currentPage);
  }

  forward(steps) {
    for (let i = 0; i < steps; i++) {
      if (this.forwardStack.length > 0) {
        this.historyStack.push(this.forwardStack.pop());
      }
    }
    this.currentPage = this.historyStack.pop();
    console.log(this.currentPage);
  }
}

let browserHistory = new BrowserHistory();

let operations = [
  ['www.google.com'],
  [1],
  ['www.stackoverflow.com'],
  [1],
  ['www.github.com'],
  [1],
  [2]
];

for (let i = 0; i < operations.length; i++) {
  let operation = operations[i];
  if (operation[0] === 'visit') {
    browserHistory.visit(operation[1]);
  } else if (operation[0] === 'back') {
    browserHistory.back(operation[1]);
  } else if (operation[0] === 'forward') {
    browserHistory.forward(operation[1]);
  }
}

This script creates a browser history manager that supports the specified operations. The browser history is implemented using two stacks: a history stack for browsing history, and a forward stack for forwarding history.

The visit(url) operation adds a new page to the history stack, and sets the current page to that url.

The back(steps) operation moves back by at most steps pages from the history stack to the forward stack. If there are not enough steps to move back, it just moves the current page to the history stack.

The forward(steps) operation moves forward by at most steps pages from the forward stack to the history stack. If there are not enough steps to move forward, it just moves the current page to the history stack.

The main part of the script creates a browser history manager, and then processes a sequence of operations. It prints the current page after every back() and forward() operation.