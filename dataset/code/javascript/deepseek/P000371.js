function searchEmployee(employeeRecords, id) {
  for(let i = 0; i < employeeRecords.length; i++) {
    if(employeeRecords[i].id === id) {
      return employeeRecords[i];
    }
  }
  return "Record Not Found";
}