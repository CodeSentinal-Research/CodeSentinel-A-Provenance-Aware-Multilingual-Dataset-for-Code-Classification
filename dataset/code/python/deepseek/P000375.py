def search_patient(patient_records, patient_id):
    for patient in patient_records:
        if patient['patient_id'] == patient_id:
            return patient
    return 'Patient Not Found'

def main():
    patient_records = [
        {'patient_id': 1, 'name': 'John', 'age': 25},
        {'patient_id': 2, 'name': 'Jane', 'age': 30},
        {'patient_id': 3, 'name': 'Doe', 'age': 35}
    ]

    patient_id = int(input('Enter patient ID: '))
    result = search_patient(patient_records, patient_id)

    if isinstance(result, dict):
        print('Patient details:')
        print('Patient ID:', result['patient_id'])
        print('Name:', result['name'])
        print('Age:', result['age'])
    else:
        print(result)

if __name__ == '__main__':
    main()