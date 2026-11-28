import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> barcodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            barcodes.add(scanner.nextInt());
        }
        System.out.println(Arrays.toString(rearrangeBarcodes(barcodes)));
    }

    public static int[] rearrangeBarcodes(List<Integer> barcodes) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int barcode : barcodes) {
            freqMap.put(barcode, freqMap.getOrDefault(barcode, 0) + 1);
        }

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> freqMap.get(b) - freqMap.get(a));
        maxHeap.addAll(freqMap.keySet());

        while (maxHeap.size() > 1) {
            int maxFreq = maxHeap.poll();
            int secondMaxFreq = maxHeap.poll();

            maxHeap.add(maxFreq);
            maxHeap.add(secondMaxFreq);
        }

        int[] result = new int[barcodes.size()];
        int index = 0;
        while (!maxHeap.isEmpty()) {
            int maxFreq = maxHeap.poll();
            for (int i = 0; i < maxFreq; i++) {
                result[index++] = maxFreq;
                if (index == result.length) {
                    return result;
                }
            }
        }
        return result;
    }
}
