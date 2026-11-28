import java.util.Arrays;

public class Solution {
    // Sorts the input array into ordered sequence.
    public String sort(String s) {
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        return new String(arr);
    }
}