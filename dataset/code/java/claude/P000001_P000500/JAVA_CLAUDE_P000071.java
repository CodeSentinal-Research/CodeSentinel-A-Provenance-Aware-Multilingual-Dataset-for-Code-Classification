public class Solution {
    public String typeOfTriangle(double a, double b, double c) {
        if (!(a + b > c && a + c > b && b + c > a)) return "Invalid";
        if (a == b && b == c) return "Equilateral";
        if (a == b || b == c || a == c) return "Isosceles";
        return "Scalene";
    }
}
