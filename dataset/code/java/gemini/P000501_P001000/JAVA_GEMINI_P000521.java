import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> nums = new ArrayList<>();
            for (int i = 0; i < n; i++) nums.add(scanner.nextInt());
            int passes = 0;
            while (!nums.isEmpty()) {
                passes++;
                List<Integer> rem = new ArrayList<>();
                int last = Integer.MIN_VALUE;
                for (int x : nums) {
                    if (x > last) {
                        last = x;
                    } else {
                        rem.add(x);
                    }
                }
                nums = rem;
            }
            System.out.println(passes);
        }
    }
}