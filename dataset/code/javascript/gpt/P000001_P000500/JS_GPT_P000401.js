// Search Products with Low Stock
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let limit = parseFloat((q["threshold"] !== undefined ? q["threshold"] : (q["stock_threshold"] !== undefined ? q["stock_threshold"] : 0)));
for (const r of records) {
    try {
        if (parseFloat((r["stock"] !== undefined ? r["stock"] : 0)) < limit) {
            out.push(r);
        }
    } catch (err) {
        /* pass */
    }
}
console.log(JSON.stringify(out));
