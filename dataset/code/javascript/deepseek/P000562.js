Here is the JavaScript code for the problem:

function canVisitAllRooms(rooms) {
    const visitedRooms = new Set();
    function visitRoom(room) {
        if(visitedRooms.has(room)) {
            return;
        }
        visitedRooms.add(room);
        for(let key of rooms[room]) {
            visitRoom(key);
        }
    }
    visitRoom(0);
    return visitedRooms.size === rooms.length;
}

This code defines a function `canVisitAllRooms` that takes as input a list of rooms where each room is an array of keys that it contains. The function first initializes a `visitedRooms` set to store the rooms that have been visited. It then defines a recursive function `visitRoom` that takes a room number as input. If the room has already been visited, it returns immediately. Otherwise, it adds the room to the visited rooms set and then visits each key in the room. The function is then called with the starting room (0). If all rooms have been visited, the function returns true; otherwise, it returns false.