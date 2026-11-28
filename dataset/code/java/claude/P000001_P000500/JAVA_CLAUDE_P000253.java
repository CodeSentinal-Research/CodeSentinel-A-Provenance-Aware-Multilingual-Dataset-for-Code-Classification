import java.util.Scanner;
public class Solution {
    public int countVowels(String s) {
        int count = 0;
        for (char c : s.toCharArray())
            if ("aeiouAEIOU".indexOf(c) >= 0) count++;
        return count;
    }
    public static void main(String[] args) {
        String s = new Scanner(System.in).nextLine();
        System.out.println(new Solution().countVowels(s));
    }
}
