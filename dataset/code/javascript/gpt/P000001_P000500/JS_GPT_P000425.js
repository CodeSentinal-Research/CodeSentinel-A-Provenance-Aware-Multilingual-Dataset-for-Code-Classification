// Search Inactive Bank Accounts
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let months = parseInt((q["months"] !== undefined ? q["months"] : (q["inactivity_months"] !== undefined ? q["inactivity_months"] : 0)), 10);
let today = datetime.date.fromisoformat(String((q["current_date"] !== undefined ? q["current_date"] : null)));
let cutoff = (today - datetime.timedelta());
for (const r of records) {
    try {
        if (datetime.date.fromisoformat(String((r["last_transaction_date"] !== undefined ? r["last_transaction_date"] : null))) < cutoff) {
            out.push(r);
        }
    } catch (err) {
        /* pass */
    }
}
console.log(JSON.stringify(out));
