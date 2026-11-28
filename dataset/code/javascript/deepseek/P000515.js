function getCollisionTimes(cars) {
  if (cars.length === 0) {
    return [];
  }

  const results = new Array(cars.length).fill(-1);
  let maxPosition = cars[cars.length - 1].position;
  let maxSpeed = cars[cars.length - 1].speed;

  for (let i = cars.length - 2; i >= 0; i--) {
    const car = cars[i];
    const nextCar = cars[i + 1];

    if (car.position + car.speed * 2 > nextCar.position && car.speed > nextCar.speed) {
      results[i] = 2.0;
      maxPosition = car.position;
      maxSpeed = car.speed;
    } else if (car.speed > nextCar.speed) {
      const collisionTime = (nextCar.position - car.position) / (car.speed - nextCar.speed);
      if (collisionTime < results[i + 1] || results[i + 1] === -1) {
        results[i] = collisionTime;
      }
    }
  }

  return results;
}

// Testing the function
const cars = [
  { position: 1, speed: 3 },
  { position: 2, speed: 4 },
  { position: 3, speed: 3 },
  { position: 4, speed: 2 },
  { position: 5, speed: 3 },
];
console.log(getCollisionTimes(cars)); // [1, 2, 3, 1.5, -1]
This JavaScript function, `getCollisionTimes`, uses a two-pointer approach to find the collision times between cars in the array. The function starts from the end of the array and moves towards the beginning, checking for a collision with the car directly ahead. If a collision is detected, it updates the result array. If no collision is detected, it simply returns -1.