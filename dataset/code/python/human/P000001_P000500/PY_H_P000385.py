import sys
import mysql.connector as sql
# Setting up database connection
try:
    mydb = sql.connect(host="localhost", user="root", password="a1b2c3d4e5")
except sql.Error as e:
    print(f"Error connecting to database: {e}") 
    sys.exit()
cr = mydb.cursor()
# Creating the database and tables if they don't exist
q = "CREATE DATABASE IF NOT EXISTS pharmacy"
cr.execute(q)
q = "USE pharmacy"
cr.execute(q)
q = '''CREATE TABLE IF NOT EXISTS pharmacy_medicine(
    mid INTEGER PRIMARY KEY AUTO_INCREMENT,
    mname VARCHAR(30) NOT NULL,
    manufacturer VARCHAR(50),
    dateofm DATE NOT NULL,
    dateofexp DATE NOT NULL,
    price FLOAT,
    qty INTEGER
)'''
cr.execute(q)
q = '''CREATE TABLE IF NOT EXISTS bill(
    orderid INTEGER PRIMARY KEY AUTO_INCREMENT,
    cname VARCHAR(50),
    phone VARCHAR(15),
    medicine_bought VARCHAR(100),
    qty_bought VARCHAR(100),
    amount FLOAT,
    billdate DATE
)'''
cr.execute(q)
mydb.commit()
#Function to get valid date
def get_valid_date(prompt,is_expiry_date=False, dom=None):
    while True:
        date_str = input(prompt)
        date_parts = date_str.split('-')
        if len(date_parts) == 3:
            year, month, day = date_parts
            # Check if the year is 4 digits
            if len(year) == 4 and year.isdigit():
                if month.isdigit() and day.isdigit():
                    month = int(month)
                    day = int(day)
                    # Check that month is between 1-12 and day is between 1-31
                    if 1 <= month <= 12 and 1 <= day <= 31:
                        if is_expiry_date and dom:
                            dom_year, dom_month, dom_day = dom.split('-')
                            dom_year = int(dom_year)
                            dom_month = int(dom_month)
                            dom_day = int(dom_day)
                            # Compare dates: expiry date must be later than manufacture date
                            if (int(year) < dom_year) or (int(year) == dom_year and int(month) < dom_month) or (int(year) == dom_year and int(month) == dom_month and int(day) <= dom_day):
                                print("Expiry date must be after the manufacture date. Please enter a valid expiry date.")
                                continue  # Retry if expiry date is not valid
                        return date_str
                    else:
                        print("Invalid month or day! Month should be between 1 and 12, day between 1 and 31.")
                else:
                    print("Month and day should be numbers!")
            else:
                print("Year should be a 4-digit number.")
        else:
            print("Invalid date format! Please enter the date in yyyy-mm-dd format.")
# Function to add new medicine
def addmedicine():
    print("\nCreating new pharmacy medicine entry...\n")
    while True:
        try:
            name = input("Enter Medicine Name: ")
            mf = input("Enter Name of Manufacturer: ")
            dom = get_valid_date("Enter Date of Manufacture (yyyy-mm-dd): ")
            doe = get_valid_date("Enter Date of Expiry (yyyy-mm-dd): ", True, dom)
            # Validate price
            while True:
                try:
                    price = float(input("Enter the Price: "))
                    if price <= 0:
                        print("Price must be greater than zero! Please enter a valid price.")
                    else:
                        break
                except ValueError:
                    print("Invalid price! Please enter a valid number for the price.")
            # Validate quantity
            while True:
                try:
                    qty = int(input("Enter the Quantity: "))
                    if qty <= 0:
                        print("Quantity must be greater than zero! Please enter a valid quantity.")
                    else:
                        break
                except ValueError:
                    print("Invalid quantity! Please enter a valid number for the quantity.")
            # Constructing SQL query
            q = "INSERT INTO pharmacy_medicine (mname, manufacturer, dateofm, dateofexp, price, qty) VALUES ('{}', '{}', '{}', '{}', {}, {})".format(name, mf, dom, doe, price, qty)
            cr.execute(q)
            mydb.commit()   
            print("\nMedicine Inserted.")
            break  # Exit loop if successful
        except sql.Error as err:
            print(f"SQL Error: {err}. Please try again.")
# Function to show all medicines in the required format
def showmedicine():
    print("\nDisplaying all pharmacy medicines...\n")
    q = "SELECT * FROM pharmacy_medicine"
    cr.execute(q)
    res = cr.fetchall()
    if not res:
        print("No medicines available in stock.\n")
        return
    for k in res:
        print("Medicine ID:", k[0], "  Name:", k[1], "  Manufacturer:", k[2], "  Date of Manufacture:", k[3], "  Date of Expiry:", k[4], "  Price:", k[5], "  Quantity:", k[6])
    print("\n")
# Function to restock medicine
def restock():
    while True:
        try:
            search_param = input("Enter Medicine ID or Full Name: ")
            if search_param.isdigit():
                q = "SELECT qty FROM pharmacy_medicine WHERE mid = {}".format(search_param)
            else:
                q = "SELECT qty FROM pharmacy_medicine WHERE mname = '{}'".format(search_param)
            cr.execute(q)
            res = cr.fetchone()
            if res is None:
                print("\nNo Medicine Found. Please check the ID or name.")
                continue  # Retry if medicine not found
            # Validate quantity to be added
            while True:
                try:
                    qty = int(input("Enter the Quantity to Add: "))
                    if qty <= 0:
                        print("Quantity must be greater than zero! Please enter a valid quantity.")
                    else:
                        break
                except ValueError:
                    print("Invalid quantity input. Please enter a valid number.")
            q = "UPDATE pharmacy_medicine SET qty = qty + {} WHERE mname = '{}' OR mid = {}".format(qty, search_param, search_param if search_param.isdigit() else "NULL")
            cr.execute(q)
            mydb.commit()
            print("\nMedicine Restocked.")
            break  # Exit loop if successful
        except sql.Error as err:
            print(f"SQL Error: {err}. Please try again.")
# Function to search for a medicine
def search():
    while True:
        try:
            search_param = input("Enter Medicine ID or Full Name: ")
            # If it's a number, treat it as Medicine ID
            if search_param.isdigit():
                q = "SELECT * FROM pharmacy_medicine WHERE mid = {}".format(search_param)
            else:  # Otherwise, treat it as the full name of the medicine
                q = "SELECT * FROM pharmacy_medicine WHERE mname = '{}'".format(search_param)
            cr.execute(q)
            result = cr.fetchone()  # Fetch one record
            if result is None:
                print("\nNo Medicine Available With This ID or Name. Please try again.")
                continue  # If medicine not found, allow the user to retry
            # If the medicine is found, display the details
            print("\nMedicine Found:")
            print("\n")
            print("Medicine ID:", result[0], "  Name:", result[1], "  Manufacturer:", result[2], "  Date of Manufacture:", result[3], "  Date of Expiry:", result[4], "  Price:", result[5], "  Quantity:", result[6])
            break  # Exit loop once a valid medicine is found
        except sql.Error as err:
            print(f"SQL Error: {err}. Please try again.")
# Function to delete medicine
def deletem():
    while True:
        try:
            search_param = input("Enter Medicine ID or Full Name to delete: ")
            # If search_param is numeric, treat it as Medicine ID
            if search_param.isdigit():
                q = "DELETE FROM pharmacy_medicine WHERE mid = {}".format(search_param)
            else:  # Otherwise, treat it as Medicine Name
                q = "DELETE FROM pharmacy_medicine WHERE mname = '{}'".format(search_param)
            cr.execute(q)
            mydb.commit()  # Commit the changes to the database
            # Check if any rows were deleted
            if cr.rowcount == 0:
                print("\nNo Medicine Found with this ID or Name. Please try again.")
                continue  # If no rows were deleted, allow the user to try again
            print("\nMedicine Deleted Successfully.")
            break  # Exit the loop once the medicine is deleted successfully
        except sql.Error as err:
            print(f"SQL Error: {err}. Please try again.")
# Function to create the order and reduce stock
def order():
    while True:
        try:
            cname = input("Enter Customer's Name: ")
            # Input validation for phone number (must be a 10-digit number)
            while True:
                phone = input("Enter Customer's 10-digit Phone Number: ")
                if phone.isdigit() and len(phone) == 10:
                    break
                else:
                    print("Invalid input! Please enter a valid 10-digit Phone Number.") 
            # Use the get_valid_date function for order date validation
            order_date = get_valid_date("Enter Order Date (yyyy-mm-dd): ")
            amount = 0
            medicine = ""
            qty_list = ""
            medicine_data = []  # Store medicine data (name, qty, price) to update stock later
            while True:
                search_param = input("Enter Medicine ID or Full Name: ")
                if search_param.isdigit():  # If it's a number, treat it as ID
                    q = "SELECT * FROM pharmacy_medicine WHERE mid = {}".format(search_param)
                else:  # Otherwise, treat it as the full name of the medicine
                    q = "SELECT * FROM pharmacy_medicine WHERE mname = '{}'".format(search_param)
                cr.execute(q)
                res = cr.fetchone()
                if res is None:
                    print("\nNo Medicine Available With This ID or Name\n")
                    continue  # Retry if the medicine was not found
                else:
                    price = res[5]
                    available_qty = res[6]
                    medicine_name = res[1]
                    # Check if price and quantity are greater than 0
                    if available_qty <= 0:
                        print(f"Medicine {medicine_name} is out of stock. Please try another one.")
                        continue
                    print("Price of Medicine:", price)
                    # Input validation for quantity
                    while True:
                        try:
                            qty = int(input(f"Enter the Quantity to be Purchased (Available: {available_qty}): "))
                            if qty > available_qty:
                                print(f"Insufficient stock. Only {available_qty} units available.")
                                continue  # Retry if quantity exceeds available stock
                            if qty <= 0:
                                print("Quantity must be greater than zero. Please enter a valid quantity.")
                                continue
                            break  # Valid quantity input
                        except ValueError:
                            print("Invalid input. Please enter a valid number for quantity.")
                    # Calculate the bill for this medicine
                    bill = price * qty
                    amount += bill
                    medicine += medicine_name + ", "
                    qty_list += str(qty) + ", "
                    medicine_data.append((medicine_name, qty, price))  # Store the purchased medicine data
                    print("Amount for Medicine:", bill)
                ans = input("Enter -1 to stop or press any key to add another medicine: ")
                if ans == "-1":
                    print("Calculating Your Bill")
                    break  # Exit loop if user doesn't want to add more medicines
            # If no medicine was added, exit function
            if amount == 0:
                print("No medicines were added to the order.")
                continue  # Retry the order process if no medicine was added
            print("Total Bill Amount is:", amount)
            medicine = medicine.rstrip(", ")
            qty_list = qty_list.rstrip(", ")
            # Insert order into the bill table
            q = "INSERT INTO bill (cname, phone, medicine_bought, qty_bought, amount, billdate) VALUES ('{}', '{}', '{}', '{}', {}, '{}')".format(cname, phone, medicine, qty_list, amount, order_date)
            cr.execute(q)
            mydb.commit()
            # Update stock in pharmacy_medicine table for each medicine in the order
            for med_name, med_qty, _ in medicine_data:
                update_qty_query = "UPDATE pharmacy_medicine SET qty = qty - {} WHERE mname = '{}'".format(med_qty, med_name)
                cr.execute(update_qty_query)
            mydb.commit()  # Commit all updates
            print("Order Created and Stock Updated.")
            break  # Exit after successful order creation
        except sql.Error as err:
            print(f"SQL Error: {err}. Please try again.")
            continue  # If there was an SQL error, retry the entire billing process
# Function to show all orders
def showorder():
    print("\nDisplaying all orders...\n")
    q = "SELECT * FROM bill"
    cr.execute(q)
    res = cr.fetchall()
    if not res:
        print("No orders found.\n")
        return
    for k in res:
        print("Order ID:", k[0], "  Customer Name:", k[1], "  Phone:", k[2], "  Medicines Bought:", k[3], "  Quantity Bought:", k[4], "  Amount:", k[5], "  Date:", k[6])
    print("\n")
# Function to search order by Order ID or Customer Name (Admin only)
def search_order():
    while True:
        try:
            search_param = input("Enter Order ID or Customer Name: ")
            # Check if the input is a number (Order ID) or a string (Customer Name)
            if search_param.isdigit():  # If it's a number, treat it as Order ID
                q = "SELECT * FROM bill WHERE orderid = {}".format(search_param)
            else:  # Otherwise, treat it as Customer Name
                q = "SELECT * FROM bill WHERE cname = '{}'".format(search_param)
            cr.execute(q)
            res = cr.fetchall()  # Fetch all matching orders
            if not res:
                print("\nNo Order Found With This ID or Customer Name\n")
                continue  # Allow user to try again
            else:
                print("\nOrder(s) Found:")
                for k in res:
                    print("\nOrder ID:", k[0], "  Customer Name:", k[1], "  Phone:", k[2], "  Medicines Bought:", k[3], "  Quantity Bought:", k[4], "  Amount:", k[5], "  Date:", k[6])
                print()
            break  # Exit after successful search
        except sql.Error as err:
            print(f"SQL Error: {err}. Please try again.")
            continue  # Retry the entire search process if there's an SQL error
# Admin Menu
def admin_menu():
    while True:
        print("\n+----------------------------------+")
        print("|         ADMIN MENU               |")
        print("+----------------------------------+")
        print("| 1. Add New Medicine              |")
        print("| 2. Restock a Medicine            |")
        print("| 3. Show All Medicines            |")
        print("| 4. Search a Medicine             |")
        print("| 5. Delete a Medicine             |")
        print("| 6. Create a Order                |")
        print("| 7. Show All Orders               |")
        print("| 8. Search an Order               |")
        print("| 9. Exit                          |")
        print("+----------------------------------+")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            addmedicine()
        elif choice == 2:
            restock()
        elif choice == 3:
            showmedicine()
        elif choice == 4:
            search()
        elif choice == 5:
            deletem()
        elif choice == 6:
            order()
        elif choice == 7:
            showorder()
        elif choice == 8:
            search_order()
        elif choice == 9:
            print("Thank you for visiting Med Plus")
            sys.exit()
        else:
            print("Invalid choice! Please try again.")
# User Menu
def user_menu():
    while True:
        print("\n+----------------------------------+")
        print("|         USER MENU                |")
        print("+----------------------------------+")
        print("| 1. Show All Medicines            |")
        print("| 2. Search a Medicine             |")
        print("| 3. Create an Order               |")
        print("| 4. Exit                          |")
        print("+----------------------------------+")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            showmedicine()
        elif choice == 2:
            search()
        elif choice == 3:
            order()
        elif choice == 4:
            print("Thank you for visiting Med Plus")
            sys.exit()
        else:
            print("Invalid choice! Please try again.")
# Login Function
def login():
    print("------------------------------------")
    print("|Successfully Connected To Database|")
    print("------------------------------------")
    while True:
        try:
            print("------------------------------------")
            print("|       WELCOME TO MEDPLUS         |")
            print("------------------------------------")
            print("------------------------------------")
            print("|    PHARMACY MANAGEMENT SYSTEM    |")
            print("------------------------------------")
            print("------------------------------------")
            print("|MAY YOU LIVE A MEDICINE FREE LIFE |")    
            print("------------------------------------")
            print("| 1. ADMIN LOGIN                   |")
            print("| 2. USER LOGIN                    |")
            print("| 3. EXIT                          |")
            print("------------------------------------")
            choice = int(input("ENTER YOUR CHOICE: "))
            if choice == 1:  # Admin login
                print("\nAdmin Login\n")
                admin_username = input("Enter Admin Username: ")
                admin_password = input("Enter Admin Password: ")
                if admin_username == "admin" and admin_password == "admin123":
                    print("Admin Logged in Successfully!")
                    admin_menu()
                else:
                    print("Incorrect Admin Username or Password.")
            elif choice == 2:  # User login
                print("\nUser Login\n")
                user_username = input("Enter User Username: ")
                user_password = input("Enter User Password: ")
                if user_username == "user" and user_password == "user123":
                    print("User Logged in Successfully!")
                    user_menu()
                else:
                    print("Incorrect User Username or Password.")
            elif choice == 3:
                print("Thank you for visiting Med Plus")
                sys.exit()
            else:
                print("Invalid choice. Please try again.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")
if __name__ == "__main__":
    try:
        login()
    finally:
        # Close the cursor and the database connection
        cr.close()
        mydb.close()
