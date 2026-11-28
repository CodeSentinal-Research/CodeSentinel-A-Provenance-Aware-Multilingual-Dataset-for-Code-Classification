import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        Set<Integer> seen = new HashSet<>();
        for(int num : arr) {
            if(seen.contains(num)) { System.out.println(num); return; }
            seen.add(num);
        }
        System.out.println("-1");
    }
}
