// Search Students Eligible for Scholarship
const fs = require("fs");
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
let min_cgpa = parseFloat((q["min_cgpa"] !== undefined ? q["min_cgpa"] : 0));
let max_income = parseFloat((q["max_income"] !== undefined ? q["max_income"] : Math.pow(10, 100)));
for (const r of records) {
    try {
        if ((parseFloat((r["cgpa"] !== undefined ? r["cgpa"] : 0)) >= min_cgpa && parseFloat((r["family_income"] !== undefined ? r["family_income"] : Math.pow(10, 100))) <= max_income)) {
            out.push(r);
        }
    } catch (err) {
        /* pass */
    }
}
console.log(JSON.stringify(out));
