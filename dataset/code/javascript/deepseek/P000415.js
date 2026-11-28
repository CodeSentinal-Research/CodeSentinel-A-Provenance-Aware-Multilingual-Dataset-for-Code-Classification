Sure, here is a simple JavaScript code using an object to map patient records to their blood groups. You can use the `filter` function to find all patients having the specified blood group.

function searchPatientsByBloodGroup(records, targetBloodGroup) {
  // Create a map of patient records to their blood groups
  const patientMap = {};
  records.forEach(record => {
    patientMap[record.id] = record.bloodGroup;
  });

  // Filter the records based on the target blood group
  return Object.values(patientMap)
    .filter(bloodGroup => bloodGroup === targetBloodGroup)
    .map(bloodGroup => records.find(record => record.bloodGroup === bloodGroup));
}

// Example usage:
const patients = [
  { id: '1', name: 'John', bloodGroup: 'A' },
  { id: '2', name: 'Jane', bloodGroup: 'B' },
  { id: '3', name: 'Bob', bloodGroup: 'A' },
  { id: '4', name: 'Alice', bloodGroup: 'B' },
];

const matchingPatients = searchPatientsByBloodGroup(patients, 'A');
console.log(matchingPatients);

This code creates a map of patient records to their blood groups, then uses the `filter` function to find all patients in the map whose blood group matches the target.

Please note that this code assumes that the `records` array is an array of objects, where each object has the properties `id`, `name`, and `bloodGroup`, and that the `bloodGroup` property is a string. The `targetBloodGroup` parameter is also a string.

This code does not handle cases where there are multiple patients in the map that have the target blood group. If you want to handle that case, you would need to modify the code to store matching patient records in a different way, such as an array of patient IDs.