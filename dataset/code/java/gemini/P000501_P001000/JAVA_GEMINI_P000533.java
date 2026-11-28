import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int size = scanner.nextInt(), q = scanner.nextInt();
            Queue<Integer> window = new LinkedList<>();
            double sum = 0;
            while (q-- > 0) {
                int val = scanner.nextInt();
                window.add(val);
                sum += val;
                if (window.size() > size) {
                    sum -= window.poll();
                }
                System.out.printf(Locale.US, "%.5f\n", sum / window.size());
            }
        }
    }
}