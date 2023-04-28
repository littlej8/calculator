#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>

#define clear() system("cls")
#define OPTIONS "'+': add two numbers\n'-': subtract two numbers\n'*': multiply two numbers\n'/': divide two numbers\n'^': square a number\n'\\': get the square root of a number"

enum OPERATIONS
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    SQUARE,
    SQRT,
};

int get_op();
void get_nums(int op, float *a, float *b);
float evaluate(int op, float a, float b);

int main(int argc, char **argv)
{
    clear();

    printf("%s\n", "Welcome to the calculator!");
    printf("%s\n", "Press any key to continue...");
    getch();

    int op;
    float a, b;

    op = get_op();

    clear();

    get_nums(op, &a, &b);

    clear();

    float ret = evaluate(op, a, b);

    if (isinf(ret))
    {
        printf("%s\n", "The operation return infinity");
    }
    else
    {
        printf("%s%.6g\n", "The operation returned: ", ret);
    }

    return 0;
}

int get_op()
{
    clear();
    int op;
    printf("%s\n", "Please enter an operation:\n\n" OPTIONS);
    scanf(" %c", &op);
    switch(op)
    {
        case '+': return ADD; break;
        case '-': return SUBTRACT; break;
        case '*': return MULTIPLY; break;
        case '/': return DIVIDE; break;
        case '^': return SQUARE; break;
        case '\\': return SQRT; break;
        default: 
        {
            printf("%s\n", "Please enter a correct operation");
            printf("%s\n", "Press any key to continue...");
            getch();
            return get_op();
        } break;
    }
}

void get_nums(int op, float *a, float *b)
{
    clear();

    printf("%s\n", "Enter the first number:");
    scanf("%f", a);

    if (op != SQUARE && op != SQRT)
    {
        clear();

        printf("%s\n", "Enter the second number:");
        scanf("%f", b);
    }
}

float evaluate(int op, float a, float b)
{
    switch(op)
    {
        case ADD: return a + b; break;
        case SUBTRACT: return a - b; break;
        case MULTIPLY: return a * b; break;
        case DIVIDE: return a / b; break;
        case SQUARE: return a * a; break;
        case SQRT: return sqrt(a); break;
    }
}