// ============================================================
//  11 - Heaps
//  Topics: Min Heap, Max Heap (custom), Java PriorityQueue,
//          Heap Sort, K largest, median of stream
// ============================================================

import java.util.*;

public class Heaps {

    // ─────────────────────────────────────────
    // MIN HEAP (custom implementation using array)
    // Parent is always SMALLER than children
    // Parent of i: (i-1)/2
    // Left child:  2*i+1
    // Right child: 2*i+2
    // ─────────────────────────────────────────
    static class MinHeap {
        int[] arr;
        int size;

        MinHeap(int capacity) { arr = new int[capacity]; size = 0; }

        int parent(int i) { return (i - 1) / 2; }
        int left(int i)   { return 2 * i + 1; }
        int right(int i)  { return 2 * i + 2; }

        void swap(int i, int j) {
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }

        // Insert — O(log n)
        void insert(int val) {
            arr[size++] = val;
            heapifyUp(size - 1);
        }

        void heapifyUp(int i) {
            while (i > 0 && arr[parent(i)] > arr[i]) {
                swap(i, parent(i));
                i = parent(i);
            }
        }

        // Extract min — O(log n)
        int extractMin() {
            if (size == 0) return -1;
            int min = arr[0];
            arr[0] = arr[--size];
            heapifyDown(0);
            return min;
        }

        void heapifyDown(int i) {
            int smallest = i;
            int l = left(i), r = right(i);
            if (l < size && arr[l] < arr[smallest]) smallest = l;
            if (r < size && arr[r] < arr[smallest]) smallest = r;
            if (smallest != i) { swap(i, smallest); heapifyDown(smallest); }
        }

        int peek() { return size == 0 ? -1 : arr[0]; }
        boolean isEmpty() { return size == 0; }

        void print() {
            System.out.print("Heap: ");
            for (int i = 0; i < size; i++) System.out.print(arr[i] + " ");
            System.out.println();
        }
    }

    // ─────────────────────────────────────────
    // HEAP SORT — O(n log n)
    // Build max heap, then repeatedly extract max
    // ─────────────────────────────────────────
    static void heapSort(int[] arr) {
        int n = arr.length;
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) heapifyDown(arr, n, i);
        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr, 0, i);          // move current max to end
            heapifyDown(arr, i, 0);   // heapify reduced heap
        }
    }

    static void heapifyDown(int[] arr, int n, int i) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) { swap(arr, i, largest); heapifyDown(arr, n, largest); }
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }

    // ─────────────────────────────────────────
    // K LARGEST ELEMENTS using Min Heap
    // ─────────────────────────────────────────
    static int[] kLargest(int[] arr, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int x : arr) {
            minHeap.add(x);
            if (minHeap.size() > k) minHeap.poll(); // remove smallest
        }
        int[] result = new int[k];
        for (int i = k - 1; i >= 0; i--) result[i] = minHeap.poll();
        return result;
    }

    // ─────────────────────────────────────────
    // K SMALLEST ELEMENTS using Max Heap
    // ─────────────────────────────────────────
    static int[] kSmallest(int[] arr, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int x : arr) {
            maxHeap.add(x);
            if (maxHeap.size() > k) maxHeap.poll(); // remove largest
        }
        int[] result = new int[k];
        for (int i = k - 1; i >= 0; i--) result[i] = maxHeap.poll();
        return result;
    }

    // ─────────────────────────────────────────
    // KTH LARGEST ELEMENT
    // ─────────────────────────────────────────
    static int kthLargest(int[] arr, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int x : arr) {
            minHeap.add(x);
            if (minHeap.size() > k) minHeap.poll();
        }
        return minHeap.peek();
    }

    // ─────────────────────────────────────────
    // MEDIAN OF A STREAM
    // Use two heaps: maxHeap for lower half, minHeap for upper half
    // ─────────────────────────────────────────
    static class MedianFinder {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder()); // lower half
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();                          // upper half

        void addNum(int num) {
            maxHeap.add(num);
            minHeap.add(maxHeap.poll()); // balance: push max of lower to upper
            if (minHeap.size() > maxHeap.size())
                maxHeap.add(minHeap.poll()); // keep lower >= upper in size
        }

        double findMedian() {
            return maxHeap.size() > minHeap.size()
                ? maxHeap.peek()
                : (maxHeap.peek() + minHeap.peek()) / 2.0;
        }
    }

    // ─────────────────────────────────────────
    // MERGE K SORTED ARRAYS using Min Heap
    // ─────────────────────────────────────────
    static int[] mergeKSorted(int[][] arrays) {
        // PQ stores [value, arrayIndex, elementIndex]
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int total = 0;
        for (int i = 0; i < arrays.length; i++) {
            if (arrays[i].length > 0) {
                pq.offer(new int[]{arrays[i][0], i, 0});
                total += arrays[i].length;
            }
        }
        int[] result = new int[total];
        int idx = 0;
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            result[idx++] = curr[0];
            int ai = curr[1], ei = curr[2];
            if (ei + 1 < arrays[ai].length)
                pq.offer(new int[]{arrays[ai][ei + 1], ai, ei + 1});
        }
        return result;
    }

    // ─────────────────────────────────────────
    // MAIN
    // ─────────────────────────────────────────
    public static void main(String[] args) {
        System.out.println("╔══════════════════════════════╗");
        System.out.println("║           Heaps              ║");
        System.out.println("╚══════════════════════════════╝\n");

        // Custom Min Heap
        System.out.println("=== Custom Min Heap ===");
        MinHeap mh = new MinHeap(10);
        for (int x : new int[]{5, 3, 8, 1, 9, 2, 7}) mh.insert(x);
        mh.print();
        System.out.println("Min: " + mh.peek());
        System.out.print("Extract order: ");
        while (!mh.isEmpty()) System.out.print(mh.extractMin() + " ");
        System.out.println();

        // Java PriorityQueue
        System.out.println("\n=== Java PriorityQueue (Min Heap) ===");
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : new int[]{5, 3, 8, 1, 9}) pq.add(x);
        System.out.print("Poll order: ");
        while (!pq.isEmpty()) System.out.print(pq.poll() + " ");
        System.out.println();

        // Heap Sort
        System.out.println("\n=== Heap Sort ===");
        int[] arr = {4, 10, 3, 5, 1, 7};
        System.out.println("Before: " + Arrays.toString(arr));
        heapSort(arr);
        System.out.println("After : " + Arrays.toString(arr));

        // K Largest
        System.out.println("\n=== K Largest Elements ===");
        int[] data = {3, 2, 1, 5, 6, 4};
        System.out.println("3 largest in " + Arrays.toString(data) + ": "
            + Arrays.toString(kLargest(data, 3)));

        // K Smallest
        System.out.println("3 smallest in " + Arrays.toString(data) + ": "
            + Arrays.toString(kSmallest(data, 3)));

        // Kth Largest
        System.out.println("2nd largest: " + kthLargest(data, 2)); // 5

        // Median Finder
        System.out.println("\n=== Median of Stream ===");
        MedianFinder mf = new MedianFinder();
        int[] stream = {5, 15, 1, 3, 8, 7, 9, 2};
        for (int x : stream) {
            mf.addNum(x);
            System.out.printf("After adding %2d → Median: %.1f%n", x, mf.findMedian());
        }

        // Merge K Sorted Arrays
        System.out.println("\n=== Merge K Sorted Arrays ===");
        int[][] arrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
        System.out.println("Merged: " + Arrays.toString(mergeKSorted(arrays)));
    }
}
