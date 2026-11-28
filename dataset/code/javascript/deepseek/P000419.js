Here's a simple JavaScript solution using filter method. It filters the devices based on their status which in this case is marked as online.

function findOnlineDevices(devices) {
    return devices.filter(device => device.status === 'online');
}

This function takes an array of device records (each with properties: id, name, status) as input and returns a new array with the online devices. The `filter` method is used here to create a new array with all devices whose status is 'online'.

For input handling, you can use a variety of methods. Here's an example using the `fs` module for reading from a file:

const fs = require('fs');

fs.readFile('devices.json', 'utf8', function(err,jsonStr) {
    if (err) {
        console.log(err);
    } else {
        let devices = JSON.parse(jsonStr);
        let onlineDevices = findOnlineDevices(devices);
        console.log(onlineDevices);
    }
});

In this example, `devices.json` is a file containing an array of device records. The `readFile` function reads the file and when it's done, it calls the `findOnlineDevices` function with the device records.

Please replace `'devices.json'` with the path to your actual file. Also, the `findOnlineDevices` function assumes that the input is an array of device records. If your data is stored differently (for example, a database or an API), you'll need to adjust the code accordingly.