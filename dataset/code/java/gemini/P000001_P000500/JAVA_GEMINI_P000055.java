public class Solution {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        for (char c = 'Z'; c >= 'A'; c--) {
            if (c < 'Z') sb.append(' ');
            sb.append(c);
        }
        System.out.println(sb.toString());
    }
}