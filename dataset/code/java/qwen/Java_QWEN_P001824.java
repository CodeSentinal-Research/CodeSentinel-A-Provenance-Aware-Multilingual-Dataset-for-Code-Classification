import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] seq1 = new int[n];
        for(int i=0; i<n; i++) seq1[i] = sc.nextInt();
        int[] seq2 = new int[n];
        for(int i=0; i<n; i++) seq2[i] = sc.nextInt();
        
        // Check if both sequences generate same BST structure
        System.out.println(generateSignature(seq1).equals(generateSignature(seq2)) ? "YES" : "NO");
    }
    
    static String generateSignature(int[] arr) {
        if(arr.length == 0) return "";
        StringBuilder sb = new StringBuilder();
        sb.append(arr[0]);
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        for(int i=1; i<arr.length; i++) {
            if(arr[i] < arr[0]) left.add(arr[i]);
            else right.add(arr[i]);
        }
        int[] lArr = left.stream().mapToInt(i->i).toArray();
        int[] rArr = right.stream().mapToInt(i->i).toArray();
        sb.append("(").append(generateSignature(lArr)).append(")");
        sb.append("(").append(generateSignature(rArr)).append(")");
        return sb.toString();
    }
}
