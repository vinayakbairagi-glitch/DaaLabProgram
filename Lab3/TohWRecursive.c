#include <stdio.h>
struct Stack
{
    int n;
    char source, intermediate, destination;
};
struct Stack stack[100];
int top = -1;
void push(int n, char source, char intermediate, char destination)
{
    stack[++top].n = n;
    stack[top].source = source;
    stack[top].intermediate = intermediate;
    stack[top].destination = destination;
}
struct Stack pop()
{
    return stack[top--];
}
int main()
{
    int n;
    struct Stack current;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    push(n, 'A', 'B', 'C');
    while (top != -1)
    {
        current = pop();
        if (current.n == 1)
        {
            printf("Move disk 1 from %c to %c\n",
                   current.source, current.destination);
        }
        else
        {
            push(current.n - 1,
                 current.source,
                 current.destination,
                 current.intermediate);
            push(1,
                 current.source,
                 current.intermediate,
                 current.destination);
            push(current.n - 1,
                 current.intermediate,
                 current.source,
                 current.destination);
        }
    }
    return 0;
}