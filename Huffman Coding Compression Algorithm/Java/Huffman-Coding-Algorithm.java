import java.util.*;

class Node {
    int data;
    Node left;
    Node right;
    
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class NodeComparator implements Comparator<Node> {
    public int compare(Node x, Node y) {
        return Integer.compare(x.data, y.data);
    }
}

class HuffmanCodingAlgorithm {
    
    static void preOrder(Node root, String s, List<String> ans) {
        if (root == null) {
            return;
        }
        
        if (root.left == null && root.right == null) {
            ans.add(s);
            return;
        }
        
        preOrder(root.left, s + "0", ans);
        preOrder(root.right, s + "1", ans);
    }
    
    static List<String> huffmanCodes(int[] frequencies) {
        PriorityQueue<Node> minHeap = new PriorityQueue<>(new NodeComparator());
        
        for (int freq : frequencies) {
            Node temp = new Node(freq);
            minHeap.add(temp);
        }
        
        while (minHeap.size() > 1) {
            Node left = minHeap.poll();
            Node right = minHeap.poll();
            
            Node parent = new Node(left.data + right.data);
            parent.left = left;
            parent.right = right;
            
            minHeap.add(parent);
        }
        
        Node root = minHeap.poll();
        
        List<String> ans = new ArrayList<>();
        if (root.left == null && root.right == null) {
            ans.add("0");
        } else {
            preOrder(root, "", ans);
        }
        
        return ans;
    }
    
    public static void main(String[] args) {
        int[] frequencies = {5, 9, 12, 13, 16, 45};
        
        List<String> codes = huffmanCodes(frequencies);
        
        System.out.println("Frequencies: " + Arrays.toString(frequencies));
        System.out.println("Huffman codes: " + codes);
        
        for (int i = 0; i < frequencies.length; i++) {
            System.out.println("Frequency " + frequencies[i] + " -> Code: " + codes.get(i));
        }
    }
}