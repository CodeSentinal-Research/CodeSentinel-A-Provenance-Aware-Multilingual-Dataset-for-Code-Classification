const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of strings: ', (num) => {
  let strings = [];
  rl.setPrompt('Enter a string: ');

  rl.prompt();

  rl.on('line', (line) => {
    strings.push(line);
    if(strings.length === num) {
      const anagramGroups = groupAnagrams(strings);
      console.log(anagramGroups);
      rl.close();
    }
  });
});

function groupAnagrams(strings) {
  const map = new Map();

  for (let string of strings) {
    const sorted = string.split('').sort().join('');
    if (!map.has(sorted)) map.set(sorted, []);
    map.get(sorted).push(string);
  }

  return Array.from(map.values());
}

This program uses the `readline` module to read input from the command line. It then uses a map to group anagrams together. The map's keys are the sorted characters from each string, and the values are arrays of strings that have the same sorted characters.

The map is created in a way that it is as simple as possible: the keys are the sorted characters, the values are empty arrays initially. Then each string is sorted and its sorted character is used as a key to add the string to the corresponding value in the map. This ensures that all strings with the same sorted characters are grouped together.

Finally, the map's values are converted to an array and returned.