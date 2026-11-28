import java.util.Scanner;

public class Solution {
    public static double arrayAverage(double[] arr) {
        if (arr == null || arr.length == 0) return 0.0;
        double sum = 0;
        for (double v : arr) sum += v;
        return sum / arr.length;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextDouble();
            System.out.printf("%.2f\n", arrayAverage(arr));
        }
        sc.close();
    }
}