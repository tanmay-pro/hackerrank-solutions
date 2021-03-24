#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define ll long long
#define PI 3.14159265
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
int MOD = 1e9 + 7;

typedef long long elementtype;
typedef struct node node;
typedef struct node *ptrnode;

struct node
{
    elementtype data;
    ptrnode next;
};

void push_front(ptrnode p, elementtype data); // Insert element at front
ptrnode createnode(elementtype data);
ll pop(ptrnode p);     // Remove element from front
bool empty(ptrnode p); // Return whether the Stack is empty or not
int size(ptrnode p);   // Return The size of Stack

void print_stack(ptrnode p)
{
    while (p->next != NULL)
    {
        p = p->next;
        printf("%lld ", p->data);
    }
    br;
}

void push_front(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    pnew->next = p->next;
    p->next = pnew;
}

int size(ptrnode p)
{
    int c = 0;
    while (p->next != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

bool empty(ptrnode p)
{
    if (p->next == NULL)
    {
        return true;
    }
    else
        return false;
}

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->data = e;
    p->next = NULL;
    return p;
}

ll pop(ptrnode p)
{
    ll element;
    if (p->next != NULL)
    {
        ptrnode temp = p;
        temp->next = p->next;
        temp = temp->next;
        element = temp->data;
        p->next = temp->next;
        free(temp);
    }
    return element;
}

int main()
{
    ll t = 1;
    scanf("%lld", &t);
    ptrnode p;
    p = createnode(0);
    ll maximum = -MOD;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            ll r;
            scanf("%lld", &r);
            push_front(p, r);
            if (r > maximum)
            {
                maximum = r;
            }
        }
        else if (n == 2)
        {
            ll ele = pop(p);
            if (ele == maximum)
            {
                maximum = -MOD;
                ptrnode temp = p;
                if (temp->next != NULL)
                {
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                        if (temp->data > maximum)
                            maximum = temp->data;
                    }
                }
            }
        }
        else if (n == 3)
        {
            printf("%lld\n", maximum);
        }
    }
    return 0;
}