import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        int maxFreq = -1;
        int maxLucky = -1;
        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
            if (entry.getValue() > maxFreq) {
                maxFreq = entry.getValue();
                maxLucky = entry.getKey();
            }
        }
        System.out.println(maxLucky);
    }
}
