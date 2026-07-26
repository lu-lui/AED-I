#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle);

int main() {
    // testes
    char *haystack_1 = "morango";
    char *needle_1 = "rango";

    char *haystack_2 = (char *)malloc(10000 *sizeof(char));
    char *needle_2 = (char *)malloc(10000 *sizeof(char));

    printf("haystack: ");
    scanf("%s", haystack_2);

    printf("needle: ");
    scanf("%s", needle_2);

    haystack_2 = (char *)realloc(haystack_2, (strlen(haystack_2) + 1) * sizeof(char));
    needle_2   = (char *)realloc(needle_2, (strlen(needle_2) + 1) * sizeof(char));

    //resultados
    printf("Teste 1: %d\n", strStr(haystack_1, needle_1)); // esperado: 2
    printf("Teste 2: %d\n", strStr(haystack_2, needle_2));

    free(haystack_2);
    free(needle_2);

    return 0;
}


int strStr(char* haystack, char* needle) {

    for(int i = 0; haystack[i] != '\0'; i++){
        int j = 0;

        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++; 
        }

        if (needle[j] == '\0'){
            return i;
        }   
    }

    return -1;
}