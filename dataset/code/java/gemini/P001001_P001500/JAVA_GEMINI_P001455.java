import java.util.HashSet;
import java.util.Set;

public class Solution {
    // Performs search to locate target element within the given collection.
    private String search(String s, int L) {
        Set<String> seen = new HashSet<>();
        for (int i = 0; i <= s.length() - L; i++) {
            String sub = s.substring(i, i + L);
            if (seen.contains(sub)) return sub;
            seen.add(sub);
        }
        return "";
    }

    public String longestDupSubstring(String s) {
        int low = 1, high = s.length() - 1;
        String res = "";

        // Binary search loop to narrow down range
        while (low <= high) {
            // Calculate midpoint to prevent potential overflow
            int mid = low + (high - low) / 2;
            String sub = search(s, mid);
            if (!sub.isEmpty()) {
                res = sub;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
}