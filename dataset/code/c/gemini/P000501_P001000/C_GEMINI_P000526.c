#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_N 10005
char formula[MAX_N];
typedef struct {
    char name[16];
    int count;
} Atom;
typedef struct {
    Atom atoms[100];
    int size;
} Map;
Map stack[100];
int cmp(const void* a, const void* b) {
    return strcmp(((Atom*)a)->name, ((Atom*)b)->name);
}
int main() {
    if (scanf("%10004s", formula) == 1) {
        int top = 0;
        stack[0].size = 0;
        int i = 0, n = strlen(formula);
        while (i < n) {
            if (formula[i] == '(') {
                top++;
                stack[top].size = 0;
                i++;
            } else if (formula[i] == ')') {
                i++;
                int i_start = i;
                while (i < n && isdigit(formula[i])) i++;
                int mult = (i_start == i) ? 1 : atoi(formula + i_start);
                Map cur = stack[top--];
                for (int j = 0; j < cur.size; j++) {
                    int found = -1;
                    for (int k = 0; k < stack[top].size; k++) {
                        if (strcmp(stack[top].atoms[k].name, cur.atoms[j].name) == 0) {
                            found = k; break;
                        }
                    }
                    if (found != -1) {
                        stack[top].atoms[found].count += cur.atoms[j].count * mult;
                    } else {
                        int idx = stack[top].size++;
                        strcpy(stack[top].atoms[idx].name, cur.atoms[j].name);
                        stack[top].atoms[idx].count = cur.atoms[j].count * mult;
                    }
                }
            } else {
                int i_start = i++;
                while (i < n && islower(formula[i])) i++;
                char atom[16] = "";
                strncpy(atom, formula + i_start, i - i_start);
                atom[i - i_start] = '\0';
                i_start = i;
                while (i < n && isdigit(formula[i])) i++;
                int cnt = (i_start == i) ? 1 : atoi(formula + i_start);
                int found = -1;
                for (int k = 0; k < stack[top].size; k++) {
                    if (strcmp(stack[top].atoms[k].name, atom) == 0) {
                        found = k; break;
                    }
                }
                if (found != -1) {
                    stack[top].atoms[found].count += cnt;
                } else {
                    int idx = stack[top].size++;
                    strcpy(stack[top].atoms[idx].name, atom);
                    stack[top].atoms[idx].count = cnt;
                }
            }
        }
        qsort(stack[0].atoms, stack[0].size, sizeof(Atom), cmp);
        for (int j = 0; j < stack[0].size; j++) {
            printf("%s", stack[0].atoms[j].name);
            if (stack[0].atoms[j].count > 1) printf("%d", stack[0].atoms[j].count);
        }
        printf("\n");
    }
    return 0;
}