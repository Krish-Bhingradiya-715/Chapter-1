#include <stdio.h>
#define MAX 10
int stack[MAX];
int sp = 0; 
void push(int x) {
    if(sp < MAX) stack[sp++] = x;
    else printf("Stack full\n");
}
int pop() {
    if(sp > 0) return stack[--sp];
    else { printf("Stack empty\n"); return 0; }
}
int main() {
    int choice, val;
    while(1) {
        printf("\n1: Push 2: Pop 3: Top 4: Duplicate 5: Swap 6: Clear 0: Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                printf("Popped: %d\n", pop());
                break;
            case 3:
                if(sp>0) printf("Top: %d\n", stack[sp-1]);
                else printf("Stack empty\n");
                break;
            case 4:
                if(sp>0) push(stack[sp-1]);
                else printf("Stack empty\n");
                break;
            case 5: 
                if(sp>1) { int t = stack[sp-1]; stack[sp-1]=stack[sp-2]; stack[sp-2]=t; }
                else printf("Need 2 elements to swap\n");
                break;
            case 6: 
                sp = 0;
                printf("Stack cleared\n");
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
