public class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] orderMap = new int[26];
        for (int i = 0; i < order.length(); i++) orderMap[order.charAt(i) - 'a'] = i;

        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i], w2 = words[i + 1];
            int len = Math.min(w1.length(), w2.length());
            boolean flag = false;

            for (int j = 0; j < len; j++) {
                if (w1.charAt(j) != w2.charAt(j)) {
                    if (orderMap[w1.charAt(j) - 'a'] > orderMap[w2.charAt(j) - 'a']) return false;
                    flag = true;
                    break;
                }
            }
            if (!flag && w1.length() > w2.length()) return false;
        }
        return true;
    }
}