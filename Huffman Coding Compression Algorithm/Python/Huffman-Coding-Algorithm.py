import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
    def __lt__(self, other):
        return self.data < other.data

def preOrder(root, s, ans):
    if not root:
        return
    
    if not root.left and not root.right:
        ans.append(s)
        return
    
    preOrder(root.left, s + "0", ans)
    preOrder(root.right, s + "1", ans)

def huffmanCodes(frequencies):
    min_heap = []
    
    for freq in frequencies:
        node = Node(freq)
        heapq.heappush(min_heap, node)
    
    while len(min_heap) > 1:
        left = heapq.heappop(min_heap)
        right = heapq.heappop(min_heap)
        
        parent = Node(left.data + right.data)
        parent.left = left
        parent.right = right
        
        heapq.heappush(min_heap, parent)
    
    root = heapq.heappop(min_heap)
    
    ans = []
    if not root.left and not root.right:
        ans.append("0")
    else:
        preOrder(root, "", ans)
    
    return ans

if __name__ == "__main__":
    frequencies = [5, 9, 12, 13, 16, 45]
    
    codes = huffmanCodes(frequencies)
    
    print("Frequencies:", frequencies)
    print("Huffman codes:", codes)
    
    for i, code in enumerate(codes):
        print(f"Frequency {frequencies[i]} -> Code: {code}")