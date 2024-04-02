#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdint.h> 

// Declare the assembly function
extern double asm_process(double* X, double* Y, int size);

// Function prototypes
void init_X(double* X, int size);
void c_process(double* X, double* Y, int size);

int main() {
    int size;
    int iterations;
    int printlimit;

    printf("Enter the size of the array: ");
    scanf_s(" %d", &size); 
    //printf("Enter how many times the function should run: ");
    //scanf_s(" %d", &iterations);
    
    double* X = malloc(size * sizeof(double));
    int Y_size = size - 6;
    double* AYout = malloc(Y_size * sizeof(double));
    double* CYout = malloc(Y_size * sizeof(double));

    // Fill X with random numbers
    if (size > 16) {
        printlimit = 10;
    }
    else {
        printlimit = Y_size;
    }


    init_X(X, size);

    // Print X for debugging
    printf("X array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%lf ", X[i]);
    }
    printf("\n");


    // Call the C function
    clock_t t;
    t = clock();
    for (int i = 0; i < 30; i++) {
        c_process(X, CYout, size);
    }
    t = clock() - t;
    double c_time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("C TIME: %lf sec\n", c_time_taken);

    // Print the result from the C function
    printf("Result from C function:\n");
    for (int i = 0; i < printlimit; i++) {
        printf("%lf\n", CYout[i]);
    }
    printf("\n");


    // Call the assembly function

    clock_t a;
    a = clock();
    for (int i = 0; i < 30; i++){
        asm_process(X, AYout, Y_size);
    }
    a = clock() - a;
    double a_time_taken = ((double)a) / CLOCKS_PER_SEC;
    printf("ASSEMBLY TIME: %Lf sec\n", a_time_taken);

    // Print the result from the assembly function
    printf("Result from Assembly function:\n");
    for (int i = 0; i < printlimit; i++) {
        printf("%lf\n", AYout[i]);
    }
    printf("\n");

    // Free allocated memory
    free(X);
    free(CYout);
    free(AYout);
    return 0;
}

void init_X(double* X, int size) {
    // Seed the random number generator with current time
    srand(time(NULL));

    // Fill X with random numbers
    for (int i = 0; i < size; i++) {
        X[i] = (double)rand();
    }
}

void c_process(double* X, double* Y, int size) {
    // Process the array using C
    int end = size - 1;
    int i;
    int counter = 0;
    for (i = 3; i <= end; i++) { 

        if (i - 3 < 0 || i + 3 >= size) {
            break;
        }
        else {
            Y[counter] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
            counter++;
        }


    }
}
