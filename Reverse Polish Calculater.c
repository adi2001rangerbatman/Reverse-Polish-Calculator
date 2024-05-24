#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Define the stack structure
typedef struct {
    int top;
    double items[STACK_SIZE];
} Stack;

// Function prototypes
void push(Stack *s, double value);
double pop(Stack *s);
double calculate(char op, double a, double b);
void initStack(Stack *s);

int main() {
    system("color b");// define the text color
    Stack stack;
    initStack(&stack); // Initialize stack using initStack function

    char token;
    double operand, a, b;

    // Home Display
    printf("\t\t\t\t\t=============================\n");
    printf("\t\t\t\t\tReverse Polish Calculator\n");
    printf("\t\t\t\t\t=============================\n\n");
    printf("\t\t\t\t\tEnter your math expression: ");

    while (1) {
        scanf("%c", &token);
        if (token == '?') {
            scanf("%lf", &operand);
            push(&stack, operand);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            b = pop(&stack);
            a = pop(&stack);
            push(&stack, calculate(token, a, b));
        } else if (token == '=') {
            printf("\t\t\t\t\t>>>%lf\n", stack.items[stack.top]);
            printf("\n\t\t\t\t\t");
        } else if (token == '#') { // Stop condition
            printf("\t\t\t\t\tGood Day!\n");
            break;
        }
    }

    return 0;
}

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Push a value onto the stack
void push(Stack *s, double value) {
    if (s->top == STACK_SIZE - 1) {
        printf("\t\t\t\t\tStack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

// Pop a value from the stack
double pop(Stack *s) {
    if (s->top == -1) {
        printf("\t\t\t\t\tStack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Perform arithmetic operation
double calculate(char op, double a, double b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("\t\t\t\t\tDivision by zero\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            printf("\t\t\t\tInvalid operator\n");
            exit(EXIT_FAILURE);
    }
}