Here is the python code to solve the given problem. The main function reads the input from the user and calls the search_passport function with the passport_records and passport_number as arguments.

def search_passport(passport_records, passport_number):
    for record in passport_records:
        if record['passport_number'] == passport_number:
            return record
    return 'Passport Not Found'

def main():
    n = int(input())
    
    passport_records = []
    
    for _ in range(n):
        passport_number, name, date_of_birth, nationality, issuing_country = input().split()
        passport_records.append({'passport_number': passport_number, 'name': name, 'date_of_birth': date_of_birth, 'nationality': nationality, 'issuing_country': issuing_country})
    
    passport_number = input()
    
    result = search_passport(passport_records, passport_number)
    
    if isinstance(result, dict):
        print(result['passport_number'], result['name'], result['date_of_birth'], result['nationality'], result['issuing_country'])
    else:
        print(result)

if __name__ == "__main__":
    main()

This code works in a way that you can run the program and provide input from the command line. The main function first reads the number of passport records, then it reads those records and stores them in a list. After that, it reads the passport number to be searched and searches for it in the list of passport records. If the passport is found, it prints the details of the passport. If the passport is not found, it prints 'Passport Not Found'.