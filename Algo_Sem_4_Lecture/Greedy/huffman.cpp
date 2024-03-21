#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
    char data;
    unsigned frequency;
    Node *left, *right;
};

Node *createNode(char data, unsigned frequency)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

void generateCodes(Node *root, string code, unordered_map<char, string> &codes)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        codes[root->data] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

void huffmanCoding(string text)
{
    unordered_map<char, unsigned> frequency;
    for (char ch : text)
    {
        frequency[ch]++;
    }

    priority_queue<Node *, vector<Node *>, CompareNodes> pq;
    for (auto &pair : frequency)
    {
        pq.push(createNode(pair.first, pair.second));
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *newNode = createNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    unordered_map<char, string> codes;
    generateCodes(pq.top(), "", codes);

    cout << "Huffman Codes:\n";
    for (auto &pair : codes)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
}

int main()
{
    string text = "hello world";
    huffmanCoding(text);
    return 0;
}
