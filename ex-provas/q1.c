// 1) Simule a execução do programa abaixo, mostrando o que será impresso na tela na coluna da direita  após o printf de “Exemplo”

#include <stdio.h>

void set(int *i, int v) {
    *i = v;
}
void soma(int *a, int v) {
    *a = *a + v;
}

void main() {
    int i = 1, h = 3, n = 0, r = 0, *p;
    int v[5];
    printf("Exemplo\n");
    v[0] = 5;
    v[1] = 4;
    v[2] = 3;
    v[3] = 2;
    v[4] = 1;
    set(&i, 0); // i = 0
    set(&h, 0); // h = 0
    p = &h; // p -> h = 3
    while (i < 3) { // i == 0 ==> i == 1 ==> i == 2
        printf("%d\n", h); // 0 ==> 0 ==> 1
        soma(p, i); // p -> h = (0 + i == 0) = 0 ==> p -> h = (0 + i == 1) = 1 ==> p -> h = (1 + i == 2) = 3
        i++; //i = 1 ==> i = 2 ==> i == 3
    }
    n = r + i; // n = r=0 + i=3 == 3
    printf("n = %d\n", n); // n = 3
    printf("H = %d\n", *p); // H = 5

    set(&v[0], 20); //v[0] = 20
    p = &v[0]; // p -> v[0] = 20
    *p = 90; // p -> v[0] = 90
    set(&r, n + 2); // r=0 = n=3 + 2 == 5
    set(&n, n * n); //n=3 = 3 * 3 == 9 
    printf("v[0] = %d\n", *p); //v[0] = 90
    printf("r = %d\n", r); // r = 5
    printf("n = %d\n", n); // n = 9
    printf("P = %d\n", *(p + 1)); // P -> v[0] ==> P + 1 -> v[0+1] ==> P + 1 -> v[1] == 4
    p++; // p -> V[1]
    printf("P = %d\n", *(p + 1)); // P -> v[1] ==> P + 1 -> v[1+1] ==> P + 1 -> v[2] == 3
}