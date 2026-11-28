Here is the Python code for your problem:

def search_vacant_slots(records):
    vacant_slots = [record for record in records if record[-1] == 'V']
    return vacant_slots

def main():
    records = [('1A', 'V'), ('2A', 'V'), ('3A', 'V'), ('4A', 'V'), ('5A', 'V'), ('6A', 'P'), ('7A', 'P')]
    vacant_slots = search_vacant_slots(records)
    print(vacant_slots)

if __name__ == "__main__":
    main()

In this code, we first define a function `search_vacant_slots` that filters the list of records to only include records where the second element of the tuple (i.e., the status of the parking slot) is 'V'.

The main function then calls `search_vacant_slots` and prints the result. 

In the main function, we use a static list to represent the parking slot records. In a real-world scenario, you would use a database query to get the records.