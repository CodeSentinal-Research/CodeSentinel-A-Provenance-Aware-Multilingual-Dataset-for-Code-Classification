Here is the JavaScript code for the problem:

function searchPatient(patientRecords, patientId) {
    for(let i = 0; i < patientRecords.length; i++) {
        if(patientRecords[i].patientId === patientId) {
            return patientRecords[i];
        }
    }
    return "Patient Not Found";
}

This code defines a function `searchPatient` which takes in an array of patient records and a patient ID as input. It iterates over the patient records array and checks if the patient ID in each record matches the input ID. If it does, it returns the corresponding patient record. If it doesn't find a match, it returns "Patient Not Found".