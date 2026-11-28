Here is a simple JavaScript function to search for records that contain a given keyword in their descriptions:

function searchRecords(records, keyword) {
    let result = [];
    for (let record of records) {
        if (record.description.includes(keyword)) {
            result.push(record);
        }
    }
    return result;
}

This function will take as input an array of records and a keyword. It will then iterate through each record in the array. If the description of the record contains the keyword, it will be added to the result array.

This function will return an array of records that contain the keyword in their description. If there are no matches, it will return an empty array.