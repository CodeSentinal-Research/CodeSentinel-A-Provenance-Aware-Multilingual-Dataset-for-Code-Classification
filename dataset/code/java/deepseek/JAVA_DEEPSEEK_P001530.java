import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        int maxSum = 0;
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (set.contains(num)) {
                currentSum -= num;
            } else {
                set.add(num);
                currentSum += num;
            }
            maxSum = Math.max(maxSum, currentSum);
        }
        System.out.println(maxSum);
    }
}
