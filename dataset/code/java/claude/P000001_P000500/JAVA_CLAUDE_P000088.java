public class Solution {
    public boolean isPerfectSquare(int num) {
        if (num < 0) return false;
        long r = (long) Math.sqrt(num);
        return r * r == num;
    }
}
