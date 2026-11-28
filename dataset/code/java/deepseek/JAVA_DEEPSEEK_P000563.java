import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String beginWord = scanner.next();
        String endWord = scanner.next();
        int n = scanner.nextInt();
        List<String> wordList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            wordList.add(scanner.next());
        }
        System.out.println(ladderLength(beginWord, endWord, wordList));
    }

    public static int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(beginWord, 1));
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            if (current.word.equals(endWord)) {
                return current.numTransforms;
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (isOneCharDiff(current.word, wordList.get(i))) {
                    queue.offer(new Pair(wordList.get(i), current.numTransforms + 1));
                    wordList.remove(i);
                    break;
                }
            }
        }
        return 0;
    }

    public static boolean isOneCharDiff(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        int diffCount = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1.charAt(i) != word2.charAt(i)) {
                diffCount++;
            }
        }
        return diffCount == 1;
    }

    static class Pair {
        String word;
        int numTransforms;

        public Pair(String word, int numTransforms) {
            this.word = word;
            this.numTransforms = numTransforms;
        }
    }
}
