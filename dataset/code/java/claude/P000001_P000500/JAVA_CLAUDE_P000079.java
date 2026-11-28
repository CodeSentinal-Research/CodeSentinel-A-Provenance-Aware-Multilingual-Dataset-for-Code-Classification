public class Solution {
    public int[] convertSeconds(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int rem = totalSeconds % 3600;
        int minutes = rem / 60;
        int seconds = rem % 60;
        return new int[]{hours, minutes, seconds};
    }
}
