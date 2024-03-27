#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double process(double num[], int size, int iteration);

int main() {

    printf("Enter a comma-separated list of numbers (e.g., 1,2,3,4,5,6,7,8): ");
    char input[100];  
    scanf("%s", input);

    // Count the number of commas to determine the number of elements
    int count = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ',') {
            count++;
        }
    }

    char* str = malloc(sizeof(char) * (strlen(input) + 1));
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(str, input); 

    char* token = strtok(str, ",");
    int counter = 0;
    double* nums = malloc(sizeof(double) * count);  

    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        free(str);
        return 1;
    }

    while (token != NULL && counter < count) {
        // Convert token to double
        double ret = strtod(token, NULL);
        nums[counter++] = ret;
        token = strtok(NULL, ",");
    }

    // Print the parsed numbers
    printf("Parsed numbers:\n");
    for (int i = 0; i < counter; i++) {
        printf("%lf\n", nums[i]);
    }

    
    
    process(nums, sizeof(nums), 3);

    free(nums);
    free(str);

    return 0;
}


double process(double num[], int size, int iteration) {
    int start = iteration;
    int end = size - 1; 
    double result = 0;
    int i;

    for (i = start; i <= end; i++) {
        // if greater or less than array break loop
        if (i - 3 < 0 || i + 3 >= size) {
            break;
        }
        else {
            result = num[i - 3] + num[i - 2] + num[i - 1] + num[i] + num[i + 1] + num[i + 2] + num[i + 3];
            printf("%.lf\n", result);
        }
    }

    return result; 
}
