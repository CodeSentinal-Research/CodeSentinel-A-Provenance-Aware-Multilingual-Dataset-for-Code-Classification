Here is the JavaScript code to solve the problem. It uses the concept of recursion to flatten the nested list.

class NestedInteger {
  constructor(value) {
    this.value = value;
    this.list = value instanceof Array ? value : [];
  }

  isInteger() {
    return true;
  }

  getList() {
    return this.list;
  }
}

class NestedIterator {
  constructor(nestedList) {
    this.flatList = [];
    this.flatten(nestedList);
    this.index = 0;
  }

  flatten(list) {
    for(let i = 0; i < list.length; i++) {
      if(list[i].isInteger()) {
        this.flatList.push(list[i].getInteger());
      } else {
        this.flatten(list[i].getList());
      }
    }
  }

  next() {
    if (this.flatList[this.index]) {
      return this.flatList[this.index++];
    }
    return null;
  }

  hasNext() {
    return this.index < this.flatList.length;
  }
}

To use the above code, we can use it as follows:

let nestedList = [1,[2,[3,[4,[5]]]],6,[7,[8,[9,[10]]]]];
let iterator = new NestedIterator(nestedList);

while (iterator.hasNext()) {
  console.log(iterator.next());
}

This code will iterate through the entire list and print each integer in turn. If there are no more integers, it will print null.