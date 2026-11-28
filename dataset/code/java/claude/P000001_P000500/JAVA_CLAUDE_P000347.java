import java.util.Scanner;
public class Solution {
    public String reverseString(String s) {
        return new StringBuilder(s).reverse().toString();
    }
    public static void main(String[] args) {
        String s = new Scanner(System.in).next();
        System.out.println(new Solution().reverseString(s));
    }
}
