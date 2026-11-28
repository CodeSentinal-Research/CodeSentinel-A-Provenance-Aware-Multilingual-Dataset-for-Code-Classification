import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int target = scanner.nextInt();
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (scanner.nextInt() == target) count++;
            }
            System.out.println(count);
        }
    }
}