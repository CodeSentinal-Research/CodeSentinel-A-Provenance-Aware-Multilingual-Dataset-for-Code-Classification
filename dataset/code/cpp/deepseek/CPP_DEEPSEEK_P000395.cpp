#include <iostream>
#include <vector>

struct HotelRoom {
    int roomNumber;
    bool isAvailable;
};

int main() {
    int numRooms;
    std::cin >> numRooms;
    
    std::vector<HotelRoom> rooms(numRooms);
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isAvailable = true;
    }
    
    for (const auto& room : rooms) {
        if (room.isAvailable) {
            std::cout << room.roomNumber << std::endl;
        }
    }
    
    return 0;
}