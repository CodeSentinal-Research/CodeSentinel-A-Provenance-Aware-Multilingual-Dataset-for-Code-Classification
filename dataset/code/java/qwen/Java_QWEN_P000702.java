import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();
        System.out.println(countOcc(arr, 0, target));
    }
    static int countOcc(int[] arr, int i, int target) {
        if(i >= arr.length) return 0;
        return (arr[i] == target ? 1 : 0) + countOcc(arr, i + 1, target);
    }
}
