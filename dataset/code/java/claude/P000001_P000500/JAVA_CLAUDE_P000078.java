public class Solution {
    public int[] convertDays(int totalDays) {
        int years = totalDays / 365;
        int rem = totalDays % 365;
        int weeks = rem / 7;
        int days = rem % 7;
        return new int[]{years, weeks, days};
    }
}
