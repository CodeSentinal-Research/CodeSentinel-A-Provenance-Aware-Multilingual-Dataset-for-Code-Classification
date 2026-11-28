import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        while (scanner.hasNext()) {
            String word = scanner.next();
            int mask = 0;
            for (char c : word.toLowerCase().toCharArray()) {
                for (int r = 0; r < 3; r++) {
                    if (rows[r].indexOf(c) != -1) {
                        mask |= (1 << r);
                        break;
                    }
                }
            }
            if (Integer.bitCount(mask) == 1) {
                System.out.println(word);
            }
        }
    }
}