function countConsonants(s) {
  const consonants = 'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ';
  let count = 0;
  for (let i = 0; i < s.length; i++) {
    if (consonants.indexOf(s[i]) !== -1) {
      count++;
    }
  }
  return count;
}