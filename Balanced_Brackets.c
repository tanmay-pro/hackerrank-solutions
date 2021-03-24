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
ll pop(ptrnode p); // Remove element from front

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
    pnew->next = p->next;
    p->next = pnew;
}

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->data = e;
    p->next = NULL;
    return p;
}

void printstack(ptrnode p)
{
    while (p->next != NULL)
    {
        p = p->next;
        printf("%lld ", p->data);
    }
    br;
}

ll pop(ptrnode p)
{
    if (p->next != NULL)
    {
        ptrnode temp = p;
        temp = temp->next;
        p->next = temp->next;
        ll element = temp->data;
        free(temp);
        return element;
    }
    return 0;
}

int main()
{
    ll t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        ptrnode p;
        p = createnode(0);
        char str[1000];
        fo(i, 1000)
        {
            str[i] = ' ';
        }
        scanf("%s", str);
        int length = 0;
        fo(i, 1000)
        {
            if (str[i] != ' ')
                length++;
        }
        bool set = true;
        fo(i, length)
        {
            if (str[i] == '(')
                push_front(p, 1);
            else if (str[i] == '{')
                push_front(p, 2);
            else if (str[i] == '[')
                push_front(p, 3);
            else if (str[i] == ')')
            {
                ll element = pop(p);
                if (element != 1)
                {
                    set = false;
                    break;
                }
            }
            else if (str[i] == '}')
            {
                ll element = pop(p);
                if (element != 2)
                {
                    set = false;
                    break;
                }
            }
            else if (str[i] == ']')
            {
                ll element = pop(p);
                if (element != 3)
                {
                    set = false;
                    break;
                }
            }
        }
        if (pop(p))
            set = false;
        if (set == true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}