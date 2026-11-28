function minRefuelStops(distance, fuel, stations, positions) {
    // Initialize the array of stops to reach the destination
    let stops = [];
    
    // Add the initial fuel to the stops array
    stops.push(fuel);
    
    // Loop through each fuel station
    for(let i = 0; i < stations.length; i++) {
        // While the remaining fuel in the current station is less than or equal to the remaining distance to reach the destination
        while(stations[i] !== 0 && stops[stops.length - 1] < positions[i]) {
            // If the remaining distance to reach the destination is less than or equal to the remaining fuel in the current station
            // Add a stop to reach the destination
            stops.push(stops[stops.length - 1] + 1);
            
            // Decrease the remaining fuel in the current station
            stations[i]--;
        }
        
        // If there is no fuel station left in the current station, break the loop
        if(stations[i] === 0) {
            break;
        }
    }
    
    // If the remaining distance to reach the destination is more than the remaining fuel in the last station
    // Return -1 as the destination cannot be reached
    if(stops[stops.length - 1] < distance) {
        return -1;
    }
    
    // Return the minimum number of stops to reach the destination
    return stops.length - 1;
}