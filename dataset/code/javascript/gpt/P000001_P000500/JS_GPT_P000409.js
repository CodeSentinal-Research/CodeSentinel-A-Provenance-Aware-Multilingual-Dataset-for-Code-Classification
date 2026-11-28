// Search Users by Username Prefix
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let prefix = String((q["prefix"] !== undefined ? q["prefix"] : (q["value"] !== undefined ? q["value"] : "")));
for (const r of records) {
    if (String((r["username"] !== undefined ? r["username"] : "")).startsWith(prefix)) {
        out.push(r);
    }
}
console.log(JSON.stringify(out));
