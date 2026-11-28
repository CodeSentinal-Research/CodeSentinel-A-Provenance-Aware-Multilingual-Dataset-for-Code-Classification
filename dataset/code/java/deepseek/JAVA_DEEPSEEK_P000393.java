import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        Trie trie = new Trie();
        for (int i = 0; i < n; i++) {
            trie.insert(scanner.nextLine());
        }
        String prefix = scanner.nextLine();
        List<String> results = trie.search(prefix);
        for (String result : results) {
            System.out.println(result);
        }
    }
}

class TrieNode {
    TrieNode[] children = new TrieNode[26];
    List<String> contacts = new ArrayList<>();
}

class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
            node.contacts.add(word);
        }
    }

    public List<String> search(String prefix) {
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            node = node.children[prefix.charAt(i) - 'a'];
            if (node == null) {
                return new ArrayList<>();
            }
        }
        return node.contacts;
    }
}
