import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] answers = new int[n];
        for(int i=0; i<n; i++) answers[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int ans : answers) freq.put(ans, freq.getOrDefault(ans, 0) + 1);
        
        int rabbits = 0;
        for(Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            int k = entry.getKey();
            int v = entry.getValue();
            rabbits += (v + k) / (k + 1) * (k + 1);
        }
        System.out.println(rabbits);
    }
}
