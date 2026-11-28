Here is the JavaScript code for the problem:

function searchAvailableParkingSlots(parkingSlotRecords) {
    // assuming each parking slot record is an array of 2 elements: [slotNumber, type]
    // where slotNumber is the number of the parking slot and type is the type of the parking slot (e.g., 'small', 'medium', 'large')

    let vacantSlots = [];

    for (let record of parkingSlotRecords) {
        if (record[1] === 'vacant') {
            vacantSlots.push(record[0]);
        }
    }

    return vacantSlots;
}

This function takes an array of parking slot records as input. For each record, it checks if the slot type is 'vacant'. If it is, it adds the slot number to the `vacantSlots` array. The function then returns this array of vacant slot numbers.

Please note that this function assumes that the parking slot records are already sorted by slot number. If not, you may need to sort the records first.