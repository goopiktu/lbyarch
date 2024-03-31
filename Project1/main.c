#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern double process(double nums[], int size);

int main() {
    

    printf("Enter a comma-separated list of numbers (e.g., 1,2,3,4,5,6,7,8): ");
    char input[100];
    scanf_s("%s", input, (unsigned)_countof(input)); // Specify the size of the buffer

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

    strcpy_s(str, strlen(input) + 1, input); // Specify the size of the destination buffer

    char* token = NULL;
    char* context = NULL; // For strtok_s
    token = strtok_s(str, ",", &context); // Pass the context pointer

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
        token = strtok_s(NULL, ",", &context); // Pass the context pointer
    }

    // Print the parsed numberss
    printf("Parsed numbers:\n");
    for (int i = 0; i < counter; i++) {
        printf("%lf\n", nums[i]);
    }

    
    // Call the assembly function

    double result = process(nums, counter);

    // Print the result returned from assembly function
    printf("Result from assembly function: %d %d\n", result, counter);

    free(nums);
    free(str);

    return 0;
}
