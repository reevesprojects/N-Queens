#include <stdio.h>
#include <stdlib.h>

int seed = 0103;
int st[16][10]; 
int count;
void randperm(int b[], int n){
    int currentNum, otherPos, otherNum;
    int i = n - 1;
    for (; i >= 1; i--){
        currentNum = b[i];
        otherPos = rand() % n;
        otherNum = b[otherPos];

        b[i] = otherNum;
        b[otherPos] = currentNum;
    }
    count++;
}

int checkboard(int b[], int n){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (b[i] == b[j] && i != j){
                return 0;
            }
            if (abs(b[i] - b[j]) == abs(i - j) && i != j){
                return 0;
            }
        }
    }

    return 1;
}

void displayboard(int b[], int n){
    int i, q;
	printf("\n[");
    for (i = 0; i < n; i++){
        printf(" %i", b[i]);
    }
    printf("]");
    for (i = 0; i < n; i++){
        printf("\n");
        for (q = b[i]; q > 0; q--) {
            printf("-");
        }
        printf("*");
        for (q = n - b[i] - 1; q > 0; q--){
            printf("-");
        }
    }
}

void stats(int st[16][10]){
    double max, mean, sizesq, sizefa;
    int i, q, size, min, holder;
    printf("\nsize\tmin\tmax\tmean\tsize**size\tsize!");
    for (i = 0; i < 16; i++){
        min = st[i][0];
        size = i + 4;
        holder = size;
        sizesq = size * size;
        sizefa = size;
        while (holder != 0){
            sizefa *= holder;
            holder--;
        }

        for (q = 0; q < 10; q++){
            if (st[i][q] < min){
                min = st[i][q];
            }
            if (max == 0 || st[i][q] > max){
                 max = st[i][q];
            }
            mean += st[i][q];
        }
        mean /= 10;
        printf("\n%-5i%-5i%-10.1f%-10.2e%-10.2e%-10.2e", size, min, max, mean, sizesq, sizefa);
    }
}

int main() {
    int b[20];
    int i, n, q, boo;
	srand(seed);
    for (i = 0; i < 10; i++){
        for (n = 4; n < 21; n++){
            for (q = 0; q < n; q++){
                b[q] = q;
            }
            boo = 0;
            do{
                randperm(b, n);
                boo = checkboard(b,n);
                
            } while (boo != 1);
            if (i == 0) {
                displayboard(b,n);
            }
            st[n-4][i] = count;
            count = 0;
        }
    }
    stats(st);
    return 0;
}
