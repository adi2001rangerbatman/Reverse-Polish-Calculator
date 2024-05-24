#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Define the stack structure
typedef struct {
    int top;
    double items[STACK_SIZE];
} Stack;

// Function prototypes
void initializeStack(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);
double calculate(char op, double a, double b);
void printStack(const Stack *s);

int main() {
    // Commented out to avoid platform dependency
    // system("color b"); // Define the text color
    
    Stack stack;
    initializeStack(&stack);

    char token;
    double operand, a, b;

    // Home Display
    printf("\t\t\t\t\t=============================\n");
    printf("\t\t\t\t\t Reverse Polish Calculator\n");
    printf("\t\t\t\t\t=============================\n\n");
    printf("\t\t\t\t\tEnter your math expression: ");

    while (1) {
        scanf(" %c", &token); // Handle leading whitespaces
        if (token == '?') {
            scanf("%lf", &operand);
            push(&stack, operand);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            b = pop(&stack);
            a = pop(&stack);
            push(&stack, calculate(token, a, b));
        } else if (token == '=') {
            printf("\t\t\t\t\t>>> %lf\n", stack.items[stack.top]);
            printf("\n\t\t\t\t\t");
        } else if (token == '#') { // Stop condition
            printf("\t\t\t\t\tGood Day!\n");
            break;
        } else {
            printf("\t\t\t\t\tInvalid input\n");
        }
        printStack(&stack); // Print the stack state for debugging
    }

    return 0;
}

// Initialize the stack
void initializeStack(Stack *s) {
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
            printf("\t\t\t\t\tInvalid operator\n");
            exit(EXIT_FAILURE);
    }
}

// Print the stack for debugging
void printStack(const Stack *s) {
    printf("\t\t\t\t\tStack state: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%lf ", s->items[i]);
    }
    printf("\n");
}
