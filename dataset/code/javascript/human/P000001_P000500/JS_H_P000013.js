/**
 * This class represents a circle and can calculate it's perimeter and area
 * @constructor
 * @param {number} radius - The radius of the circle.
 */
export default class Circle {
  constructor(radius) {
    this.radius = radius
  }

  area = () => {
    return Math.pow(this.radius, 2) * Math.PI
  }
}
