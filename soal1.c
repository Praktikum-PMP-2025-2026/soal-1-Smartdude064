/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Faiz Azmi Irwan (13224040)
 *   Nama File           : soal2.c
 *   Deskripsi           : Soal 1 - Pemulihan Sensor Fragmen
 * 
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
  
int main() {
    int N, n, number, sum = 0;

    scanf("%d", &N);
    int arr[N];
    int *ptr_arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &number);
        arr[i] = number;
        ptr_arr[i] = &arr[i]; //debugging pertama pada nilai address yang dipanggil salah &arr[N]
        //printf("Nilai %d - %d - %d - %d\n", arr[i], &arr[i], ptr_arr[i], *ptr_arr[i]);
    }
    

    for (int i = 0; i < N; i++) {
        if (*ptr_arr[i] == -1) {
            if (N == 1) {
                *ptr_arr[i] = 0;
                arr[i] = *ptr_arr[i];
                break;
            }
            for (int j = 1; j <= N; j++) {
                if (*ptr_arr[i-j] != -1 && *ptr_arr[i+j] != -1) {
                    *ptr_arr[i] = floor((*ptr_arr[i+j] + *ptr_arr[i-j]) / 2); //debugging kedua kurang tanda kurung
                    arr[i] = *ptr_arr[i];
                    break;
                } else if (*ptr_arr[i-j] != -1) {
                    *ptr_arr[i] = *ptr_arr[i-j];
                    arr[i] = *ptr_arr[i];
                    break;
                } else if (*ptr_arr[i+j] != -1) {
                    *ptr_arr[i] = *ptr_arr[i+j];
                    arr[i] = *ptr_arr[i];
                    break;
                } else {
                    *ptr_arr[i] = 0;
                    arr[i] = *ptr_arr[i];
                    break;
                }
            }
        }
        //printf("Nilai %d - %d - %d - %d\n", arr[i], &arr[i], ptr_arr[i], *ptr_arr[i]);
        //printf("Nilai array ke-%d adalah %d\n", i, arr[i]);
    }

    printf("RECOVERED ");
    for (int i = 0; i < N-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[N-1]);


    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    printf("MAX_SUM %d\n", sum);

    return 0;
}
 
