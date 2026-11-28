public class Main {
    public static int guess(int num) {
        // This is a placeholder for the actual implementation of the guess API.
        // It's not included in the problem statement because it's not relevant to the solution.
        return 0;
    }

    public static int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            } else if (res < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(guessNumber(10));
    }
}
