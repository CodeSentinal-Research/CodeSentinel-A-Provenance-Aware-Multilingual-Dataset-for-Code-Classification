Sure, here is the JavaScript code for the zigzag conversion problem.

function zigzagConversion(S, numRows) {
  if (numRows === 1) return S;

  const length = S.length;
  const cycle = numRows * 2 - 2; // the total possible cycle
  const ret = [];
  for (let i = 0; i < length; i += cycle) {
    ret.push(S[i]);
    if (i + numRows < length) ret.push(S[i + numRows]);
    if (i + numRows * 2 < length) ret.push(S[i + numRows * 2]);
  }
  return ret.join("");
}

You can use this function by passing the string `S` and the number of rows `numRows` as parameters. For example, you can call `zigzagConversion('PAYPALISHIRING', 3)` to get 'PAHNAPLSIIGTR' as the result.