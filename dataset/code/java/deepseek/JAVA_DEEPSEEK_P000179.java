import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[] array1 = new int[m];
        int[] array2 = new int[n];

        for (int i = 0; i < m; i++) {
            array1[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            array2[i] = scanner.nextInt();
        }

        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : array1) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        List<Integer> list = new ArrayList<>();
        for (int num : array2) {
            if (countMap.containsKey(num)) {
                for (int i = 0; i < countMap.get(num); i++) {
                    list.add(num);
                }
                countMap.remove(num);
            }
       }

        List<Integer> remaining = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            for (int i = 0; i < entry.getValue(); i++) {
                remaining.add(entry.getKey());
            }
        }

        Collections.sort(remaining);
        list.addAll(remaining);

        for (int num : list) {
            System.out.print(num + " ");
        }
    }
}
