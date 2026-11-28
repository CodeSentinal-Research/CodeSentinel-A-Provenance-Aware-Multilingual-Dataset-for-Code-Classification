// Search Duplicate Email Addresses
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let counts = Counter([...records].map(r => String((r["email"] !== undefined ? r["email"] : ""))));
console.log(JSON.stringify([...[...Object.entries(counts)].filter(([e, c]) => c > 1).map(([e, c]) => e)].sort((a, b) => a < b ? -1 : a > b ? 1 : 0)));
sys.exit();
console.log(JSON.stringify(out));
