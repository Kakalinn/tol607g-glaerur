#include <stdio.h>
#include <stdlib.h>
typedef struct {int x, y;} ii;

int cmpx(const void* p1, const void* p2) {return ((ii*)p1)->x - ((ii*)p2)->x;}
int cmpy(const void* p1, const void* p2) {return ((ii*)p1)->y - ((ii*)p2)->y;}

void compress(int* a, int n)
{
    int i, j, x, k;
    ii b[n];
    for (i = 0; i < n; i++) b[i].x = a[i], b[i].y = i;                          // Búum til lista af tvenndum (a_i, i).
    qsort(b, n, sizeof(b[0]), cmpx);                                            // Röðum listanum eftir fyrra stakinu.
    for (i = k = 0; i < n; i = j, k++)
        for (j = i, x = b[i].x; j < n && b[j].x == x; j++)
            b[j].x = k;                                                         // Breytum i-tu tölunni í i.
    qsort(b, n, sizeof(b[0]), cmpy);                                            // Röðum eftir seinna stakinu (upphaflega röðun).
    for (i = 0; i < n; i++) a[i] = b[i].x;                                      // Yfirskrifum a með þjöppuðu gildunum.
}

int main()
{
    int n, i;
    scanf("%d", &n);                                                            // Innlestur hefst.
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
    compress(a, n);                                                             // Þjöppum gildin.
    for (i = 0; i < n; i++) printf("%d ", a[i]);                                // Prentum þjöppuð gildin.
    printf("\n");
    return 0;
}
