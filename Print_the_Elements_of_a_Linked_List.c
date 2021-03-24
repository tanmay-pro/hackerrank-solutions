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

typedef struct Node node;
typedef struct Node *ptrnode;
typedef long long elementtype;

struct Node
{
    elementtype element;
    ptrnode next;
};

ptrnode createnode(elementtype e);
ptrnode createemptylist();
void insertatrear(ptrnode p, elementtype e);

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->element = e;
    p->next = NULL;
    return p;
}

ptrnode createemptylist()
{
    ptrnode p = createnode(0);
    return p;
}

//Inserts a node at the end of the list
void insertatrear(ptrnode p, elementtype e)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptrnode pnew = createnode(e);
    pnew->next = NULL;
    p->next = pnew;
}

int main()
{

    ptrnode p;
    p = createnode(0);
    ll t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        ll e;
        scanf("%lld", &e);
        insertatrear(p, e);
    }
    while (p->next != NULL)
    {
        p = p->next;
        printf("%lld\n", p->element);
    }
    return 0;
}