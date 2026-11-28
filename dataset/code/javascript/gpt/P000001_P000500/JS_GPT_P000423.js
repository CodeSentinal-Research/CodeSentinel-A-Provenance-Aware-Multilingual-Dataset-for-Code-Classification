// Search Orders Pending for More Than N Days
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let days = parseInt((q["days"] !== undefined ? q["days"] : (q["n"] !== undefined ? q["n"] : 0)), 10);
let today = datetime.date.fromisoformat(String((q["current_date"] !== undefined ? q["current_date"] : null)));
for (const r of records) {
    if (String((r["status"] !== undefined ? r["status"] : "")).toLowerCase() === "pending") {
        try {
            let placed = datetime.date.fromisoformat(String((r["order_date"] !== undefined ? r["order_date"] : null)));
            if ((today - placed).days > days) {
                out.push(r);
            }
        } catch (err) {
            /* pass */
        }
    }
}
console.log(JSON.stringify(out));
