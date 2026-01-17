#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int freq;
    Node *left, *right;

    Node(int f) {
        freq = f;
        left = right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void preorder(Node* root, vector<string>& ans, string curr) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(curr);
        return;
    }

    preorder(root->left, ans, curr + "0");
    preorder(root->right, ans, curr + "1");
}

vector<string> huffmanCodes(string s, vector<int>& f) {
    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < s.length(); i++) {
        pq.push(new Node(f[i]));
    }

    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();

        Node* newNode = new Node(l->freq + r->freq);
        newNode->left = l;
        newNode->right = r;

        pq.push(newNode);
    }

    Node* root = pq.top();
    vector<string> ans;
    preorder(root, ans, "");

    return ans;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    string s;
    cout << "Enter characters string: ";
    cin >> s;

    vector<int> freq(n);
    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    vector<string> res = huffmanCodes(s, freq);

    cout << "Huffman Codes:\n";
    for (string x : res)
        cout << x << " ";

    return 0;
}
