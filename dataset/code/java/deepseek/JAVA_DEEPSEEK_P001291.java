import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        List<Integer> cards = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            cards.add(scanner.nextInt());
        }
        System.out.println(canRearrange(cards, K) ? "YES" : "NO");
    }

    private static boolean canRearrange(List<Integer> cards, int K) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int card : cards) {
            countMap.put(card, countMap.getOrDefault(card, 0) + 1);
        }
        List<Map.Entry<Integer, Integer>> countList = new ArrayList<>(countMap.entrySet());
        countList.sort(Map.Entry.comparingByValue());
        int maxCount = countList.get(countList.size() - 1).getValue();
        if (maxCount > K) {
            return false;
        }
        int totalCount = 0;
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            totalCount += entry.getValue();
        }
        if (totalCount % K != 0) {
            return false;
        }
        int groupCount = totalCount / K;
        for (int i = 0; i < countList.size(); i++) {
            if (countList.get(i).getValue() != groupCount) {
                return false;
            }
        }
        return true;
    }
}
