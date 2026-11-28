public class Solution {
    // Sorts the input array into ordered sequence.
    public void waveSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i += 2) {
            if (i > 0 && arr[i] < arr[i - 1]) {
                int temp = arr[i]; arr[i] = arr[i - 1]; arr[i - 1] = temp;
            }
            if (i < n - 1 && arr[i] < arr[i + 1]) {
                int temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
            }
        }
    }
}