#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct {
    char kode[10];
    char nama[50];
    char bahanDasar[50];
    char harga[50];
    int jumlah;
}data;

void inputBarang();
void lihatStock();
void peringatan();

int main()
{
    system("cls");
    int nomorMenu;

    do {
        printf("\t\t+-------------------------------------------------------+\n\n");
        printf("\t\t                        TOKO MEBEL                       \n\n");
        printf("\t\t+-------------------------------------------------------+\n\n");
        printf("\t\t|                  [1]. Input Barang                    |\n");
        printf("\t\t|                  [2]. Lihat Stock Barang              |\n");
        printf("\t\t|                  [3]. Exit                            |\n");
        printf("\t\t|                                                       |\n");
        printf("\t\t|                  PILIH [1] [2] [3]                    |\n");
        printf("\t\t|                                                       |\n\n");
        printf("\t\t3 * * * * * * * * * * * * * * * * * * * * * * * * * * * 3\n");
        printf("\t\t=========================================================\n");
        printf("\t\t:: Pilihan : ");
        fflush(stdin);scanf("%d",&nomorMenu);


        switch(nomorMenu){
        case 1:
            inputBarang();
            printf("\n\t\t    == Tekan apapun untuk kembali ke menu utama ==    ");
            getch();
            system("cls");
            break;
        case 2:
             lihatStock();
             printf("\n\t\t   == Tekan apapun untuk kembali ke menu utama ==    ");
             getch();
             system("cls");
            break;
        case 3:
            system("cls");
            break;
            default:
            peringatan();
        }
    } while(nomorMenu!=3);
    return 0;
}

void inputBarang(){
    system("cls");
    int banyakBarang;
    char und='_';
    FILE *fp;
    fp = fopen("data.txt","a+");

    printf("\t\t -------------------------------------------------------\n");
    printf("\t\t|                     INPUT BARANG                      |\n");
    printf("\t\t -------------------------------------------------------\n");
    printf("\t\t Banyaknya barang yang akan anda masukkan : ");
    fflush(stdin);scanf("%d",&banyakBarang);
    data barang[banyakBarang];
    printf("\t\t =======================================================\n");
    for(int i=1;i<=banyakBarang;i++){
        printf("\t\t                      - - - - - - \n");
        printf("\t\t                    | Barang [%d] |                       \n",i);
        printf("\t\t                      - - - - - - \n");
        printf("\t\t :: Kode Barang     : [%d] : ",i);
        fflush(stdin);scanf("%[^\n]",&barang[i].kode);
        for(int j=0;j<strlen(barang[i].kode);j++){
            if(barang[i].kode[j] == ' '){
                barang[i].kode[j] = und;
            }
        }
        printf("\t\t :: Nama Barang     : [%d] : ",i);
        fflush(stdin);scanf("%[^\n]",&barang[i].nama);
        for(int j=0;j<strlen(barang[i].nama);j++){
            if(barang[i].nama[j] == ' '){
                barang[i].nama[j] = und;
            }
        }

        printf("\t\t :: Bahan Dasar     : [%d] : ",i);
        fflush(stdin);scanf("%[^\n]",&barang[i].bahanDasar);
        for(int j=0;j<strlen(barang[i].bahanDasar);j++){
            if(barang[i].bahanDasar[j] == ' '){
                barang[i].bahanDasar[j] = und;
            }
        }

        printf("\t\t :: Jumlah          : [%d] : ",i);
        fflush(stdin);scanf("%d",&barang[i].jumlah);

        printf("\t\t :: Harga Per Unit  : [%d] : Rp. ",i);
        fflush(stdin);scanf("%[^\n]",&barang[i].harga);
        for(int j=0;j<strlen(barang[i].harga);j++){
            if(barang[i].harga[j] == ' '){
                barang[i].harga[j]= und;
            }
        }
        printf("\t\t =======================================================\n");
        fprintf(fp,"%s %s %s %d %s \n",barang[i].kode,barang[i].nama,barang[i].bahanDasar,barang[i].jumlah,barang[i].harga);
    }
    if(banyakBarang == 0){
        printf("\n\t\t                TIDAK MENAMBAHKAN BARANG\n");
    }else{
    printf("\n\t\t                        SUKSES\n");
    }
    fclose(fp);
}

void lihatStock (){
    system ("cls");
    int count=1;
    char spasi =' ';

    data barang;

    FILE *fp;
    fp = fopen("data.txt","r");
    printf("\t\t -------------------------------------------------------\n");
    printf("\t\t|                  PERSEDIAAN BARANG                    |\n");
    printf("\t\t -------------------------------------------------------\n");

    while(fscanf(fp,"%s %s %s %d %s \n",barang.kode,barang.nama,barang.bahanDasar,&barang.jumlah,barang.harga)!= EOF){
        for(int i=0;i<strlen(barang.kode);i++){
            if(barang.kode[i] == '_'){
                barang.kode[i] = spasi;
            }
        }
        for(int i=0;i<strlen(barang.nama);i++){
            if(barang.nama[i] == '_'){
                barang.nama[i] = spasi;
            }
        }
        for(int i=0;i<strlen(barang.bahanDasar);i++){
            if(barang.bahanDasar[i] == '_'){
                barang.bahanDasar[i] = spasi;
            }
        }
        for(int i=0;i<strlen(barang.harga);i++){
            if(barang.kode[i] == '_'){
                barang.kode[i] = spasi;
            }
        }
        printf("\t\t                      - - - - - - \n");
        printf("\t\t                    | Barang [%d] |\n",count);
        printf("\t\t                      - - - - - - \n");
        printf("\t\t  :: Kode Barang    : [%d] : %s \n",count,barang.kode);
        printf("\t\t  :: Nama Barang    : [%d] : %s \n",count,barang.nama);
        printf("\t\t  :: Bahan Dasar    : [%d] : %s \n",count,barang.bahanDasar);
        printf("\t\t  :: Jumlah         : [%d] : %d \n",count,barang.jumlah);
        printf("\t\t  :: Harga Per Unit : [%d] : Rp. %s \n",count,barang.harga);
        printf("\t\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");

        count++;
    }
    fclose(fp);
}

void peringatan (){
    system("cls");
    printf("\t\t -------------------------------------------------------\n");
    printf("\t\t|                     !PERINGATAN!                      |\n");
    printf("\t\t -------------------------------------------------------\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t|               NOMOR PILIHAN ANDA SALAH!               |\n");
    printf("\t\t|               SILAHKAN PILIH [1] [2] [3]              |\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t -------------------------------------------------------\n");
    printf("\t\t [!] Beralih ke menu utama ");
    for(int i=0;i<4;i++){
        sleep(1);
        printf(". ");
    }
    system("cls");
}
