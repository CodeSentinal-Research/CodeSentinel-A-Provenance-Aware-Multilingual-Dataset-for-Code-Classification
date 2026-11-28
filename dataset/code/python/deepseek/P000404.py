Sure, here is a simple Python code that solves the problem. This code assumes that we have a list of dictionaries where each dictionary represents a doctor. Each dictionary has a key for "name" and "specialization".

def search_doctors_by_specialization(doctor_records, specialization):
    matching_doctors = [doctor for doctor in doctor_records if doctor['specialization'] == specialization]
    return matching_doctors

def main():
    doctor_records = [
        {'name': 'Dr. Smith', 'specialization': 'Cardiology'},
        {'name': 'Dr. Johnson', 'specialization': 'Neurology'},
        {'name': 'Dr. Williams', 'specialization': 'Cardiology'},
        {'name': 'Dr. Brown', 'specialization': 'Neurology'},
        {'name': 'Dr. Jones', 'specialization': 'Neurology'},
        {'name': 'Dr. Miller', 'specialization': 'Cardiology'},
    ]

    specialization = 'Cardiology'

    matching_doctors = search_doctors_by_specialization(doctor_records, specialization)
    for doctor in matching_doctors:
        print(doctor['name'])

if __name__ == '__main__':
    main()

This code will output:

Dr. Smith
Dr. Williams
Dr. Miller

This code works by using list comprehension to create a list of doctors with the specified specialization. The main function demonstrates how to use this function with some sample input.