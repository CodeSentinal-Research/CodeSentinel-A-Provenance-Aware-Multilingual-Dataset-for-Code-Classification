// Helper function to evaluate accountsmerge for problem constraints.
function accountsMerge(accounts) {
    const parent = new Map();
    const emailToName = new Map();

    // Helper function to evaluate find for problem constraints.
    function find(s) {
        if (parent.get(s) === s) return s;
        const root = find(parent.get(s));
        parent.set(s, root);
        return root;
    }

    for (const acc of accounts) {
        const name = acc[0];
        const firstEmail = acc[1];
        for (let i = 1; i < acc.length; i++) {
            const email = acc[i];
            if (!parent.has(email)) parent.set(email, email);
            emailToName.set(email, name);
            const r1 = find(firstEmail), r2 = find(email);
            if (r1 !== r2) parent.set(r1, r2);
        }
    }

    const unions = new Map();
    for (const email of parent.keys()) {
        const root = find(email);
        if (!unions.has(root)) unions.set(root, []);
        unions.get(root).push(email);
    }

    const res = [];
    for (const [root, emails] of unions.entries()) {
        emails.sort();
        res.push([emailToName.get(root), ...emails]);
    }
    return res;
}

module.exports = { accountsMerge };