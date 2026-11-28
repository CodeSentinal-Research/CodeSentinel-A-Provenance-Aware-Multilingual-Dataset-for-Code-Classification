function capitalizeFirstLetter(str) {
  return str.split(' ').map(function(word) {
    return word.charAt(0).toUpperCase() + word.substring(1);
  }).join(' ');
}

var S = prompt("Enter a string:");
var result = capitalizeFirstLetter(S);
console.log(result);