#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

void print_book(Book* b) {
    printf("Title: %s, Pages: %d, Price: %.1f\n", b->title, b->pages, b->price);
}

int main() {
    Book* p = (Book*)malloc(sizeof(Book));
    p->title = (char*)malloc(13 * sizeof(char));
    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750.0;
    
    print_book(p);
    
    free(p->title);
    free(p);
    return 0;
}
