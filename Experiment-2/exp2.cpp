#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = code == "" ? "0" : code;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

string decode(Node* root, string encoded) {
    string result = "";
    Node* curr = root;
    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;
        if (!curr->left && !curr->right) {
            result += curr->ch;
            curr = root;
        }
    }
    return result;
}

int main() {
    string input;
    getline(cin, input);

    if (input.length() == 0) return 0;

    map<char, int> freq;
    for (char c : input) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto p : freq) pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();

    map<char, string> codes;
    generateCodes(root, "", codes);

    string encoded = "";
    for (char c : input) encoded += codes[c];

    string decoded = decode(root, encoded);

    cout << input << endl;
    cout << encoded << endl;
    cout << decoded << endl;

    return 0;
}
