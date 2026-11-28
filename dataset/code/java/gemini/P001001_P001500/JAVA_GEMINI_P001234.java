import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            int[] dep = new int[n];
            for (int i = 0; i < n; i++) dep[i] = sc.nextInt();

            Arrays.sort(arr);
            Arrays.sort(dep);

            int i = 0, j = 0;
            int platNeeded = 0, maxPlat = 0;

            while (i < n && j < n) {
                if (arr[i] <= dep[j]) {
                    platNeeded++;
                    maxPlat = Math.max(maxPlat, platNeeded);
                    i++;
                } else {
                    platNeeded--;
                    j++;
                }
            }
            System.out.println(maxPlat);
        }
        sc.close();
    }
}