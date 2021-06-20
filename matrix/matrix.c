#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void mx_free(TMatrix *m) {
    if (m != NULL)
        if (m->a != NULL) {
            free(m->a);
            free(m);
        }
}

void mx_print(TMatrix *m) {
    unsigned int i, j;


    if (m != NULL) {
        if (m->a != NULL) {
            for (i = 0; i < m->m; i++) {
                for (j = 0; j < m->n; j++)
                    printf("%8.2lf", m->a[i * m->n + j]);
                printf("\n");
            }
        }
    }
}

TMatrix *mx_identity(unsigned int n) {
    unsigned int i, j;
    TMatrix *m = NULL;


    m = (TMatrix*)malloc(sizeof(TMatrix));
    if (m != NULL) {
        m->a = (double*)malloc(n * n * sizeof(double));
        if (m->a != NULL) {
            m->n = m->m = n;
            for (i = 0; i < m->m; i++)
                for (j = 0; j < m->n; j++)
                    m->a[i * n + j] = i == j ? 1 : 0;
        }
        else {
            free(m);
            m = NULL;
        }
    }

    return m;
}

void mx_sort(TMatrix *m)
{
    int *index = (int*)malloc(sizeof(double) * m->n);
    for (int i = 0; i < m->n; ++i)
    {
        index[i] = i;
    }

    for (int i = 0; i < m->n; ++i)
    {
        for (int j = i + 1; j < m->n; ++j)
        {
            if (m->a[i] > m->a[j])
            {
                double tmp = m->a[i];
                m->a[i] = m->a[j];
                m->a[j] = tmp;

                int tmp_i = index[i];
                index[i] = index[j];
                index[j] = tmp_i;
            }
        }
    }

    for (int j = 0; j < m->n; ++j)
    {
        if (index[j] != j)
        {
            for (int i = 1; i < m->m; ++i)
            {
                double tmp = m->a[j + i * m->n];
                m->a[j + i * m->n] = m->a[index[j] + i * m->n];
                m->a[index[j] + i * m->n] = tmp;
            }

            index[index[j]] = index[j];
            index[j] = j;
        }
    }

    free(index);
}