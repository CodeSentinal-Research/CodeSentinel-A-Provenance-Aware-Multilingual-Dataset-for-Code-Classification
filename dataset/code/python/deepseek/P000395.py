Here is a simple Python solution using list comprehension to find available rooms. This code assumes that each hotel room record is a list containing the room number and availability (True or False):

def get_available_rooms(room_records):
    return [room[0] for room in room_records if room[1] == True]

room_records = [(1, True), (2, False), (3, True), (4, False), (5, True)]
print(get_available_rooms(room_records))  

This code works by iterating over each room record in the input list. If the availability is True (i.e., the room is available), it adds the room number to the output list.

Please note that this solution is basic and may not scale well for larger inputs. For larger inputs, you might want to consider using a more efficient data structure or a database to store and retrieve room availability information.