import java.util.Scanner;
public class Solution {
    public String toggleCase(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray())
            sb.append(Character.isUpperCase(c) ? Character.toLowerCase(c) : Character.toUpperCase(c));
        return sb.toString();
    }
    public static void main(String[] args) {
        System.out.println(new Solution().toggleCase(new Scanner(System.in).next()));
    }
}
