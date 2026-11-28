import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        
        int[] arr1 = new int[m];
        for (int i = 0; i < m; i++) arr1[i] = sc.nextInt();
        
        int[] order = new int[n];
        HashMap<Integer, Integer> orderMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            order[i] = sc.nextInt();
            orderMap.put(order[i], i);
        }
        
        ArrayList<Integer> inOrder = new ArrayList<>();
        ArrayList<Integer> notInOrder = new ArrayList<>();
        
        for (int num : arr1) {
            if (orderMap.containsKey(num)) {
                inOrder.add(num);
            } else {
                notInOrder.add(num);
            }
        }
        
        // Sort inOrder based on orderMap
        Collections.sort(inOrder, (a, b) -> orderMap.get(a) - orderMap.get(b));
        
        // Sort notInOrder naturally
        Collections.sort(notInOrder);
        
        inOrder.addAll(notInOrder);
        
        for (int i = 0; i < inOrder.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(inOrder.get(i));
        }
        System.out.println();
    }
}
