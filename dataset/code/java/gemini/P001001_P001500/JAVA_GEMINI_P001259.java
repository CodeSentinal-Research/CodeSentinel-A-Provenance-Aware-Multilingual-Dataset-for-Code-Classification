import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLine()) {
            String s = sc.nextLine().trim();
            int unbalanced = 0;
            for (char c : s.toCharArray()) {
                if (c == '[') {
                    if (unbalanced > 0) unbalanced--;
                } else {
                    unbalanced++;
                }
            }
            System.out.println((unbalanced + 1) / 2);
        }
        sc.close();
    }
}