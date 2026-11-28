import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        
        int[] hCuts = new int[r-1];
        for(int i=0; i<r-1; i++) hCuts[i] = sc.nextInt();
        
        int[] vCuts = new int[c-1];
        for(int i=0; i<c-1; i++) vCuts[i] = sc.nextInt();
        
        Arrays.sort(hCuts);
        Arrays.sort(vCuts);
        
        long cost = 0;
        int hPieces = 1;
        int vPieces = 1;
        
        int i = r-2;
        int j = c-2;
        
        while(i >= 0 && j >= 0) {
            if(hCuts[i] > vCuts[j]) {
                cost += (long)hCuts[i] * vPieces;
                hPieces++;
                i--;
            } else {
                cost += (long)vCuts[j] * hPieces;
                vPieces++;
                j--;
            }
        }
        
        while(i >= 0) {
            cost += (long)hCuts[i] * vPieces;
            i--;
        }
        
        while(j >= 0) {
            cost += (long)vCuts[j] * hPieces;
            j--;
        }
        
        System.out.println(cost);
    }
}
