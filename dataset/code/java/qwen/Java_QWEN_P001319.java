import java.util.*;
class TrieNode {
    TrieNode[] children = new TrieNode[26];
    boolean isWord = false;
}
public class Main {
    static TrieNode root;
    static Set<String> result;
    static char[][] board;
    static boolean[][] visited;
    static int r, c;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        board = new char[r][c];
        for(int i=0; i<r; i++) board[i] = sc.next().toCharArray();
        
        int n = sc.nextInt();
        root = new TrieNode();
        for(int i=0; i<n; i++) {
            String word = sc.next();
            insert(word);
        }
        
        result = new TreeSet<>();
        visited = new boolean[r][c];
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                dfs(i, j, root, new StringBuilder());
            }
        }
        
        for(String s : result) System.out.println(s);
    }
    
    static void insert(String word) {
        TrieNode node = root;
        for(char ch : word.toCharArray()) {
            if(node.children[ch-'a'] == null) node.children[ch-'a'] = new TrieNode();
            node = node.children[ch-'a'];
        }
        node.isWord = true;
    }
    
    static void dfs(int i, int j, TrieNode node, StringBuilder sb) {
        if(i < 0 || i >= r || j < 0 || j >= c || visited[i][j]) return;
        char ch = board[i][j];
        if(node.children[ch-'a'] == null) return;
        
        visited[i][j] = true;
        node = node.children[ch-'a'];
        sb.append(ch);
        
        if(node.isWord) result.add(sb.toString());
        
        dfs(i+1, j, node, sb);
        dfs(i-1, j, node, sb);
        dfs(i, j+1, node, sb);
        dfs(i, j-1, node, sb);
        
        sb.deleteCharAt(sb.length()-1);
        visited[i][j] = false;
    }
}
