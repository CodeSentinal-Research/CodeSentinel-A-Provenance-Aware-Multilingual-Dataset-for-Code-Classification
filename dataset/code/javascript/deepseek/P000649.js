function compareLists(first, second) {
  if (first === null || second === null) {
    return first === second;
  }

  let nodeA = first;
  let nodeB = second;

  while (nodeA !== null && nodeB !== null) {
    if (nodeA.value !== nodeB.value) {
      return false;
    }
    nodeA = nodeA.next;
    nodeB = nodeB.next;
  }

  return nodeA === null && nodeB === null;
}