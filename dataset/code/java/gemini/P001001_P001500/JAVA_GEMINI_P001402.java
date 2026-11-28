public class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] rem = new int[k];
        for (int x : arr) {
            int r = ((x % k) + k) % k;
            rem[r]++;
        }

        if (rem[0] % 2 != 0) return false;
        for (int i = 1; i <= k / 2; i++) {
            if (i * 2 == k) {
                if (rem[i] % 2 != 0) return false;
            } else if (rem[i] != rem[k - i]) {
                return false;
            }
        }
        return true;
    }
}