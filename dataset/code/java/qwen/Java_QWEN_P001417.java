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
        
        Map<Integer, Integer> order = new HashMap<>();
        for(int i=0; i<m; i++) order.put(arr2[i], i);
        
        List<Integer> inOrder = new ArrayList<>();
        List<Integer> notInOrder = new ArrayList<>();
        
        for(int num : arr1) {
            if(order.containsKey(num)) inOrder.add(num);
            else notInOrder.add(num);
        }
        
        inOrder.sort((a, b) -> order.get(a) - order.get(b));
        Collections.sort(notInOrder);
        inOrder.addAll(notInOrder);
        
        for(int x : inOrder) System.out.print(x + " ");
    }
}
