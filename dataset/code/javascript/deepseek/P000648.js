Here is a simple implementation of the Undo Redo Editor using JavaScript. We will use a linked list to implement the history mechanism. 

class Node {
    constructor(text) {
        this.text = text;
        this.next = null;
    }
}

class History {
    constructor() {
        this.current = null;
        this.undoStack = new Node("");
        this.redoStack = new Node("");
    }

    append(text) {
        const node = new Node(text);
        node.next = this.current;
        this.current = node;
        this.undoStack.next = this.undoStack;
        this.redoStack.next = this.redoStack;
    }

    undo() {
        if (this.current !== null) {
            this.redoStack.next = this.redoStack.next.next;
            this.redoStack = this.redoStack.next;
            const text = this.current.next.text;
            console.log("Undo operation: ", text);
            return text;
        }
        return null;
    }

    redo() {
        if (this.redoStack.next !== null) {
            this.current = this.current.next;
            const text = this.redoStack.next.text;
            console.log("Redo operation: ", text);
            return text;
        }
        return null;
    }
}

const history = new History();

function type(text) {
    history.append(text);
}

function undo() {
    return history.undo();
}

function redo() {
    return history.redo();
}

function print() {
    let current = history.current;
    while (current !== null) {
        console.log(current.text);
        current = current.next;
    }
}

type("Hello");
print();
undo();
type("World");
print();
redo();

This code creates a History class that uses a linked list to store the operations. The append function is used to add a new operation to the history. The undo and redo functions are used to undo and redo the most recent operation, respectively. The print function is used to print the current document.