Sure, here's a simple example of how you can implement this in JavaScript. In this example, I'm assuming a structure where each room is represented by an object with a `status` property indicating whether the room is available or not.

let hotelRooms = [
    { id: 1, status: true },
    { id: 2, status: false },
    { id: 3, status: true },
    // ... more rooms
];

function searchAvailableRooms() {
    let availableRooms = [];

    for (let i = 0; i < hotelRooms.length; i++) {
        if (hotelRooms[i].status) {
            availableRooms.push(hotelRooms[i]);
        }
    }

    return availableRooms;
}

console.log(searchAvailableRooms());

This code will output an array of all available rooms in the `hotelRooms` array.

Please note that this is a very basic implementation and may not work as-is for a real-world scenario. In a real-world scenario, you would need to interact with your database or API to fetch the room data. You may also need to handle pagination if you are fetching a large number of rooms.

Also, the way you fetch data from a database or an API can differ based on the technology you are using. The above example is written with Node.js and assumes you have a database or an API ready to fetch the data. If you are working in a different environment (like a front-end web application), you may need to use a different method to fetch data.