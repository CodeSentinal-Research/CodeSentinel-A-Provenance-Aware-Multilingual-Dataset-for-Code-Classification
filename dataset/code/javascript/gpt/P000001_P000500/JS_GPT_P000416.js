// Search Vehicles Manufactured After a Given Year
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let year = parseInt((q["year"] !== undefined ? q["year"] : (q["after_year"] !== undefined ? q["after_year"] : 0)), 10);
for (const r of records) {
    try {
        if (parseInt((r["manufactured_year"] !== undefined ? r["manufactured_year"] : 0), 10) > year) {
            out.push(r);
        }
    } catch (err) {
        /* pass */
    }
}
console.log(JSON.stringify(out));
