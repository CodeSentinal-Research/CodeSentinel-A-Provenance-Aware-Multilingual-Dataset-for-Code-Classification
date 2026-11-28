import java.util.*;

public class Solution {
    static class Node {
        String word;
        int index;
        Node(String w, int i) { word = w; index = i; }
    }

    public int numMatchingSubseq(String s, String[] words) {
        List<Node>[] heads = new ArrayList[26];
        for (int i = 0; i < 26; i++) heads[i] = new ArrayList<>();

        for (String w : words) {
            heads[w.charAt(0) - 'a'].add(new Node(w, 0));
        }

        int ans = 0;
        for (char c : s.toCharArray()) {
            List<Node> cur = heads[c - 'a'];
            heads[c - 'a'] = new ArrayList<>();

            for (Node node : cur) {
                node.index++;
                if (node.index == node.word.length()) {
                    ans++;
                } else {
                    heads[node.word.charAt(node.index) - 'a'].add(node);
                }
            }
        }
        return ans;
    }
}