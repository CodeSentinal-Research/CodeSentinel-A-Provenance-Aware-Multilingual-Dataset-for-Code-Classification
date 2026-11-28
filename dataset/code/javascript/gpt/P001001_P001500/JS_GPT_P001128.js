// P001128 - Accounts Merge
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length === 0) return;
    const numAccounts = parseInt(lines[0].trim(), 10);
    const emailToName = new Map();
    const parent = new Map();
    function find(email) {
        if (!parent.has(email)) parent.set(email, email);
        if (parent.get(email) === email) return email;
        const root = find(parent.get(email));
        parent.set(email, root);
        return root;
    }
    function union(e1, e2) {
        const r1 = find(e1), r2 = find(e2);
        if (r1 !== r2) parent.set(r1, r2);
    }
    for (let i = 1; i <= numAccounts; i++) {
        if (!lines[i]) continue;
        const parts = lines[i].trim().split(/\s+/);
        const name = parts[0];
        const firstEmail = parts[1];
        for (let j = 1; j < parts.length; j++) {
            emailToName.set(parts[j], name);
            union(firstEmail, parts[j]);
        }
    }
    const unions = new Map();
    for (const email of emailToName.keys()) {
        const root = find(email);
        if (!unions.has(root)) unions.set(root, []);
        unions.get(root).push(email);
    }
    for (const [root, emails] of unions.entries()) {
        emails.sort();
        const name = emailToName.get(root);
        console.log(name + " " + emails.join(" "));
    }
}

main();
