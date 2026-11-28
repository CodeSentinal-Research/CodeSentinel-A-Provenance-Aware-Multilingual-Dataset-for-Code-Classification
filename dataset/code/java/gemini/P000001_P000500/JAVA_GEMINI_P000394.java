import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            String[] brands = new String[n];
            for (int i = 0; i < n; i++) {
                names[i] = scanner.next();
                brands[i] = scanner.next();
            }
            String targetBrand = scanner.next();
            for (int i = 0; i < n; i++) {
                if (brands[i].equals(targetBrand)) {
                    System.out.println(names[i]);
                }
            }
        }
    }
}