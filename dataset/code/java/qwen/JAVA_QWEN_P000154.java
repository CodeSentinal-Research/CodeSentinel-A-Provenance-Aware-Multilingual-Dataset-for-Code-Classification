import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }
        
        long expectedSum = (long) n * (n + 1) / 2;
        long missing = expectedSum - (sum - getDuplicate(arr));
        System.out.println(missing + " " + getDuplicate(arr));
    }
    
    private static int getDuplicate(int[] arr) {
        boolean[] seen = new boolean[arr.length + 1];
        for (int num : arr) {
            if (seen[num]) return num;
            seen[num] = true;
        }
        return -1;
    }
}
