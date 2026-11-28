function reorganizeString(str) {
  // Create a frequency map
  let freqMap = {};
  for (let char of str) {
    freqMap[char] = (freqMap[char] || 0) + 1;
  }

  // Create a priority queue based on character frequencies
  let pq = new PriorityQueue((a, b) => freqMap[b] - freqMap[a]);
  for (let char in freqMap) {
    pq.push(char);
  }

  // Create a string builder
  let sb = new StringBuilder();

  // Continue until the priority queue is empty
  while (!pq.isEmpty()) {
    // Get the highest frequency character
    let maxChar = pq.poll();

    // Append the character to the string builder
    sb.append(maxChar);

    // Decrease the frequency of the character
    freqMap[maxChar]--;

    // If the frequency is 0, remove the character from the priority queue
    if (freqMap[maxChar] === 0) {
      pq.remove(maxChar);
    } else {
      // If the frequency is not 0, add the character back to the priority queue
      pq.push(maxChar);
    }
  }

  // Return the final string
  return sb.toString();
}

class PriorityQueue {
  constructor(comparator) {
    this.list = [];
    this.comparator = comparator;
  }

  push(element) {
    this.list.push(element);
    this.list.sort(this.comparator);
  }

  poll() {
    return this.list.shift();
  }

  remove(element) {
    let index = this.list.indexOf(element);
    if (index !== -1) {
      this.list.splice(index, 1);
    }
  }

  isEmpty() {
    return this.list.length === 0;
  }
}

class StringBuilder {
  constructor() {
    this.parts = [];
  }

  append(part) {
    this.parts.push(part);
  }

  toString() {
    return this.parts.join("");
  }
}