Here is the Python code that implements the problem:

def search_records(records, keyword):
    return [record for record in records if keyword in record]

records = [input() for _ in range(int(input().strip()))]
keyword = input().strip()

matched_records = search_records(records, keyword)

for record in matched_records:
    print(record)
This script first reads the number of records and the keyword from the input, then reads each record. It then calls the `search_records` function with the input records and keyword, and prints the result.