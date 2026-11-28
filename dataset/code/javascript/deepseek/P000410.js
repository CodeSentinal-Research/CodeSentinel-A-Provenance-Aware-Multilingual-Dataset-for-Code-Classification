function searchProductsByNameSuffix(records, suffix) {
    const regex = new RegExp('.*' + suffix + '$');
    return records.filter(record => regex.test(record.name));
}