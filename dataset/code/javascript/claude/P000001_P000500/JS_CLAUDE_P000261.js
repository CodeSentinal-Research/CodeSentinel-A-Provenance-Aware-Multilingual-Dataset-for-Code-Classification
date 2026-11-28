console.log([...require("fs").readFileSync("/dev/stdin","utf8").trim()].map(c=>c===c.toUpperCase()?c.toLowerCase():c.toUpperCase()).join(""));
