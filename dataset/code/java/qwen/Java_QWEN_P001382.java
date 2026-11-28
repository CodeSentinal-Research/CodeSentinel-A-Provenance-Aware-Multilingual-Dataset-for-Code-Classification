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
        
        Set<Integer> set1 = new HashSet<>();
        for(int num : arr1) set1.add(num);
        
        Set<Integer> intersection = new TreeSet<>();
        for(int num : arr2) {
            if(set1.contains(num)) intersection.add(num);
        }
        
        for(int num : intersection) System.out.print(num + " ");
    }
}
