#include <stdio.h>

int main() {
    int n = 14;

    int profit[14]   = {22,19,29,28,30,21,27,25,24,26,14,27,19,11};
    int deadline[14] = {3,3,8,6,7,5,10,4,6,12,13,2,14,1};
    int job[14];

    int slot[15];   // slots from 1 to 14
    int i, j;

    // Initialize job numbers
    for(i = 0; i < n; i++)
        job[i] = i + 1;

    // Initialize slots as empty
    for(i = 1; i <= 14; i++)
        slot[i] = -1;

    // Step 1: Sort jobs by profit (Descending) using simple bubble sort
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(profit[j] < profit[j+1]) {
                // Swap profit
                int temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                // Swap deadline
                temp = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = temp;

                // Swap job number
                temp = job[j];
                job[j] = job[j+1];
                job[j+1] = temp;
            }
        }
    }

    int totalProfit = 0;

    // Step 2: Assign jobs to slots
    for(i = 0; i < n; i++) {
        for(j = deadline[i]; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = job[i];
                totalProfit = totalProfit + profit[i];
                break;
            }
            else {
                // Slot already filled, try previous slot
            }
        }
    }

    // Step 3: Display result
    printf("Selected Jobs:\n");
    for(i = 1; i <= 14; i++) {
        if(slot[i] != -1)
            printf("Slot %d -> Job %d\n", i, slot[i]);
    }

    printf("\nMaximum Profit = %d\n", totalProfit);

    return 0;
}
