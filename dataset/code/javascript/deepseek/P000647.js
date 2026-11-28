Here's the JavaScript code for the problem.

class Node {
    constructor(data, prev = null, next = null) {
        this.data = data;
        this.prev = prev;
        this.next = next;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    addSong(data) {
        const node = new Node(data);
        if (this.head) {
            node.next = this.head;
            this.head.prev = node;
            this.head = node;
        } else {
            this.head = node;
            this.tail = node;
        }
        this.size++;
    }

    removeSong(data) {
        let current = this.head;
        while (current) {
            if (current.data === data) {
                if (current.prev) current.prev.next = current.next;
                if (current.next) current.next.prev = current.prev;
                if (current === this.head) this.head = current.next;
                if (current === this.tail) this.tail = current.prev;
                this.size--;
                return;
            }
            current = current.next;
        }
    }

    playNext() {
        if (!this.head) return "Playlist is empty";
        let current = this.head.next;
        console.log(current.data);
        this.head.next = current.next;
        if (current.next) current.next.prev = this.head;
        if (this.head.next) this.head.next.prev = null;
        this.head = current;
    }

    playPrevious() {
        if (!this.head) return "Playlist is empty";
        let current = this.tail;
        while (current) {
            if (current.data === this.tail.data) break;
            current = current.prev;
        }
        if (!current) return "Playlist is empty";
        console.log(current.data);
        this.tail = current;
        if (this.tail.prev) this.tail.prev.next = null;
        this.tail.next = null;
        this.head = this.tail;
    }

    currentSong() {
        if (!this.head) return "Playlist is empty";
        console.log(this.head.data);
    }
}

function processOperations(q, operations) {
    let playlist = new DoublyLinkedList();

    operations.forEach((operation) => {
        const [type, data] = operation;
        if (type === 'addSong') {
            playlist.addSong(data);
        } else if (type === 'removeSong') {
            playlist.removeSong(data);
        } else if (type === 'playNext') {
            playlist.playNext();
        } else if (type === 'playPrevious') {
            playlist.playPrevious();
        } else if (type === 'currentSong') {
            playlist.currentSong();
        }
    });
}

processOperations(q, operations);

In this code, `processOperations` function is responsible for processing the operations and printing the result for every operation. We use a doubly linked list to manage the songs in the playlist. The list keeps track of the current song in the playlist. Each operation is processed separately and the result is printed.