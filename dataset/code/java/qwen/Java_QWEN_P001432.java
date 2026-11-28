import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] dominoes = new int[n][2];
        for(int i=0; i<n; i++) {
            dominoes[i][0] = sc.nextInt();
            dominoes[i][1] = sc.nextInt();
        }
        
        Map<String, Integer> freq = new HashMap<>();
        long count = 0;
        
        for(int[] d : dominoes) {
            int a = Math.min(d[0], d[1]);
            int b = Math.max(d[0], d[1]);
            String key = a + "," + b;
            count += freq.getOrDefault(key, 0);
            freq.put(key, freq.getOrDefault(key, 0) + 1);
        }
        System.out.println(count);
    }
}
