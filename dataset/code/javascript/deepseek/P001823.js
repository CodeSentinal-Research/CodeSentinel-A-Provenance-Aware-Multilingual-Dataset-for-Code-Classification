function solve() {
  let N = parseInt(readline());
  let postorder = readline().split(' ').map(Number);
  
  function isValidBST(array) {
    if (array.length <= 2) {
      if (array.length === 1) {
        return true;
      } else {
        return Math.abs(array[0] - array[1]) <= 1;
      }
    }
    
    let root = array[array.length - 1];
    let leftHalf = array.slice(0, array.length - 1).filter(num => num < root);
    let rightHalf = array.slice(0, array.length - 1).filter(num => num > root);
    
    return isValidBST(leftHalf) && isValidBST(rightHalf) && Math.abs(leftHalf[leftHalf.length - 1] - root) <= 1;
  }
  
  console.log(isValidBST(postorder) ? 'YES' : 'NO');
}