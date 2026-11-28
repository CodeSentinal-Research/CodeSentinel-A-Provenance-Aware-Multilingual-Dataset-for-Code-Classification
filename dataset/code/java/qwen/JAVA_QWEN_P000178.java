import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        
        ArrayList<int[]> list = new ArrayList<>();
        for (int key : freqMap.keySet()) {
            list.add(new int[]{key, freqMap.get(key)});
        }
        
        Collections.sort(list, (a, b) -> {
            if (b[1] != a[1]) return b[1] - a[1];
            return a[0] - b[0];
        });
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int[] item : list) {
            for (int i = 0; i < item[1]; i++) {
                result.add(item[0]);
            }
        }
        
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(result.get(i));
        }
        System.out.println();
    }
}
