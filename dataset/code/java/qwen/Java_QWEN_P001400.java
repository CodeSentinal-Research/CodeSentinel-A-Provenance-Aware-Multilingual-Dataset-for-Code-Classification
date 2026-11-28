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
        
        Set<Integer> set1 = new TreeSet<>();
        Set<Integer> set2 = new TreeSet<>();
        for(int num : arr1) set1.add(num);
        for(int num : arr2) set2.add(num);
        
        List<Integer> only1 = new ArrayList<>(set1);
        only1.removeAll(set2);
        
        List<Integer> only2 = new ArrayList<>(set2);
        only2.removeAll(set1);
        
        for(int num : only1) System.out.print(num + " ");
        System.out.println();
        for(int num : only2) System.out.print(num + " ");
    }
}
