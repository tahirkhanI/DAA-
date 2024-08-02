#include <stdio.h>

typedef struct {
    int weight, value;
    float ratio;
} Item;

void sortItems(Item items[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++)
        for ( j = i + 1; j < n; j++)
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
}

float knapsack(Item items[], int n, int capacity) {
	int i;
    sortItems(items, n);
    int currentWeight = 0;
    float totalValue = 0.0;

    for ( i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = capacity - currentWeight;
            totalValue += items[i].value * (float)remain / items[i].weight;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n,i,capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter weight and value for each item:\n");
    for ( i = 0; i < n; i++) {
        printf("Item %d weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d value: ", i + 1);
        scanf("%d", &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Maximum value: %.2f\n", knapsack(items, n, capacity));
    return 0;
}

