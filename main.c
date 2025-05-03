// Felipe e Luis (1º Semestre FATEC ADS - Noturno)
#include <stdio.h>

int factorial(unsigned int n) {  
    int result = 1;
    
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

double permutation(int withRepetition, int n, int k) {
    int withoutRepetition = !withRepetition;

    if (withoutRepetition) {
        return 0.0;
    }

    if (withRepetition) {
        return 0.0;
    }

    return 0.0;
}

double combination(int withRepetition, int n, int k) {
    int withoutRepetition = !withRepetition;

    if (withoutRepetition) {
        if (n < k || n < 0 || k < 0) {
            printf("The passed value to n or k does not follow the combination without repetition rules.\n");
            return 0.0;
        }
        return (double) factorial(n) / (factorial(k) * factorial(n - k));
    }

    if (withRepetition) {
        if (n <= 0 || k < 0) {
            printf("The passed value to n or k does not follow the combination with repetition rules.\n");
            return 0.0;
        }
        return (double) factorial(n + k - 1) / (factorial(k) * factorial(n - 1));
    }

    return 0.0;
}

int main() {
    int firstLevel = 0;
    double result = 1.0;
    int n, k;
    int secondLevel;

    do {
        printf("MAIN MENU\n");
        printf("[1] Combinatorial Analysis without Repetition\n");
        printf("[2] Combinatorial Analysis with Repetition\n");
        printf("[3] Exit Program\n");
        printf("Enter an option to proceed:\n");
        scanf("%d", &firstLevel);
        switch (firstLevel) {
            case 1:
                do {
                    printf("SUBMENU: Without Repetition\n");
                    printf("[1] P(n)\n");
                    printf("[2] A(n,k)\n");
                    printf("[3] C(n,k)\n");
                    printf("[4] Back to MAIN MENU\n");
                    printf("Enter an option to proceed:\n");
                    scanf("%d", &secondLevel);
                    switch(secondLevel) {
                        case 1:
                            printf("Enter the n value:\n");
                            scanf("%d", &n);
                            break;
                        case 2:
                            printf("Enter the n value:\n");
                            scanf("%d", &n);
                            printf("Enter the k value:\n");
                            scanf("%d", &k);
                            break; 
                        case 3:
                            printf("Enter the n value:\n");
                            scanf("%d", &n);
                            printf("Enter the k value:\n");
                            scanf("%d", &k);
                            result = combination(0, n, k);
                            printf("Operation Result: %.0lf\n", result);
                            break; 
                        case 4:
                            printf("[4] Back to MAIN MENU\n");
                            firstLevel = 0;
                            break;
                    }
                } while (secondLevel == 0);
                break;
            case 2:
                do {
                    printf("SUBMENU: With Repetition\n");
                    printf("[1] PR(n)\n");
                    printf("[2] AR(n,k)\n");
                    printf("[3] CR(n,k)\n");
                    printf("[4] Back to MAIN MENU\n");
                    printf("Enter an option to proceed:\n");
                    scanf("%d", &secondLevel);
                    switch(secondLevel) {
                        case 1:
                            printf("[1] PR(n, k, n1, n2...,nk)\n");
                            break;
                        case 2:
                            printf("[2] AR(n,k)\n");
                            break; 
                        case 3:
                            printf("Enter the n value:\n");
                            scanf("%d", &n);
                            printf("Enter the k value:\n");
                            scanf("%d", &k);
                            result = combination(1, n, k);
                            printf("Operation Result: %lf", result);
                            break; 
                        case 4:
                            printf("[4] Back to MAIN MENU\n");
                            firstLevel = 0;
                            break;
                    }
                } while (secondLevel == 0);
                break;
            case 3:
                printf("Thanks. Come back when you need my help.");
                break;
            default:    
                printf("Invalid option, try again!\n");
                firstLevel = 0;
                break;
        }
    }   while(firstLevel == 0);
    
    return 0;
}