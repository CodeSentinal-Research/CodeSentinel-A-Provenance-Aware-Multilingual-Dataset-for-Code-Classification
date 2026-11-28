// Search Products Eligible for Free Shipping
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let limit = parseFloat((q["minimum_price"] !== undefined ? q["minimum_price"] : (q["threshold"] !== undefined ? q["threshold"] : 0)));
for (const r of records) {
    try {
        if (parseFloat((r["price"] !== undefined ? r["price"] : 0)) >= limit) {
            out.push(r);
        }
    } catch (err) {
        /* pass */
    }
}
console.log(JSON.stringify(out));
