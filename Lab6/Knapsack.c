#include <stdio.h>
struct Item {
    int weight;
    int profit;
    float ratio;
};
int main() {
    int n, capacity, i, j;
    float totalProfit = 0.0;
    struct Item temp;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (capacity == 0) {
            break;
        }
        if (items[i].weight <= capacity) {
            capacity = capacity - items[i].weight;
            totalProfit = totalProfit + items[i].profit;
            printf("Selected complete item: Weight = %d, Profit = %d\n",
                   items[i].weight, items[i].profit);
        } else {
            float fraction = (float)capacity / items[i].weight;
            totalProfit = totalProfit +
                          items[i].profit * fraction;
            printf("Selected %.2f fraction of item: Weight = %d, Profit = %d\n",
                   fraction, items[i].weight, items[i].profit);
            capacity = 0;
        }
    }
    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;
}