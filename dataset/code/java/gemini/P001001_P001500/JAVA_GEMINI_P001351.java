import java.util.*;

public class CombinationIterator {
    private List<String> list = new ArrayList<>();
    private int idx = 0;

    private void backtrack(String characters, int len, int start, StringBuilder sb) {
        if (sb.length() == len) {
            list.add(sb.toString());
            return;
        }
        for (int i = start; i < characters.length(); i++) {
            sb.append(characters.charAt(i));
            backtrack(characters, len, i + 1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    public CombinationIterator(String characters, int combinationLength) {
        backtrack(characters, combinationLength, 0, new StringBuilder());
    }

    public String next() {
        return list.get(idx++);
    }

    public boolean hasNext() {
        return idx < list.size();
    }
}