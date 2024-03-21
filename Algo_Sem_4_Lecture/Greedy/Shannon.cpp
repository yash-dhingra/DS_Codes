#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
    char symbol;
    int frequency;
    string code;
    Node *left;
    Node *right;

    Node(char s, int f) : symbol(s), frequency(f), code(""), left(nullptr), right(nullptr) {}
};

bool compareNodes(const Node *a, const Node *b)
{
    return a->frequency > b->frequency;
}

void shannonFano(vector<Node *> &nodes, int start, int end)
{
    if (start == end)
        return;

    if (start + 1 == end)
    {
        nodes[start]->code += "0";
        nodes[end]->code += "1";
        return;
    }

    int totalFrequency = 0;
    for (int i = start; i <= end; ++i)
    {
        totalFrequency += nodes[i]->frequency;
    }

    int halfFrequency = 0;
    int partitionIndex = start;

    while (halfFrequency <= totalFrequency / 2)
    {
        halfFrequency += nodes[partitionIndex]->frequency;
        partitionIndex++;
    }

    for (int i = start; i < partitionIndex; ++i)
    {
        nodes[i]->code += "0";
    }
    for (int i = partitionIndex; i <= end; ++i)
    {
        nodes[i]->code += "1";
    }

    shannonFano(nodes, start, partitionIndex - 1);
    shannonFano(nodes, partitionIndex, end);
}

int main()
{
    string input;
    cout << "Enter input string: ";
    cin >> input;

    vector<Node *> nodes;
    for (char c : input)
    {
        bool found = false;
        for (Node *node : nodes)
        {
            if (node->symbol == c)
            {
                node->frequency++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            nodes.push_back(new Node(c, 1));
        }
    }

    sort(nodes.begin(), nodes.end(), compareNodes);

    shannonFano(nodes, 0, nodes.size() - 1);

    cout << "Symbol\tFrequency\tCode\n";
    for (Node *node : nodes)
    {
        cout << node->symbol << "\t" << node->frequency << "\t\t" << node->code << "\n";
    }

    for (Node *node : nodes)
    {
        delete node;
    }

    return 0;
}
