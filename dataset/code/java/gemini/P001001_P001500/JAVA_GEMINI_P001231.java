import java.util.Arrays;

public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int childPtr = 0, cookiePtr = 0;

        while (childPtr < g.length && cookiePtr < s.length) {
            if (s[cookiePtr] >= g[childPtr]) {
                childPtr++;
            }
            cookiePtr++;
        }
        return childPtr;
    }
}