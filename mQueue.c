#include "queue.h"
#include <stdio.h>

#define MAX_LOKET 3  

int main() {
    Queue antrian[MAX_LOKET];  
    int pilihan, loket, selesai;
    
    int i = 0;
    while (i < MAX_LOKET) {
        initializeQueue(&antrian[i]);
        i++;
    }

    do {
        printf("\n=== Sistem Antrian Bank ===\n");
        printf("1. Ambil Nomor Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Semua Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: 
                printf("Masukkan nomor loket (1-%d): ", MAX_LOKET);
                scanf("%d", &loket);
                
                if (loket < 1 || loket > MAX_LOKET) {
                    printf("Loket tidak valid!\n");
                } else {
                    enqueue(&antrian[loket - 1]);
                    printf("Nomor antrian %d masuk ke Loket %d.\n", antrian[loket - 1].Number, loket);
                }
                break;

            case 2: 
                printf("Masukkan nomor loket yang ingin diproses (1-%d): ", MAX_LOKET);
                scanf("%d", &loket);

                if (loket < 1 || loket > MAX_LOKET) {
                    printf("Loket tidak valid!\n");
                } else {
                    dequeue(&antrian[loket - 1], &selesai);
                    if (selesai != -1) {
                        printf("Nomor antrian %d telah diproses di Loket %d.\n", selesai, loket);
                    }
                }
                break;

            case 3: 
                printf("\nDaftar Antrian di Semua Loket:\n");
                
                i = 0;
                while (i < MAX_LOKET) {
                    printf("Loket %d: ", i + 1);
                    printQueue(&antrian[i]);
                    i++;
                }
                break;

            case 4: 
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }

    } while (pilihan != 4);

    return 0;
}

