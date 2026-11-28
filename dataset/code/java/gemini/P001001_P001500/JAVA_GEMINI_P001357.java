public class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                String s1 = num.substring(0, i), s2 = num.substring(i, j);
                if ((s1.charAt(0) == '0' && s1.length() > 1) || (s2.charAt(0) == '0' && s2.length() > 1)) {
                    continue;
                }

                long n1 = Long.parseLong(s1), n2 = Long.parseLong(s2);
                int k = j;
                while (k < n) {
                    long n3 = n1 + n2;
                    String s3 = String.valueOf(n3);
                    if (!num.startsWith(s3, k)) break;
                    k += s3.length();
                    n1 = n2;
                    n2 = n3;
                }
                if (k == n) return true;
            }
        }
        return false;
    }
}