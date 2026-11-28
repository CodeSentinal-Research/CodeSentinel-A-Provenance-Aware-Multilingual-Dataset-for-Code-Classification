def input_handler(records):
    mobile_number = input("Enter the mobile number to be searched: ")
    for record in records:
        if record['mobile_number'] == mobile_number:
            return record
    return None

def search_customer(records):
    customer = input_handler(records)
    if customer:
        print("Matching customer details: ", customer)
    else:
        print("Customer Not Found")

def main():
    records = [{'name': 'John', 'mobile_number': '1234567890'}, 
               {'name': 'Mike', 'mobile_number': '0987654321'}, 
               {'name': 'Sara', 'mobile_number': '1112223333'}]
    search_customer(records)

if __name__ == "__main__":
    main()