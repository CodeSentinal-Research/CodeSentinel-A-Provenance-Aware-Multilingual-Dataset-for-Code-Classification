import java.util.*;
public class Solution {
    public boolean isAnagram(String s1, String s2) {
        char[] a = s1.toCharArray(), b = s2.toCharArray();
        Arrays.sort(a); Arrays.sort(b);
        return Arrays.equals(a, b);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next(), s2 = sc.next();
        System.out.println(new Solution().isAnagram(s1, s2) ? "Anagram" : "Not Anagram");
    }
}
