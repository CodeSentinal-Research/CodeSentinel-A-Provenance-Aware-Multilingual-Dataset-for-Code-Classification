// Search Expired Memberships
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let today = String((q["date"] !== undefined ? q["date"] : (q["current_date"] !== undefined ? q["current_date"] : "")));
for (const r of records) {
    if (String((r["expiry_date"] !== undefined ? r["expiry_date"] : "")) < today) {
        out.push(r);
    }
}
console.log(JSON.stringify(out));
