import java.util.Scanner;
public class Solution {
    public String concatenate(String s1, String s2) { return s1 + s2; }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(new Solution().concatenate(sc.next(), sc.next()));
    }
}
