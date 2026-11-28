// Search Available Flights Within Budget
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let budget = parseFloat((q["budget"] !== undefined ? q["budget"] : (q["maximum"] !== undefined ? q["maximum"] : 0)));
for (const r of records) {
    try {
        if ((Boolean((r["available"] !== undefined ? r["available"] : false)) && parseFloat((r["price"] !== undefined ? r["price"] : 0)) <= budget)) {
            out.push(r);
        }
    } catch (err) {
        /* pass */
    }
}
console.log(JSON.stringify(out));
