import java.util.*;
public class Main {
    static int[] parentA, parentB;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        parentA = new int[n + 1];
        parentB = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parentA[i] = i;
            parentB[i] = i;
        }
        
        int removed = 0;
        for (int i = 0; i < m; i++) {
            int type = sc.nextInt();
            int u = sc.nextInt();
            int v = sc.nextInt();
            
            if (type == 3) {
                if (findA(u) != findA(v)) {
                    unionA(u, v);
                    removed++;
                }
                if (findB(u) != findB(v)) {
                    unionB(u, v);
                    removed++;
                }
            } else if (type == 1) {
                if (findA(u) != findA(v)) {
                    unionA(u, v);
                    removed++;
                }
            } else if (type == 2) {
                if (findB(u) != findB(v)) {
                    unionB(u, v);
                    removed++;
                }
            }
        }
        
        // Check connectivity
        int rootA = findA(1);
        int rootB = findB(1);
        for (int i = 2; i <= n; i++) {
            if (findA(i) != rootA || findB(i) != rootB) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(m - removed);
    }
    
    static int findA(int i) {
        if (parentA[i] != i) parentA[i] = findA(parentA[i]);
        return parentA[i];
    }
    static void unionA(int i, int j) { parentA[findA(i)] = findA(j); }
    
    static int findB(int i) {
        if (parentB[i] != i) parentB[i] = findB(parentB[i]);
        return parentB[i];
    }
    static void unionB(int i, int j) { parentB[findB(i)] = findB(j); }
}
