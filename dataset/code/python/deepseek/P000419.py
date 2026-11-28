Here's a simple Python program that uses list comprehension to solve the problem:

def find_online_devices(device_records):
    online_devices = [device for device in device_records if device['status'] == 'online']
    return online_devices

device_records = [{'id': 'device1', 'status': 'online'}, {'id': 'device2', 'status': 'offline'}, {'id': 'device3', 'status': 'online'}, {'id': 'device4', 'status': 'online'}, {'id': 'device5', 'status': 'offline'}]

print(find_online_devices(device_records))

In the program above, the function `find_online_devices` takes a list of device records as input. It uses a list comprehension to filter out the devices whose status is 'online' and returns the remaining devices in the list.

The input is a list of device records, where each record is a dictionary with 'id' and 'status' keys. In the example, we have five devices, two of which are online and two of which are offline.

When you run this program, it will print:
[{'id': 'device1', 'status': 'online'}, {'id': 'device3', 'status': 'online'}, {'id': 'device5', 'status': 'offline'}]

Note that the order of the devices in the output may not match the order in the input list, because lists in Python are unordered collections of items.