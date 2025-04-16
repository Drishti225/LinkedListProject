#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void append(int x) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;

    if (head == NULL) {
        head = new;
    } else {
        struct node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new;
    }
}

void append_beginning(int x) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->next = head;
    head = new;
}

void append_anywhere(int x, int pos) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = x;

    if (pos == 0) {
        new->next = head;
        head = new;
        return;
    }

    struct node *curr = head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Invalid position!\n");
        free(new);
        return;
    }

    new->next = curr->next;
    curr->next = new;
}

void del_begin() {
    if (head == NULL) return;
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void del_anywhere(int pos) {
    if (head == NULL) return;

    if (pos == 0) {
        del_begin();
        return;
    }

    struct node *p = head;
    struct node *q = head->next;

    for (int i = 0; i < pos - 1 && q != NULL; i++) {
        p = p->next;
        q = q->next;
    }

    if (q == NULL) {
        printf("Invalid position!\n");
        return;
    }

    p->next = q->next;
    free(q);
}

void del_end() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}

void display() {
    struct node *curr = head;
    printf("Linked List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int choice, pos, val;
    do {
        printf("\nMenu:\n");
        printf("1. Append at end\n");
        printf("2. Append at beginning\n");
        printf("3. Append at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from position\n");
        printf("6. Delete from end\n");
        printf("7. Display list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                append(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                append_beginning(val);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                append_anywhere(val, pos);
                break;
            case 4:
                del_begin();
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                del_anywhere(pos);
                break;
            case 6:
                del_end();
                break;
            case 7:
                display();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
