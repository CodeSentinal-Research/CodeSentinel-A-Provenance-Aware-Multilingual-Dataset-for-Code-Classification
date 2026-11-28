def search_student(records, roll):
    for record in records:
        if record['roll_number'] == roll:
            return record
    return "Record Not Found"

def main():
    records = [
        {'name': 'John', 'roll_number': 101},
        {'name': 'Jane', 'roll_number': 102},
        {'name': 'Smith', 'roll_number': 103},
        {'name': 'James', 'roll_number': 104},
        {'name': 'Emily', 'roll_number': 105}
    ]

    roll_number = int(input("Enter roll number: "))
    result = search_student(records, roll_number)

    if isinstance(result, dict):
        print('Name: ', result['name'])
        print('Roll Number: ', result['roll_number'])
    else:
        print(result)

if __name__ == "__main__":
    main()

This code first defines a function `search_student` which takes a list of student records and a roll number as inputs. It then loops through the records, and returns the first student record with a roll number equal to the input. If no such student record is found, it returns the string 'Record Not Found'.

Then, in the `main` function, we first create a list of student records. We then ask for the user's roll number, and we call the `search_student` function with these inputs. If the result is a dictionary (which means we found a student), we print their name and roll number. If the result is 'Record Not Found', we print this message.