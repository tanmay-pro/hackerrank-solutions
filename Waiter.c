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

void push_front(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    if (p->next == NULL)
    {
        p->rear = pnew;
    }
    else
    {
        p->next->prev = pnew;
    }
    pnew->next = p->next;
    p->next = pnew;
    pnew->prev = p;
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
    ll el;
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

void printans(ptrnode p)
{
    while (p->next != NULL)
    {
        p = p->next;
        printf("%lld ", p->data);
        br;
    }
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

int main()
{
    ll n, q;
    scanf("%lld %lld", &n, &q);
    ptrnode p;
    p = createnode(0);
    ll x;
    fo(i, n)
    {
        scanf("%lld", &x);
        push_back(p, x);
    }
    ll is_composite[x + 5];
    fo(i, x + 5)
    {
        is_composite[i] = 0;
    }
    is_composite[0] = is_composite[1] = 1;
    for (int i = 2; i * i <= x; i++)
        if (!is_composite[i])
            for (int j = i * i; j <= x; j += i)
                is_composite[j] = 1;

    ptrnode primes;
    primes = createnode(0);
    int c = 0;
    for (ll i = 0; i <= n; i++)
    {
        if (!is_composite[i] && c <= size(p))
        {
            push_back(primes, i);
            c++;
        }
        else if (c > size(p))
        {
            break;
        }
    }
    printans(primes);
    ptrnode b;
    b = createnode(0);
    int i = 1;
    p = p->next;
    primes = primes->next;
    while (i <= size(primes))
    {
        ll temp = size(p);
        for (int j = 1; j <= temp; j++)
        {
            ll ele = pop(p);
            if (ele % primes->data == 0)
            {
                push_back(b, ele);
            }
            else
            {
                push_back(p, ele);
            }
        }
        primes = primes->next;
    }
    for (int i = 0; i < size(b); i++)
    {
        b = b->next;
        printf("%lld\n", b->data);
    }
    return 0;
}