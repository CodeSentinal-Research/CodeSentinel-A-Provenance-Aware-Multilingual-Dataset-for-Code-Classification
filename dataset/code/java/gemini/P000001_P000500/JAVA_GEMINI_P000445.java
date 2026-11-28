import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int target = scanner.nextInt();
            boolean found = false;
            for (int i = 0; i < r * c; i++) {
                if (scanner.nextInt() == target) found = true;
            }
            System.out.println(found ? "Found" : "Not Found");
        }
    }
}