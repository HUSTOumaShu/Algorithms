#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000005

struct Node
{
    int data;
    Node *next;
};

Node *createNode()
{
    Node *node = new Node();
    node->data = 0;
    node->next = NULL;
    return node;
}

void addNode(Node *head, Node *node)
{
    if (head == NULL)
        head = node;
    Node *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}

int n, m;
int a[MAX];
Node b[MAX];

int main()
{
    int result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int j;
        Node *head = createNode();
        for (j = 0; j < i; j++)
        {
            Node *tmp = createNode();
            addNode(head, tmp);
        }
        j = i;
        Node *tmp = createNode();
        tmp->data = a[j];
        addNode(head, tmp);
        while (j < n)
        {
            if (a[j] > a[j + 1])
            {
            }
            else
            {
            }
            j++;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int prev, next;
        cin >> prev >> next;
        result += b[prev][next];
    }
    cout << result;
}
