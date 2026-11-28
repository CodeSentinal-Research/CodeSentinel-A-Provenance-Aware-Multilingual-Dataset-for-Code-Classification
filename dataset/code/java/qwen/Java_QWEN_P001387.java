import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[m];
        for(int i=0; i<n; i++) arr1[i] = sc.nextInt();
        for(int i=0; i<m; i++) arr2[i] = sc.nextInt();
        
        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        for(int num : arr1) map1.put(num, map1.getOrDefault(num, 0) + 1);
        for(int num : arr2) map2.put(num, map2.getOrDefault(num, 0) + 1);
        
        System.out.println(map1.equals(map2) ? "YES" : "NO");
    }
}
