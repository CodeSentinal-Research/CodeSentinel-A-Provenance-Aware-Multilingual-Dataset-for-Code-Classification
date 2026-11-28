Here is the JavaScript code for the problem:

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class TextEditor {
    constructor() {
        this.head = new Node(null);
        this.current = this.head;
    }

    addText(text) {
        let newNode = new Node(text);
        newNode.next = this.current.next;
        this.current.next = newNode;
        this.current = this.current.next;
    }

    deleteText(k) {
        let temp = this.head;
        while(k-- > 0 && temp.next !== null){
            temp = temp.next;
        }
        if(k>0 && temp.next !== null){
            temp.next = temp.next.next;
        }
    }

    cursorLeft(k) {
        while(k-- > 0 && this.current !== this.head) {
            this.current = this.current.next;
        }
        return this.getLastTen();
    }

    cursorRight(k) {
        while(k-- > 0 && this.current.next !== null) {
            this.current = this.current.next;
        }
        return this.getLastTen();
    }

    getLastTen() {
        let temp = this.head;
        let result = '';
        while(temp.next !== null && temp.next !== this.current && result.length < 10) {
            temp = temp.next;
            result += temp.data;
        }
        return result;
    }
}

function processOperations(q, operations) {
    let editor = new TextEditor();
    for(let operation of operations){
        if(operation[0] === 1){
            editor.addText(operation[1]);
        }
        else if(operation[0] === 2){
            editor.deleteText(operation[1]);
        }
        else if(operation[0] === 3){
            console.log(editor.cursorLeft(operation[1]));
        }
        else if(operation[0] === 4){
            console.log(editor.cursorRight(operation[1]));
        }
    }
}

To use this code, create an array of operations where each operation is an array of two elements. The first element in the operation is a number indicating the type of operation (1 for addText, 2 for deleteText, 3 for cursorLeft, and 4 for cursorRight), and the second element is the text or k value depending on the operation. For example:

let operations = [[1, 'Hello'], [1, ' World'], [3, 2], [4, 3]];
processOperations(4, operations);