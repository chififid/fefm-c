#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* ptr;
};
typedef struct node Node;

int main() {
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    
    n1->value = 100;
    n1->ptr = n2;
    
    n2->value = 200;
    n2->ptr = n3;
    
    n3->value = 300;
    n3->ptr = n1;
    
    Node* current = n1;
    for (int i = 0; i < 10; i++) {
        printf("%d ", current->value);
        current = current->ptr;
    }
    printf("\n");
    
    free(n1);
    free(n2);
    free(n3);
    return 0;
}
