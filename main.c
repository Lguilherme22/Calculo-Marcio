#include <stdio.h>

int factorial(unsigned int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double permutation(int withRepetition, int n, int k) {
    if (withRepetition) {
        double result = 1.0;
        for (int i = 0; i < k; i++) {
            result *= n;
        }
        return result;
    } else {
        if (n < k) return 0.0;
        return (double) factorial(n) / factorial(n - k);
    }
}

double combination(int withRepetition, int n, int k) {
    if (withRepetition) {
        if (n <= 0) return 0.0;
        return (double) factorial(n + k - 1) / (factorial(k) * factorial(n - 1));
    } else {
        if (n < k) return 0.0;
        return (double) factorial(n) / (factorial(k) * factorial(n - k));
    }
}

int main() {
    int firstLevel = 0, secondLevel = 0;
    double result;
    int n, k;

    do {
        printf("\nMAIN MENU\n");
        printf("[1] Analise Combinatoria SEM Repeticao\n");
        printf("[2] Analise Combinatoria COM Repeticao\n");
        printf("[3] Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &firstLevel);

        switch (firstLevel) {
            case 1:
                do {
                    printf("SUBMENU: Sem Repeticao\n");
                    printf("[1] P(n) - Permutacao\n");
                    printf("[2] A(n,k) - Arranjo\n");
                    printf("[3] C(n,k) - Combinacao\n");
                    printf("[4] Voltar ao MENU PRINCIPAL\n");
                    printf("Escolha uma opcao:\n");
                    scanf("%d", &secondLevel);

                    switch (secondLevel) {
                        case 1:
                            printf("Enter n: ");
                            scanf("%d", &n);
                            result = factorial(n);
                            printf("P(%d) = %.0lf\n", n, result);
                            printf("Pressione Enter para continuar...");
                            getchar(); getchar();
                            break;
                        case 2:
                            printf("Enter n: ");
                            scanf("%d", &n);
                            printf("Enter k: ");
                            scanf("%d", &k);
                            result = permutation(0, n, k);
                            printf("A(%d, %d) = %.0lf\n", n, k, result);
                            printf("Pressione Enter para continuar...");
                            getchar(); getchar();
                            break;
                        case 3:
                            printf("Enter n: ");
                            scanf("%d", &n);
                            printf("Enter k: ");
                            scanf("%d", &k);
                            result = combination(0, n, k);
                            printf("C(%d, %d) = %.0lf\n", n, k, result);
                            printf("Pressione Enter para continuar...");
                            getchar(); getchar();
                            break;
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida.\n");
                            printf("Pressione Enter para continuar...");
                            getchar(); getchar();
                            break;
                    }
                } while (secondLevel != 4);
                break;

            case 2:
                do {
                    printf("\nSUBMENU: Com Repetição\n");
                    printf("[1] AR(n,k) - Arranjo com repeticao\n");
                    printf("[2] CR(n,k) - Combinacao com repeticao\n");
                    printf("[3] Voltar para menu principal\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &secondLevel);

                    switch (secondLevel) {
                        case 1:
                            printf("Enter n: ");
                            scanf("%d", &n);
                            printf("Enter k: ");
                            scanf("%d", &k);
                            result = permutation(1, n, k);
                            printf("AR(%d, %d) = %.0lf\n", n, k, result);
                            printf("Pressione Enter para continuar...");
                            getchar(); getchar();
                            break;
                        case 2:
                            printf("Enter n: ");
                            scanf("%d", &n);
                            printf("Enter k: ");
                            scanf("%d", &k);
                            result = combination(1, n, k);
                            printf("CR(%d, %d) = %.0lf\n", n, k, result);
                            printf("Pressione Enter para continuar...");
                            getchar(); getchar();
                            break;
                        case 3:
                            break;
                        default:
                            printf("Opcao invalida.\n");
                            printf("Pressione Enter para continuar...");
                            getchar(); getchar();
                            break;
                    }
                } while (secondLevel != 3);
                break;

            case 3:
                printf("O programa foi finalizado.... Obrigado\n");
                break;

            default:
                printf("Opcao invalidaa.\n");
                printf("Pressione Enter para continuar...");
                getchar(); getchar();
                break;
        }
    } while (firstLevel != 3);

    return 0;
}