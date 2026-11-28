import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        // Separate positives and negatives
        int[] pos = new int[n];
        int[] neg = new int[n];
        int pCount = 0, nCount = 0;
        
        for (int num : arr) {
            if (num >= 0) pos[pCount++] = num;
            else neg[nCount++] = num;
        }
        
        int i = 0, j = 0, idx = 0;
        boolean turnPositive = true;
        
        while (i < pCount && j < nCount) {
            if (turnPositive) {
                arr[idx++] = pos[i++];
            } else {
                arr[idx++] = neg[j++];
            }
            turnPositive = !turnPositive;
        }
        
        while (i < pCount) arr[idx++] = pos[i++];
        while (j < nCount) arr[idx++] = neg[j++];
        
        for (int k = 0; k < n; k++) {
            if (k > 0) System.out.print(" ");
            System.out.print(arr[k]);
        }
        System.out.println();
    }
}
