const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of matrices: ', (n) => {
  rl.question('Enter dimensions: ', (dims) => {
    const d = dims.split(' ').map(Number);
    const m = [];
    for(let i=0; i<=n; i++) {
      m[i] = [];
      for(let j=0; j<=n; j++) {
        m[i][j] = 0;
      }
    }
    for(let len=1; len<=n; len++) {
      for(let i=0; i<=n-len; i++) {
        const j = i+len;
        m[i][j] = Infinity;
        for(let k=i; k<j; k++) {
          m[i][j] = Math.min(m[i][j], m[i][k] + m[k+1][j] * d[i] * d[j]);
        }
      }
    }
    console.log(m[0][n]);
    rl.close();
  });
});