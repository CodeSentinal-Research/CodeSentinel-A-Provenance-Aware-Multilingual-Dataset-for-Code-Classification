Sure, here is a simple Python solution using list comprehension to match patients based on their blood group.

def search_patients(records, blood_group):
    return [record for record in records if record[-1] == blood_group]

patients = [['John', 'O+'], ['Jane', 'A-'], ['Tom', 'B+'], ['Emily', 'B-'], ['Steve', 'O-']]
blood_group = 'B+'

matched_patients = search_patients(patients, blood_group)

for patient in matched_patients:
    print(patient)

This function, `search_patients`, takes a list of patient records and a blood group as inputs. It then returns a list of patient records that match the given blood group.

The test code creates a list of patient records and a blood group, then calls the `search_patients` function with these as arguments. The results are printed to the console.

The input list of patient records is hardcoded for simplicity. In a real-world scenario, you would likely read this from a file or database. The blood group is also hardcoded for simplicity. In a real-world scenario, you would get this from the user input.

Please note that this code assumes that the patient records are lists where the first element is the patient's name and the second element is the patient's blood group. The `search_patients` function would need to be adjusted if this is not the case.