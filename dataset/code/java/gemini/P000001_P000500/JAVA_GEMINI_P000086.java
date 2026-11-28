import java.util.Scanner;

public class Solution {
    public static double calculateElectricityBill(double units) {
        double bill = 0.0;
        if (units <= 50) {
            bill = units * 0.50;
        } else if (units <= 150) {
            bill = (50 * 0.50) + ((units - 50) * 0.75);
        } else if (units <= 250) {
            bill = (50 * 0.50) + (100 * 0.75) + ((units - 150) * 1.20);
        } else {
            bill = (50 * 0.50) + (100 * 0.75) + (100 * 1.20) + ((units - 250) * 1.50);
        }
        return bill + (bill * 0.20);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextDouble()) {
            double units = sc.nextDouble();
            System.out.printf("%.2f\n", calculateElectricityBill(units));
        }
        sc.close();
    }
}