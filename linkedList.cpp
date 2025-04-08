// code to implement and demonstrate variour operation on linked list such as traverse,insertion and deletion

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

typedef struct {
    node *first;
} list;

list *makelist(void) {
    list *l = (list *)malloc(sizeof(list));
    l->first = NULL;
    return l;
}

void createlist(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = NULL;

    if (l->first == NULL) {
        l->first = n;
    } else {
        node *p = l->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
    }
}

void firstnode(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = l->first;
    l->first = n;
}

void maddnode(list *l, int p, int v) {
    node *t = l->first;
    while (t != NULL && t->info != p) {
        t = t->next;
    }
    if (t == NULL) return;

    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = t->next;
    t->next = n;
}

void laddnode(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = NULL;

    if (l->first == NULL) {
        l->first = n;
    } else {
        node *p = l->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
    }
}

void printlist(list *l) {
    node *t = l->first;
    while (t != NULL) {
        printf("%d ->", t->info);
        t = t->next;
    }
    printf("NULL\n");
}
void dellist(list *l, int v) {
    node *t = l->first;
    node *s = NULL;

    if (t == NULL) return;

    if (t->info == v) {
        l->first = t->next;
        free(t);
        return;
    }

    while (t != NULL && t->info != v) {
        s = t;
        t = t->next;
    }

    if (t != NULL) {
        s->next = t->next;
        free(t);
    }
}
int main() {
    list *ls = makelist();
    int a, i, v, p;

    printf("ENTER VAL IN LIST:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a);
        createlist(ls, a);
    }
    printlist(ls);

    printf("\nENTER FIRST NODE IN LIST: ");
    scanf("%d", &v);
    firstnode(ls, v);
    printlist(ls);

    printf("\nENTER NODE IN MIDDLE:\n");
    printf("ntr prev. node: ");
    scanf("%d", &p);
    printf("ENTER new node: ");
    scanf("%d", &v);
    maddnode(ls, p, v);
    printlist(ls);

    printf("\nENTER LAST NODE: ");
    scanf("%d", &v);
    laddnode(ls, v);
    printlist(ls);

    printf("\nENTER val 2 b del = ");
    scanf("%d", &v);
    dellist(ls, v);
    printlist(ls);
    return 0;
}
