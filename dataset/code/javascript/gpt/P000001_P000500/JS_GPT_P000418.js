// Search Employees Joined Before a Given Date
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let d = String((q["date"] !== undefined ? q["date"] : ""));
for (const r of records) {
    if (String((r["joining_date"] !== undefined ? r["joining_date"] : "")) < d) {
        out.push(r);
    }
}
console.log(JSON.stringify(out));
