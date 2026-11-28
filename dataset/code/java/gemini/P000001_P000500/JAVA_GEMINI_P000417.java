import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] titles = new String[n], authors = new String[n], genres = new String[n];
            for (int i = 0; i < n; i++) { titles[i] = scanner.next(); authors[i] = scanner.next(); genres[i] = scanner.next(); }
            String a = scanner.next(), g = scanner.next();
            for (int i = 0; i < n; i++) if (authors[i].equals(a) && genres[i].equals(g)) System.out.println(titles[i]);
        }
    }
}