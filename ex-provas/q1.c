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
    set(&i, 0);
    set(&h, 0);
    p = &h;
    while (i < 3) {
        printf("%d\n", h);
        soma(p, i);
        i++;
    }
    n = r + i;
    printf("n = %d\n", n);
    printf("H = %d\n", *p);

    set(&v[0], 20);
    p = &v[0];
    *p = 90;
    set(&r, n + 2);
    set(&n, n * n);
    printf("v[0] = %d\n", *p);
    printf("r = %d\n", r);
    printf("n = %d\n", n);
    printf("P = %d\n", *(p + 1));
    p++;
    printf("P = %d\n", *(p + 1));
}