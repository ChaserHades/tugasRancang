#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pengunjung
{
    char nama[50];
    int NIM;
};

struct perpustakaan
{
    char judul[100];
    char author[50];
    int tahun;
};

struct status
{
    int keluarMasuk;
};

void dataPengunjung();
void dataPerpustakaan();
void menu();
void inputUser();

void clearScreen()
{
    printf("\033[H\033[J"); // kalau windows pakai system("cls");
    fflush(stdin);
    fflush(stdout);
}

void bubbleSort(struct pengunjung *Mahasiswa, const int jumlah) 
{
    for (int batasLuar = 0; batasLuar < jumlah - 1; batasLuar++) 
    {
        for (int batasDalam = 0; batasDalam < jumlah - batasLuar - 1; batasDalam++) 
        {
            if (strcmp(Mahasiswa[batasDalam].nama, Mahasiswa[batasDalam + 1].nama) > 0) 
            {
                struct pengunjung temp = Mahasiswa[batasDalam];
                Mahasiswa[batasDalam] = Mahasiswa[batasDalam + 1];
                Mahasiswa[batasDalam + 1] = temp;
            }
        }
    }
}

void dataPengunjung(struct pengunjung **Mahasiswa, int *jumlah)
{
    *Mahasiswa = (struct pengunjung *)realloc(*Mahasiswa, (*jumlah + 1) * sizeof(struct pengunjung));

    
}

void dataPerpustakaan()
{
    struct perpustakaan Buku;
    
    printf("Data Buku");
    
    
}

void menu(struct pengunjung **Mahasiswa, int *jumlah)
{
    printf ("\n1. Data Pengunjung\n");
    printf ("2. Data Perpus\n");
    printf ("3. Exit\n");

    inputUser(Mahasiswa, jumlah);   
}

void inputUser(struct pengunjung **Mahasiswa, int *jumlah)
{
    char keyboard;
    keyboard = getchar();
    getchar();

    switch (keyboard)
    {
    case '1':
        clearScreen();
        dataPengunjung(Mahasiswa, jumlah);
        break;
    case '2':
        clearScreen();
        dataPerpustakaan();
        break;
    case '3':
        clearScreen();
        printf("\nTerimakasih!!\n");
        exit(0);
        break;
    default:
        printf("Pilihan Tidak Ada!!\n");
        break;
    }
    printf("\nEnter\n");
    getchar();
    clearScreen();
    menu(Mahasiswa, jumlah);
}

int main(int argc, char **argv)
{
    struct pengunjung *Mahasiswa = NULL;
    int jumlah = 0;
    clearScreen();

    menu(Mahasiswa, jumlah);
    
    return 0;
}
