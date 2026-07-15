// 2) Qual a complexidade no pior caso do seguinte algoritmo? Justifique. O(n)

int fun(int n) {
    int count = 0, i, j;
    for (i = n; i > 0; i /= 2)
        for (j = 0; j < i; j++)
            count += 1;
    return count;
}
