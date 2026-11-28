function maxRunningTime(n, m, batteries) {
  // Find the maximum battery capacity
  var maxBattery = Math.max.apply(null, batteries);

  // Calculate the total battery power
  var totalBatteryPower = maxBattery * m;

  // Calculate the total power all computers can take
  var totalPower = n * maxBattery;

  // Calculate the remaining power
  var remainingPower = totalBatteryPower - totalPower;

  // Calculate the maximum running time
  var maxRunningTime = remainingPower / n;

  return maxRunningTime;
}
In this code, we are first finding the maximum battery capacity. Then we calculate the total battery power. After that, we calculate the total power all computers can take. We calculate the remaining power by subtracting the total power from the total battery power. Lastly, we calculate the maximum running time by dividing the remaining power by the number of computers. The function returns the maximum running time.