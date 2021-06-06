//
// Created by Benjamin on 2021. 04. 23..
//

#include "DynamicList.h"

DynamicList* createDL() {
    DynamicList *node = (DynamicList*)calloc(1, sizeof(DynamicList));
    node->next = NULL;
    return node;
}

void fillList(DynamicList **front, int *array, int length) {
    for(int i = 0; i < length; ++i) {
        addLast(&(*front), array[i]);
    }
}

void insertSorted(DynamicList **front, int value) {
    DynamicList *new = createDL();
    new->info = value;
    if((*front) == NULL) {
        (*front) = new;
        return;
    }
    if((*front)->info > new->info) {
        addFirst(&(*front), new->info);
        return;
    }
    DynamicList *node = (*front), *help = NULL;
    while(node != NULL && node->info < new->info) {
        help = node;
        node = node->next;
    }
    if(node == NULL) {
        addLast(&(*front), new->info);
        return;
    }
    new->next = node;
    help->next = new;
}

void addFirst(DynamicList **front, int value) {
    DynamicList *new = createDL();
    new->info = value;
    new->next = (*front);
    (*front) = new;
}

void addLast(DynamicList **front, int value) {
    DynamicList *new = createDL();
    new->info = value;
    new->next = NULL;
    if((*front) == NULL) {
        (*front) = new;
    } else {
        DynamicList *node = (*front);
        while(node->next != NULL) {
            node = node->next;
        }
        node->next = new;
    }
}

int searchInList(DynamicList *front, int value) {
    if(front == NULL) {
        return 0;
    }
    DynamicList *node = front;
    while(node->next != NULL) {
        if(node->info == value) {
            return 1;
        } else {
            node = node->next;
        }
    }
    if(node->next == NULL && node->info != value) {
        return 0;
    }
}

void deleteFirst(DynamicList **front) {
    if((*front) == NULL) {
        printf("The list is empty!\n");
        return;
    }
    DynamicList *node = (*front);
    (*front) = (*front)->next;
    freeNode(&node);
}

void deleteLast(DynamicList **front) {
    if((*front) == NULL) {
        printf("The list is empty!\n");
        return;
    }
    DynamicList *node = (*front);
    while (node->next->next != NULL) {
        node = node->next;
    }
    DynamicList *temp = node->next;
    node->next = NULL;
    freeNode(&temp);
}

void deleteValue(DynamicList **front, int value) {
    if((*front) == NULL) {
        printf("The list is empty!\n");
        return;
    }
    DynamicList *node = (*front), *help = NULL;
    while(node != NULL && node->info != value) {
        help = node;
        node = node->next;
    }
    if(node != NULL) {
        if(help == NULL) {
            (*front) = node->next;
        } else {
            help->next = node->next;
        }
        freeNode(&node);
    } else {
        printf("This value isn't in the list!\n");
    }
}

void deleteAll(DynamicList **front) {
    while((*front) != NULL) {
        DynamicList *node = (*front);
        (*front) = (*front)->next;
        freeNode(&node);
    }
}

void freeNode(DynamicList **node) {
    (*node)->info = 0;
    (*node)->next = NULL;
    free((*node));
}

void printList(DynamicList *front) {
    if(front == NULL) {
        printf("List is empty!\n");
        return;
    }
    DynamicList *node = front;
    while(node != NULL) {
        printf("%d ", node->info);
        node = node->next;
    }
    printf("\n");
}
