Here is a simple JavaScript code that fulfills the problem's requirement. This code assumes you have a list of doctors in memory and a specialization.

function searchDoctorsBySpecialization(doctors, specialization) {
    var results = [];
    for(let i=0; i<doctors.length; i++) {
        if(doctors[i].specialization === specialization) {
            results.push(doctors[i]);
        }
    }
    return results;
}

// Example usage:

var doctors = [
    {name: 'Doctor A', specialization: 'Surgeon'},
    {name: 'Doctor B', specialization: 'Cardiologist'},
    {name: 'Doctor C', specialization: 'Neurologist'},
    {name: 'Doctor D', specialization: 'Neurologist'},
    {name: 'Doctor E', specialization: 'Oncologist'}
];

var result = searchDoctorsBySpecialization(doctors, 'Neurologist');

console.log(result);

In this code, we define a function `searchDoctorsBySpecialization` that takes in an array of doctors and a specialization, then iterates over the doctors array. If the specialization of a doctor matches the input specialization, the doctor object is added to the results array. Finally, the results array is returned.

The example usage demonstrates how to call this function with a list of doctors and a specialization, and how to print the results.

Please note that you need to replace the `doctors` array with your actual data. Also, this code doesn't handle the input, it's just a structure. For a real-world application, you'd want to replace this array with a database query or similar.