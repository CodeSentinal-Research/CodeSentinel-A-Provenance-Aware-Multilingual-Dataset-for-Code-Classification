import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[2*n];
        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
            arr[i+n] = sc.nextInt();
        }
        
        Arrays.sort(arr);
        int platforms = 1;
        int maxPlatforms = 1;
        int i=1, j=n;
        while(i<2*n && j<2*n) {
            if(arr[i] < arr[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }
            maxPlatforms = Math.max(maxPlatforms, platforms);
        }
        System.out.println(maxPlatforms);
    }
}
