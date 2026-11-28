// Search Courses by Instructor
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
for (const r of records) {
    if (String((r["instructor"] !== undefined ? r["instructor"] : "")) === String((q["instructor"] !== undefined ? q["instructor"] : (q["value"] !== undefined ? q["value"] : (q["query"] !== undefined ? q["query"] : ""))))) {
        out.push(r);
    }
}
console.log(JSON.stringify(out));
