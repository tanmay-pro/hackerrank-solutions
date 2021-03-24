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
typedef struct deque deque;
typedef struct deque *ptrdeque;

struct node
{
    elementtype data;
    ptrnode next;
    ptrnode rear;
    ptrnode prev;
};

void push_front(ptrnode p, elementtype data); // Insert at front
ptrnode createnode(elementtype data);
ll pop(ptrnode p);                           // Remove from front
void push_back(ptrnode p, elementtype data); // Insert at Rear
void eject(ptrnode p);                       // Remove item from rear
bool empty(ptrnode p);                       // Return whether the Queue is empty or not
int size(ptrnode p);                         // Return The size of Queue
elementtype front(ptrnode p);                // Return the first element of the queue
elementtype back(ptrnode p);                 // Return the last element of the queue

elementtype back(ptrnode p)
{
    return p->rear->data;
}

elementtype front(ptrnode p)
{
    return p->next->data;
}

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->data = e;
    p->next = NULL;
    p->prev = NULL;
    p->rear = NULL;
    return p;
}

ll pop(ptrnode p)
{
    ll el = -1;
    if (p->next != NULL)
    {
        if (p->next->next == NULL)
        {
            p->rear = p;
        }
        ptrnode temp = p;
        temp->next = p->next;
        temp = temp->next;
        el = temp->data;
        p->next = temp->next;
        free(temp);
    }
    return el;
}

void push_back(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    if (p->rear == NULL)
    {
        pnew->prev = p;
        p->next = pnew;
    }
    else
    {
        pnew->prev = p->rear;
        p->rear->next = pnew;
    }
    p->rear = pnew;
}

void eject(ptrnode p)
{
    if (p->rear != NULL)
    {
        ptrnode temp = p->rear;
        temp->prev->next = NULL;
        if (temp->prev != p)
            p->rear = temp->prev;
        else
        {
            p->rear = NULL;
        }
        free(temp);
    }
}

ll max(ll a, ll b, ll c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int main()
{
    ptrnode p1;
    p1 = createnode(0);
    ptrnode p2;
    p2 = createnode(0);
    ptrnode p3;
    p3 = createnode(0);
    ll c1, c2, c3;
    ll h1 = 0, h2 = 0, h3 = 0;
    scanf("%lld %lld %lld", &c1, &c2, &c3);
    fo(i, c1)
    {
        ll x;
        scanf("%lld", &x);
        push_back(p1, x);
        h1 += x;
    }
    fo(i, c2)
    {
        ll x;
        scanf("%lld", &x);
        push_back(p2, x);
        h2 += x;
    }
    fo(i, c3)
    {
        ll x;
        scanf("%lld", &x);
        push_back(p3, x);
        h3 += x;
    }
    bool set = true;
    while (h1 != h2 || h2 != h3)
    {
        ll max_el = max(h1, h2, h3);
        if (max_el == h1)
        {
            ll ret = pop(p1);
            if (ret == -1)
            {
                set = false;
                break;
            }
            else
            {
                h1 -= ret;
            }
        }
        else if (max_el == h2)
        {
            ll ret = pop(p2);
            if (ret == -1)
            {
                set = false;
                break;
            }
            else
            {
                h2 -= ret;
            }
        }
        else if (max_el == h3)
        {
            ll ret = pop(p3);
            if (ret == -1)
            {
                set = false;
                break;
            }
            else
            {
                h3 -= ret;
            }
        }
    }
    if (set == true)
    {
        printf("%lld\n", h1);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}