// Search Books by Author and Genre
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let author = String((q["author"] !== undefined ? q["author"] : ""));
let genre = String((q["genre"] !== undefined ? q["genre"] : ""));
for (const r of records) {
    if ((String((r["author"] !== undefined ? r["author"] : "")) === author && String((r["genre"] !== undefined ? r["genre"] : "")) === genre)) {
        out.push(r);
    }
}
console.log(JSON.stringify(out));
