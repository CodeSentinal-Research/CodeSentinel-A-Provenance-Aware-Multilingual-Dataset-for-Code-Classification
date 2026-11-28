import java.util.*;

public class Solution {
    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        String word = null;
    }

    private void dfs(char[][] board, int r, int c, TrieNode node, List<String> res) {
        char ch = board[r][c];
        if (ch == '#' || node.children[ch - 'a'] == null) return;

        TrieNode next = node.children[ch - 'a'];
        if (next.word != null) {
            res.add(next.word);
            next.word = null;
        }

        board[r][c] = '#';
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int[] d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < board.length && nc >= 0 && nc < board[0].length && board[nr][nc] != '#') {
                dfs(board, nr, nc, next, res);
            }
        }
        board[r][c] = ch;
    }

    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = new TrieNode();
        for (String w : words) {
            TrieNode node = root;
            for (char c : w.toCharArray()) {
                if (node.children[c - 'a'] == null) node.children[c - 'a'] = new TrieNode();
                node = node.children[c - 'a'];
            }
            node.word = w;
        }

        List<String> res = new ArrayList<>();
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
}