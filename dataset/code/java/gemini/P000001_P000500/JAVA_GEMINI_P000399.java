import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] titles = new String[n];
            int[] years = new int[n];
            for (int i = 0; i < n; i++) {
                titles[i] = scanner.next();
                years[i] = scanner.nextInt();
            }
            int minYear = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                if (years[i] > minYear) {
                    System.out.println(titles[i]);
                }
            }
        }
    }
}