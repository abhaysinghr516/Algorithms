# Huffman Coding Compression Algorithm

Huffman Coding is a lossless data compression algorithm that works by assigning variable-length codes to input characters based on their frequencies. Characters with higher frequencies are assigned shorter codes, while characters with lower frequencies are assigned longer codes.

## Time Complexity

Best: O(n + k _ log(k))
Average: O(n + k _ log(k))
Worst: O(n + k \* log(k))

## Space Complexity

O(k)

## Example Use Case

Compressing text data, such as documents or web pages, to reduce storage space or transmission time.
