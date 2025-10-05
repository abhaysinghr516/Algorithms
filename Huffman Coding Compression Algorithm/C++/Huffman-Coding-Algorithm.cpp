#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

struct NodeComparator {
    bool operator()(Node* l, Node* r) {
        return l->data > r->data;
    }
};

void preOrder(Node *root, string s, vector<string>& ans) {
    if (!root) {
        return;
    }
    
    if (!root->left && !root->right) {
        ans.push_back(s);
        return;
    }
    
    preOrder(root->left, s + "0", ans);
    preOrder(root->right, s + "1", ans);
}

vector<string> huffmanCodes(vector<int> frequencies) {
    priority_queue<Node*, vector<Node*>, NodeComparator> minHeap;

    for (int freq : frequencies) {
        Node *temp = new Node(freq);
        minHeap.push(temp);
    }
    
    while (minHeap.size() > 1) {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        
        Node *parent = new Node(left->data + right->data);
        parent->left = left;
        parent->right = right;
        
        minHeap.push(parent);
    }
    
    Node *root = minHeap.top();
    minHeap.pop();
    
    vector<string> ans;
    if (!root->left && !root->right) {
        ans.push_back("0");
    } else {
        preOrder(root, "", ans);
    }
    
    return ans;
}

int main() {
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};
    
    vector<string> codes = huffmanCodes(frequencies);
    
    cout << "Frequencies: ";
    for (int freq : frequencies) {
        cout << freq << " ";
    }
    cout << endl;
    
    cout << "Huffman codes: ";
    for (string code : codes) {
        cout << code << " ";
    }
    cout << endl;
    
    for (int i = 0; i < frequencies.size(); i++) {
        cout << "Frequency " << frequencies[i] << " -> Code: " << codes[i] << endl;
    }
    
    return 0;
}