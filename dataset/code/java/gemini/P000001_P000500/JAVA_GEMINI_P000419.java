import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                String dev = scanner.next();
                String st = scanner.next().toLowerCase();
                if (st.equals("online") || st.equals("active") || st.equals("true") || st.equals("1") || st.equals("yes")) {
                    System.out.println(dev);
                }
            }
        }
    }
}