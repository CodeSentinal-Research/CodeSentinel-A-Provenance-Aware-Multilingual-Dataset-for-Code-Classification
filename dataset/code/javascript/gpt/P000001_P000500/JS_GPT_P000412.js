// Case-Insensitive Contact Search
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let name = String((q["name"] !== undefined ? q["name"] : (q["query"] !== undefined ? q["query"] : ""))).toLowerCase();
for (const r of records) {
    if (String((r["name"] !== undefined ? r["name"] : "")).toLowerCase() === name) {
        out.push(r);
    }
}
console.log(JSON.stringify(out));
