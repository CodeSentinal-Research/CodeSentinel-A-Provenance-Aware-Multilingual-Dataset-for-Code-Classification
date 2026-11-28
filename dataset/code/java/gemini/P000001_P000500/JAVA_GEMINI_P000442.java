import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int target = scanner.nextInt();
            int idx = -1;
            for (int i = 0; i < n; i++) {
                int v = scanner.nextInt();
                if (v == target && idx == -1) idx = i;
            }
            System.out.println(idx);
        }
    }
}