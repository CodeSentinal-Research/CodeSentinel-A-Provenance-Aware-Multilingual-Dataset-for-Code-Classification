// Search Available Parking Slots
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_raw = fs.readFileSync(0, "utf8").trim();
const _stdin_json = _stdin_raw ? JSON.parse(_stdin_raw) : {};
let data = _stdin_json;
let records = (data["records"] !== undefined ? data["records"] : []);
let q = (data["query"] !== undefined ? data["query"] : data);
let out = [];
for (const r of records) {
    if (_in(String((r["status"] !== undefined ? r["status"] : (r["available"] !== undefined ? r["available"] : ""))).toLowerCase(), ["vacant", "available", "true"])) {
        out.push(r);
    }
}
console.log(JSON.stringify(out));
