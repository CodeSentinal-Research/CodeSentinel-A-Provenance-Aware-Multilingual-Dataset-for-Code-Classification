import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt();
            int[] target = new int[m];
            for (int i = 0; i < m; i++) target[i] = scanner.nextInt();
            int n = scanner.nextInt();
            int targetIdx = 0;
            for (int i = 1; i <= n; i++) {
                if (targetIdx == m) break;
                System.out.println("Push");
                if (target[targetIdx] == i) targetIdx++;
                else System.out.println("Pop");
            }
        }
    }
}