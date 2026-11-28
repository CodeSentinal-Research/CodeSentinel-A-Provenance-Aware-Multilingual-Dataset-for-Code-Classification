public class Solution {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c > 'A') sb.append(' ');
            sb.append(c);
        }
        System.out.println(sb.toString());
    }
}