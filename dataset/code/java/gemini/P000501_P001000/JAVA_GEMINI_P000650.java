import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int size = scanner.nextInt();
            int[] vals = new int[size];
            for (int i = 0; i < size; i++) vals[i] = scanner.nextInt();
            int n = scanner.nextInt();
            if (n >= 1 && n <= size) System.out.println(vals[n - 1]);
            else System.out.println(-1);
        }
    }
}