import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            char[] a = scanner.next().toCharArray();
            int k = scanner.nextInt();
            for (int start = 0; start < a.length; start += 2 * k) {
                int i = start, j = Math.min(start + k - 1, a.length - 1);
                while (i < j) {
                    char tmp = a[i];
                    a[i++] = a[j];
                    a[j--] = tmp;
                }
            }
            System.out.println(new String(a));
        }
    }
}