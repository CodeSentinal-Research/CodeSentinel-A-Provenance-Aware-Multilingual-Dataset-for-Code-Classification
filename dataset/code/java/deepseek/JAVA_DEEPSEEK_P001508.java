import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] fruits = new int[n];
        for (int i = 0; i < n; i++) {
            fruits[i] = scanner.nextInt();
        }
        System.out.println(maxFruits(fruits));
    }

    public static int maxFruits(int[] fruits) {
        int left = 0, right = 0, max = 0;
        int[] count = new int[2];
        while (right < fruits.length) {
            count[fruits[right]]++;
            while (count[fruits[right]] > 1) {
                count[fruits[left]]--;
                left++;
            }
            max = Math.max(max, right - left + 1);
            right++;
        }
        return max;
    }
}
