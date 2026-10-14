#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void bubble_sort(int start, int end, int arr[]);
void printmas(int mas[], int n);
int main1();
int main2();
int main3();
int main4();
int main5(); 

int main(){
    // main1();
    // main2();
    // main3();
    // main4();  
    // main5();
    return 0;
}
int main1(){
    int n, min = 1e9, max=-1e9, iminf, iminl, imaxf, imaxl, imin, imax, sum = 0, cnt = 0, sum1 = 0;
    printf("|ПЕРВАЯ ЗАДАЧА| Введи число: ");                    //n - длина массива 
    scanf("%d",&n);
    printf(" \n Введи массив:");
    int mas[n];                                 
    for(int i = 0; i < n; i++){
        scanf("%d", &mas[i]);
        sum += mas[i];
        if(mas[i] <= min) {
            iminl = i; 
            if(mas[i] != min) {iminf = i;}                  //нахождение минимума(правого и если минимум поменялся - левого)
            min = mas[i];
        }
        if(mas[i] >= max) {
            imaxl = i; 
            if(mas[i] != max) {imaxf = i;}                      //аналогично с максимумом
            max = mas[i];
        }
    }
    if(imaxf > iminl){ 
        imin = iminl;
        imax = imaxf;
    } else {
        imin = imaxf;
        imax = iminl;
    }
    float mid = sum / n; 
    printmas(mas, n);
    printf("[");
    for(int i = 0; i < n; i++){                                      //счет чисел больше среднего 
        if(mas[i] > mid) {cnt++;}
        if((i > imax) && (i < imin)) {sum1 += i;}                        //счет между min и max
        if(mas[i] < 0){
            mas[i] = abs(mas[i]);
        }
        if(mas[i] == 0) {mas[i] = mid;}
        if(i % 2 == 1) {mas[i] += min;}
        printf("%d, ", mas[i]);
    }
    printf(" ]");
    printf("\n Среднее значение:%f, min: %d, max: %d, iminf: %d, iminl: %d, imaxf: %d, imaxl: %d, Сумма между max и min: %d \n ", mid, min, max, iminf, iminl, imaxf, imaxl, sum1);
    return 0;
}

int main2(){
    int n, k, shift, med, cnt_med = 0;                      //n - длина массива, k - сдвиг
    printf("|ВТОРАЯ ЗАДАЧА| \n Введи n:");
    scanf("%d",&n);
    printf(", Введи k:");
    scanf("%d", &k);
    printf(" \n Введи массив:");
    int mas[n], sortmas[n], shiftmas[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &mas[i]);
        shiftmas[i] = mas[i];
        sortmas[i] = mas[i];
    }

    shift = k % n;
    for(int i = 0; i < n; i++){
        shiftmas[i] = mas[(i + shift) % n];      //сдвиг
    }
    bubble_sort(0, n / 2, sortmas);
    bubble_sort(n / 2, n, sortmas);  //сортировка(не встроенная)

    if(n % 2 == 1){
        med = sortmas[n / 2];
    } else {med = (sortmas[n / 2 -1] + sortmas[n / 2]) / 2;}        //медиана

    int masnew[n], cnt = 0;
    for(int i = 0; i < n; i++){
        if(sortmas[i] != med){
            masnew[cnt] = sortmas[i];       //массив чисел, не равных медиане
            cnt++;
        }
    
    }
    printf("Сдвиг:"); printmas(shiftmas, n);
    printf("Сортировка:"); printmas(sortmas, n);
    printf("Без медианы:"); printmas(masnew, cnt);
    printf("Медиана: %d \n", med);
    return 0;
}

int main3(){
    int n, k, maxn = -1e9, imax, jmax, sum = 0, comp = 1;               //n - длина строки, k - длина стоблца
    bool squaresym  = true;
    printf("|ТРЕТЬЯ ЗАДАЧА| Ввведи M: ");
    scanf("%d", &n);
    printf(", введи N:");
    scanf("%d", &k);
    printf("Введи массив: \n");
    int mas[n][k], turnmas[k][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            scanf("%d", &mas[i][j]);
            if(maxn < mas[i][j]){
                maxn = mas[i][j]; imax = i + 1; jmax = j + 1;
            }
            if(i % 2 == 1) {sum += mas[i][j];}          //максимум/сумма/произведение
            if(j % 2 == 0) {comp *= mas[i][j];}
        }
    }
    if(n == k){
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(mas[i][j] != mas[j][i]) {squaresym = false;}     //транспонирование и проверка на симметричность
                int l = mas[i][j];
                mas[j][i] = mas[i][j];
                mas[i][j] = l;
            }
        }
    } else{
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++){         //поворот
                turnmas[i][j] = mas[j][k - i - 1];
            }
        }
    }

    printf("Сумма: %d; Произведение: %d; Максимальный элемент: %d, i = %d, j = %d; \n Измененный массив: \n", sum, comp, maxn, imax, jmax);
    for(int i = 0; i < k; i++){
        printf("[");
        for(int j = 0; j < n - 1; j++){
            printf("%d, ", turnmas[i][j]);
        }
        printf("%d] \n", turnmas[i][n - 1]);
    }
    if(n == k){
        if(squaresym){
                    printf("Матрица квадратная и симметричная \n Седловые точки: \n");
        } else {printf("Матрица квадратная и несимметричная \n Седловые точки: \n");}
    }
    for(int i = 0; i < n; i++){
        int min = 1e9;
        for(int j = 0; j < k; j++){
            if(min > mas[i][j]) {min = mas[i][j];}
        }
        bool flag = true;
        for(int j = 0; j < k; j++){             //нахождение седловых точек
            if(mas[i][j] == min){
                for(int l = 0; l < n; l++){
                    if(mas[l][j] > min){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    printf("i = %d, j = %d, Значение = %d; \n", i + 1, j + 1, min);
                }
            }
        }
    }
    return 0;
}

int main4(){
    int n, maxrep = -1e9, unicount = 0, difcount = 0, x, lincount = 0, bincount = 1, mod;
    printf("|ЧЕТВЕРТАЯ ЗАДАЧА| \n Введи n:");               //длина массива
    scanf("%d",&n);
    printf(" \n Введи массив:");
    int mas[n], sortmas[n], freqmas[21] = {0}, unimas[n], difmas[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &mas[i]);
        sortmas[i] = mas[i];
        if(mas[i] <= 10 && mas[i] >= -10) {freqmas[mas[i] + 10]++;}     //частотный массив 
    }
    printf("Введи x:");
    scanf("%d", &x);
    bubble_sort(0, n, sortmas);  
    for(int i = 0; i < 21; i++){
        if(maxrep < freqmas[i]) {maxrep = freqmas[i]; mod = i - 10;}        //нахождение максимальной частоты
    }
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(mas[i] == mas[j] && i != j){
                flag = false;
                break;
            }
        }
        if(flag){
            difmas[difcount] = mas[i];                                      //нахождение различных
            difcount++;
        }
    }
    bool iuni = true;
    if(sortmas[0] == sortmas[1]){               //нахождение уникальных
        iuni = false;
    } else {iuni = true;}                       //является ли 1 элемент уникальным в сорт. массиве
    for(int i = 0; i < n - 1; i++){
        if(iuni){
            if(sortmas[i] == sortmas[i + 1]){       
                iuni = false;                                               
            } else {
                unimas[unicount] = sortmas[i];
                unicount++;
            }
        } else {
            if(sortmas[i] != sortmas[i + 1]){
                iuni = true;
            }
        }
    }
    bool linflag = false;
    for(int i = 0; i < n; i++){
        lincount++;                         //линейный поиск
        if(mas[i] == x){
            linflag = true;
            break;
        }
    if(!linflag) {lincount = -1;}
    }
    int left = 0, right = n - 1, mid;
    while (left <= right) {                 //бинарный поиск через 2 указателя
        bincount++; 
        mid = left + (right - left) / 2;

        if (sortmas[mid] == x) {
            break;
        } else if (sortmas[mid] < x) {
            left = mid + 1;
        } else {right = mid - 1;}
    }
    if(sortmas[bincount] != x) {bincount = -1;}

    printmas(freqmas, 21);                                                              
    printf("Мода: %d; Количество различных: %d; Лин поиск: %d; Бин поиск: %d \n", mod, difcount, lincount, bincount);
    printf("Массив уникальных: ");
    printmas(unimas, unicount);
    return 0;
}

int main5(){
     int n, k;                              //длины массивов
     printf("|ПЯТАЯ ЗАДАЧА| \n Введи n:");
    scanf("%d",&n);
    printf(" \n Введи массив A:");
    int fmas[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &fmas[i]);
    }
    printf("\n Введи k:");
    scanf("%d", &k);
    printf(" \n Введи массив C:");
    int smas[k], unite[n + k], unite_count = 0, resid[n], resid_count = 0, symres[n + k], symres_count = 0, nmin;
    if(n <= k){
        nmin = n;                           //минимум из массивов
    } else {nmin = k;}

    int inter[nmin], inter_count = 0;;
    
    for(int i = 0; i < k; i++){
        scanf("%d", &smas[i]);
    }
    bubble_sort(0, n, fmas);
    bubble_sort(0, k, smas);
    int i =0;
    int j = 0;
    while (i < n && j < k)
    {
        if(fmas[i] < smas[j]){
            unite[unite_count] = fmas[i];           //2 указателя: проходимся в сорт. массивах, добавляем в соотв. массивы
            unite_count++;
            resid[resid_count] = fmas[i];
            resid_count++;
            symres[symres_count] = fmas[i];
            symres_count++;
            i++;
        } else if(fmas[i] > smas[j]){
            unite[unite_count] = smas[j];
            unite_count++;
            symres[symres_count] = smas[j];
            symres_count++;
            j++;
        } else {
            unite[unite_count] = fmas[i];
            unite_count++;
            inter[inter_count] = fmas[i];
            inter_count++;
            i++;
            j++;
        }
    }
    printf("Объединение: \n");
    printmas(unite, unite_count);
    printf("Пересечение: \n");
    printmas(inter, inter_count);
    printf("A/C: \n");
    printmas(resid, resid_count);
    printf("Симметричное разность: \n");
    printmas(symres, symres_count);
    if(inter_count == k){
        printf("Массив C - подмножество A");
    } else {printf("Массив C - не подмножество A");}
    return 0;
}

void bubble_sort(int start, int end, int arr[]){ 
    for(int i = start; i < end - 1; i++){
        bool flag = true;
        for(int j = start; j < end - (i - start) - 1; j++){
            if(arr[j] > arr[j + 1]){
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
                flag = false;
            }
        }
        if(flag) {break;}
    }
}

void printmas(int mas[], int n){
    printf("[");
    for(int i = 0; i < n - 1; i++){
        printf("%d, ", mas[i]);
    }
    printf("%d] \n", mas[n - 1]);
}