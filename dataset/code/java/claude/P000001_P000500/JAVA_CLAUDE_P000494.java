import java.util.Scanner;
public class Solution {
    public double celsiusToFahrenheit(double c) { return c*9.0/5.0+32.0; }
    public static void main(String[] args) {
        double c = new Scanner(System.in).nextDouble();
        System.out.printf("%.2f%n", new Solution().celsiusToFahrenheit(c));
    }
}
