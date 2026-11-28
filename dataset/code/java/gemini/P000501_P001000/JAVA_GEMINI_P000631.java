import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Set<Integer> vals = new HashSet<>();
            for (int i = 0; i < n; i++) vals.add(scanner.nextInt());
            int target = scanner.nextInt();
            System.out.println(vals.contains(target) ? "true" : "false");
        }
    }
}