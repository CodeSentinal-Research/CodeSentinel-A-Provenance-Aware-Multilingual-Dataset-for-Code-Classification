import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int index = scanner.nextInt();
        int maxSum = scanner.nextInt();
        System.out.println(maxValue(n, index, maxSum));
    }

    public static int maxValue(int n, int index, int maxSum) {
        int maxVal = Math.min(maxSum, index + 1);
        maxSum -= maxVal;
        int minVal = maxVal - (index == n - 1 ? maxSum : 0);
        return (maxVal + minVal) / 2;
    }
}
