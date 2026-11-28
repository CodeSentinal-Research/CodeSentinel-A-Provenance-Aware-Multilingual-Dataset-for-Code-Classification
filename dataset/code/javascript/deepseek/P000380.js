function searchHotelByID(hotels, hotelID) {
    // Iterate through the list of hotels
    for(let i = 0; i < hotels.length; i++) {
        // If the hotel ID matches the input ID
        if(hotels[i].hotelID === hotelID) {
            // Return the hotel details
            return hotels[i];
        }
    }
    // If the hotel ID was not found
    return 'Hotel Not Found';
}