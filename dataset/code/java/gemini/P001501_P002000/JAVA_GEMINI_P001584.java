import java.util.Scanner;

public class Solution {
    private static boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            int k = sc.nextInt();

            int l = 0, vCount = 0, maxLen = 0;

            for (int r = 0; r < s.length(); r++) {
                if (isVowel(s.charAt(r))) vCount++;
                while (vCount > k) {
                    if (isVowel(s.charAt(l++))) vCount--;
                }
                maxLen = Math.max(maxLen, r - l + 1);
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}