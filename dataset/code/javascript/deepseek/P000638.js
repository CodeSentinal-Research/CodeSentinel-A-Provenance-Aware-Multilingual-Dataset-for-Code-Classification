class Node {
  constructor(coefficient, exponent) {
    this.coefficient = coefficient;
    this.exponent = exponent;
    this.next = null;
  }
}

class Polynomial {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  insert(coefficient, exponent) {
    let node = new Node(coefficient, exponent);
    if (this.head === null) {
      this.head = node;
      this.tail = node;
    } else {
      if (node.exponent === this.tail.exponent) {
        this.tail.coefficient += node.coefficient;
      } else {
        node.next = this.tail;
        this.tail = node;
     
        if (this.head.exponent > this.tail.exponent) {
          let temp = this.head;
          this.head = node;
          this.head.next = temp;
        }
      }
    }
  }

  delete(exponent) {
    let temp = this.head;
    let prev = null;
    while (temp !== null && temp.exponent !== exponent) {
      prev = temp;
      temp = temp.next;
    }
    if (temp === null) {
      console.log("No term with exponent " + exponent);
    } else if (temp === this.head) {
      this.head = temp.next;
      if (this.head === null) {
        this.tail = null;
      }
    } else if (temp === this.tail) {
      this.tail = prev;
      this.tail.next = null;
    } else {
      prev.next = temp.next;
    }
  }

  evaluate(x) {
    let temp = this.head;
    let result = 0;
    while (temp !== null) {
      result += temp.coefficient * Math.pow(x, temp.exponent);
      temp = temp.next;
    }
    console.log(result);
  }

  display() {
    let temp = this.head;
    while (temp !== null) {
      console.log(`Coefficient: ${temp.coefficient} Exponent: ${temp.exponent}`);
      temp = temp.next;
    }
  }
}

// To test the code
let poly = new Polynomial();
poly.insert(5, 3);
poly.insert(4, 2);
poly.insert(6, 1);
poly.insert(9, 0);
poly.display();
poly.evaluate(2);
poly.delete(2);
poly.display();
poly.evaluate(2);
poly.delete(3);
poly.display();
poly.evaluate(3);
poly.delete(1);
poly.display();
poly.evaluate(1);
poly.delete(0);
poly.display();
poly.evaluate(0);