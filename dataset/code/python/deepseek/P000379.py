Sure, here's a simple Python script using a dictionary to store the train data. In this case, the train number is the key and the value is a dictionary with the train details. This script will take the train number as input and display the details or "Train Not Found" if the train number is not found.

def get_train_info(train_data, train_number):
    if train_number in train_data:
        print(train_data[train_number])
    else:
        print("Train Not Found")

train_data = {
    'TRAIN123': {'train_name': 'Train 123', 'destination': 'New York', 'time': '06:00 PM', 'capacity': 50},
    'TRAIN456': {'train_name': 'Train 456', 'destination': 'Los Angeles', 'time': '08:00 AM', 'capacity': 30},
    'TRAIN789': {'train_name': 'Train 789', 'destination': 'Chicago', 'time': '10:00 PM', 'capacity': 40}
}

train_number = input("Enter the train number: ")
get_train_info(train_data, train_number)

In this code, the `get_train_info` function takes the train data and a train number as inputs. It checks if the train number is in the train data. If it is, it prints the details of the train. If not, it prints "Train Not Found".

In the main part of the code, we create a dictionary `train_data` where each key is a train number and the value is a dictionary with the train details. We then take a train number as input from the user and call the `get_train_info` function with `train_data` and the input train number.

This is a simple and basic implementation of your problem. In a real-world scenario, you would probably want to use a database or some sort of data structure to store this data, which would allow for more efficient and scalable data handling.