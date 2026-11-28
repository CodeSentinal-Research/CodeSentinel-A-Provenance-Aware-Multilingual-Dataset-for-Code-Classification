process.stdin.on('data', function(data) {
  var [pattern, sentence] = data.toString().split('\n');
  console.log(wordPattern(pattern, sentence));
});

function wordPattern(pattern, sentence) {
  var words = sentence.split(' ');
  for(var i = 0; i < pattern.length; i++) {
    if(pattern[i] == ' ') continue;
    if(words.indexOf(pattern[i]) != words.lastIndexOf(pattern[i])) {
      return 'NO';
    }
  }
  return 'YES';
}