# Huffman Coding Compression Algorithm

Huffman Coding is a lossless data compression algorithm that works by assigning variable-length codes to input characters based on their frequencies. Characters with higher frequencies are assigned shorter codes, while characters with lower frequencies are assigned longer codes.

## Algorithm Overview

1. **Build Frequency Table**: Count the frequency of each character in the input.
2. **Create Leaf Nodes**: Create a leaf node for each character with its frequency.
3. **Build Min Heap**: Insert all leaf nodes into a priority queue (min heap) based on frequency.
4. **Build Huffman Tree**: 
   - Extract two nodes with minimum frequency
   - Create a new internal node with these two as children and frequency = sum of frequencies
   - Insert the new node back into the heap
   - Repeat until only one node remains (root of Huffman tree)
5. **Generate Codes**: Traverse the tree from root to leaves, assigning '0' for left edges and '1' for right edges.

## Time Complexity

- **Best**: O(n + k × log(k))
- **Average**: O(n + k × log(k))  
- **Worst**: O(n + k × log(k))

Where:
- n = length of input text
- k = number of unique characters

## Space Complexity

O(k) - for storing the Huffman tree and codes

## Algorithm Steps Visualization

```
Input: "aabccc"
Frequencies: a=2, b=1, c=3

Step 1: Create nodes and min heap
[b:1] [a:2] [c:3]

Step 2: Merge b:1 and a:2 -> internal:3
[internal:3] [c:3]

Step 3: Merge internal:3 and c:3 -> root:6
         root:6
        /      \
   internal:3   c:3
   /        \
  b:1       a:2

Step 4: Generate codes
- Left edge = '0', Right edge = '1'
- b: 00
- a: 01  
- c: 1
```

## Applications

- **File Compression**: ZIP files, JPEG compression
- **Data Transmission**: Reducing bandwidth usage
- **Text Compression**: Compressing documents and web pages
- **Network Protocols**: HTTP compression

## Example Usage

For the frequencies [5, 9, 12, 13, 16, 45], the algorithm generates optimal variable-length codes that minimize the total encoding length.
