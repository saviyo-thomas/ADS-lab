#include<stdio.h>
#include<stdbool.h>
#define size 3

int a[size], b = -1, f = -1;

void enq(int d);
void dq();
void count();
void dis();

bool isfull() {
    return (b + 1) % size == f;
}

bool isempty() {
    return f == -1;
}

int main() {
    int ch, d;
    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.print\n4.Count\n5.Exit\nEnter your choice :");
        if (scanf("%d", &ch) != 1) return 0;
        switch(ch) {
            case 1: {
                printf("Data :");
                if (scanf("%d", &d) == 1) { enq(d); }
                break;
                    }
            case 2: dq(); break;
            case 3: dis(); break;
            case 4: count(); break;
            case 5: return 0;
            default: printf("Enter valid input");
    }}
    return 0;
}

void enq(int d) {
    if (isfull()) {printf("Queue is full"); return; }
    if (f == -1) {f = 0; }
    b = (b + 1) % size;
    a[b] = d;
}

void dq() {
    if (isempty()) {printf("Queue is empty"); return; }
    printf("%d is dequeued", a[f]);
    if (f == b) { f = -1; b = -1;   } else { f = (f + 1) % size;}
}

void count() {
    if (isempty()) { printf("Queue is empty"); return; }
    int c;
    if (b >= f) { c = b - f + 1; }
    else { c = size - f + b + 1; }
    printf("Number of elements in queue: %d", c);
}

void dis() {
    if (isempty()) { printf("Queue is empty"); return;}
    int i = f;
    while (1) {
        printf("[%d] ", a[i]);
        if (i == b) break;
        i = (i + 1) % size;
    }
    printf("\n");
}
