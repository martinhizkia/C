#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "warna.c"
#include "header.c"
#include "sinopsis.c"
#include "nowplaying.c"
#include "comingsoon.c"
int menu(), belitiket(), menusinopsis(), menunowplaying(), menucomingsoon(), menufilm(), avengers(), pikachu(), resetduduk(), tiketavenger(int xx, int yy, int c), printtiketavenger(int xx, int yy, int c);
void arrowmenu(int a, int b), choice(int a), kursipenontonavenger(int c), kursipenontonpikachu(int c), arrow(int a, int b, int xx, int yy);
int main(){
  fflush(stdin);
  int a = menu();
  choice(a);
}
int loading(){
  int loading1, loading2;
  system("cls");
  kuning();
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t LOADING, PLEASE WAIT");
  for(loading1 = 0; loading1 < 3; ++loading1){
    printf(".");
    Sleep(50);
  }
  printf("\n\n\t\t\t\t\t\t\t\t");
  biru();
  for(loading2 = 0; loading2 < 40; ++loading2){
    printf("%c", 219);
    Sleep(50);
  }
  normal();
}
int menu(){
  char awal[7][20]={"BELI TIKET", "SINOPSIS FILM", "NOW PLAYING", "COMING SOON", "BANTUAN", "ADMIN MODE", "KELUAR"};
  int b = 1, key = 0, a;
  loading();
  while(key != 13){
    system("cls");
    header();
    fflush(stdin);
    kuning();
    printf("\n\t\t\t\t\t\t\t     SELAMAT DATANG! SILAHKAN PILIH SALAH SATU OPSI\n\n");
    normal();
    for(a = 0; a < 7; a++){
      arrowmenu(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t\t    %d. %s \n", a + 1, awal[a]);
      printf("\t\t\t\t\t\t\t\t\t   ==================\n");
    }
    key = getch();
    if(key == 80 && b != 7){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 7;
    }
    else if(key == 80 && b == 7){
      b = 1;
    }
  }
  return b;
}
void arrowmenu(int a, int b){
  if(a == b){
    merah();
  }
  else{
    normal();
  }
}
void choice(int a){
  if(a == 1){
    menufilm();
  }
  if(a == 2){
    menusinopsis();
  }
  if(a == 3){
    menunowplaying();
  }
  if(a == 4){
    menucomingsoon();
  }
  if(a == 5){
    bantuan();
  }
  if(a == 6){
    resetduduk();
  }
  if(a == 7){
    system("cls");
    headerkeluar();
    exit(0);
  }
}
void kursipenontonavenger(int c){
  fflush(stdin);
  char kursi[8][10]={
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80}
  };
  int ave[8][10][4] = {};
  int a = 0, b = 0, key = 0, xx = 1, yy = 1;
  while(key != 13){
    system("cls");
    fflush(stdin);
    FILE *p = fopen("avenger.txt", "r");
    for(int x = 0; x < 8; x++){
      for(int y = 0; y < 10; y++){
        for(int z = 0; z < 4; z++){
          fscanf(p, "%1d", &ave[x][y][z]);
        }
      }
    }
    fclose(p);
    headerbelitiket();
    kuning();
    printf("\n\t\t\t\t\t\t\t\tPILIH POSISI KURSI YANG INGIN ANDA PESAN\n\n\n");
    normal();
    for(a = 0; a < 8; a++){
      for(b = 0; b < 10; b++){
        arrow(a + 1, b + 1, xx, yy);
        if(b == 0){
          printf("\t\t\t\t\t\t\t   ");
        }
        if(a == 0 && b < 9){
          if(ave[a][b][c] == 1){
            printf("[ %d] ", kursi[a][b]);
          }
          else{
            printf("  %d  ", kursi[a][b]);
          }
        }
        else{
          if(ave[a][b][c] == 1){
            printf("[%d] ", kursi[a][b]);
          }
          else{
            printf(" %d  ", kursi[a][b]);
          }
        }
        if(b == 4){
          printf("  ");
        }
      }
      printf("\n\n");
    }
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t    =================================================\n");
    printf("\t\t\t\t\t\t\t\t              LAYAR DISINI\n");
    printf("\t\t\t\t\t\t\t    =================================================\n");
    key = getch();
    if(key == 80 && xx != 8){
      xx++;
    }
    else if(key == 72 && xx != 1){
      xx--;
    }
    else if(key == 72 && xx == 1){
      xx = 8;
    }
    else if(key == 80 && xx == 8){
      xx = 1;
    }
    else if(key == 75 && yy != 1){
      yy--;
    }
    else if(key == 77 && yy != 10){
      yy++;
    }
    else if(key == 75 && yy == 1){
      yy = 10;
    }
    else if(key == 77 && yy){
      yy = yy;
    }
    else if(key == 27){
      main();
    }
    else{
      yy = yy;
      xx = xx;
    }
  }
  tiketavenger(xx, yy, c);
}
void kursipenontonpikachu(int c){
  fflush(stdin);
  char kursi[8][10]={
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80}
  };
  int pik[8][10][4] = {};
  int a = 0, b = 0, key = 0, xx = 1, yy = 1;
  while(key != 13){
    system("cls");
    fflush(stdin);
    FILE *p = fopen("pikachu.txt", "r");
    for(int x = 0; x < 8; x++){
      for(int y = 0; y < 10; y++){
        for(int z = 0; z < 4; z++){
          fscanf(p, "%1d", &pik[x][y][z]);
        }
      }
    }
    fclose(p);
    headerbelitiket();
    kuning();
    printf("\n\t\t\t\t\t\t\t\tPILIH POSISI KURSI YANG INGIN ANDA PESAN\n\n\n");
    normal();
    for(a = 0; a < 8; a++){
      for(b = 0; b < 10; b++){
        arrow(a + 1, b + 1, xx, yy);
        if(b == 0){
          printf("\t\t\t\t\t\t\t   ");
        }
        if(a == 0 && b < 9){
          if(pik[a][b][c] == 1){
            printf("[ %d] ", kursi[a][b]);
          }
          else{
            printf("  %d  ", kursi[a][b]);
          }
        }
        else{
          if(pik[a][b][c] == 1){
            printf("[%d] ", kursi[a][b]);
          }
          else{
            printf(" %d  ", kursi[a][b]);
          }
        }
        if(b == 4){
          printf("  ");
        }
      }
      printf("\n\n");
    }
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t    =================================================\n");
    printf("\t\t\t\t\t\t\t\t              LAYAR DISINI\n");
    printf("\t\t\t\t\t\t\t    =================================================\n");
    key = getch();
    if(key == 80 && xx != 8){
      xx++;
    }
    else if(key == 72 && xx != 1){
      xx--;
    }
    else if(key == 72 && xx == 1){
      xx = 8;
    }
    else if(key == 80 && xx == 8){
      xx = 1;
    }
    else if(key == 75 && yy != 1){
      yy--;
    }
    else if(key == 77 && yy != 10){
      yy++;
    }
    else if(key == 75 && yy == 1){
      yy = 10;
    }
    else if(key == 77 && yy){
      yy = yy;
    }
    else if(key == 27){
      main();
    }
    else{
      yy = yy;
      xx = xx;
    }
  }
  tiketpikachu(xx, yy, c);
}
void arrow(int a, int b, int xx, int yy){
  if(a == xx && b == yy){
    merah();
  }
  else{
    normal();
  }
}
int menusinopsis(){
  char awal[6][40]={"AVENGERS: ENDGAME", "POKEMON DETECTIVE PIKACHU", "ALADDIN", "GODZILLA II: KING OF THE MONSTERS", "JOHN WICK: CHAPTER 3 - PARABELLUM", "KEMBALI"};
  int b = 1, key = 0, a;
  fflush(stdin);
  while(key != 13){
   fflush(stdin);
    system("cls");
    headersinopsis();
    kuning();
    printf("\n\t\t\t\t\t\t\t\t     SILAHKAN PILIH SALAH SATU FILM\n\n");
    normal();
    for(a = 0; a < 6; a++){
      arrowmenu(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t  %d. %s \n", a + 1, awal[a]);
      printf("\t\t\t\t\t\t\t\t ======================================\n");
    }
    key = getch();
    if(key == 80 && b != 6){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 6;
    }
    else if(key == 80 && b == 6){
      b = 1;
    }
  }
  if(b == 1){
    sinopsisendgame();
  }
  if(b == 2){
    sinopsispikachu();
  }
  if(b == 3){
    sinopsisaladdin();
  }
  if(b == 4){
    sinopsisgodzilla();
  }
  if(b == 5){
    sinopsisjohnwick();
  }
  if(b == 6){
    main();
  }
}
int menunowplaying(){
  char awal[3][30]={"AVENGERS: ENDGAME", "POKEMON DETECTIVE PIKACHU", "KEMBALI"};
  int b = 1, key = 0, a;
  fflush(stdin);
  while(key != 13){
    system("cls");
    headernowplaying();
    kuning();
    printf("\n\t\t\t\t\t\t\t\t     SILAHKAN PILIH SALAH SATU FILM\n\n");
    normal();
    for(a = 0; a < 3; a++){
      arrowmenu(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t      %d. %s \n", a + 1, awal[a]);
      printf("\t\t\t\t\t\t\t\t     ==============================\n");
    }
    key = getch();
    if(key == 80 && b != 3){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 3;
    }
    else if(key == 80 && b == 3){
      b = 1;
    }
  }
  if(b == 1){
    nowplayingendgame();
  }
  if(b == 2){
    nowplayingpikachu();
  }
  if(b == 3){
    main();
  }
}
int menucomingsoon(){
  char awal[4][40]={"ALADDIN", "GODZILLA II: KING OF THE MONSTERS", "JOHN WICK: CHAPTER 3 - PARABELLUM", "KEMBALI"};
  int b = 1, key = 0, a;
  fflush(stdin);
  while(key != 13){
    system("cls");
    headercomingsoon();
    kuning();
    printf("\n\t\t\t\t\t\t\t\t     SILAHKAN PILIH SALAH SATU FILM\n\n");
    normal();
    for(a = 0; a < 4; a++){
      arrowmenu(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t  %d. %s \n", a + 1, awal[a]);
      printf("\t\t\t\t\t\t\t\t ======================================\n");
    }
    key = getch();
    if(key == 80 && b != 4){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 4;
    }
    else if(key == 80 && b == 4){
      b = 1;
    }
  }
  if(b == 1){
    comingsoonaladdin();
  }
  if(b == 2){
    comingsoongodzilla();
  }
  if(b == 3){
    comingsoonjohnwick();
  }
  if(b == 4){
    main();
  }
}
int menufilm(){
  char awal[3][30]={"AVENGERS: ENDGAME", "POKEMON DETECTIVE PIKACHU", "KEMBALI"};
  int b = 1, key = 0, a;
  fflush(stdin);
  while(key != 13){
    system("cls");
    headerbelitiket();
    kuning();
    printf("\n\t\t\t\t\t\t\t\t     SILAHKAN PILIH SALAH SATU FILM\n\n");
    normal();
    for(a = 0; a < 3; a++){
      arrowmenu(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t      %d. %s \n", a + 1, awal[a]);
      printf("\t\t\t\t\t\t\t\t     ==============================\n");
    }
    key = getch();
    if(key == 80 && b != 3){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 3;
    }
    else if(key == 80 && b == 3){
      b = 1;
    }
  }
  if(b == 1){
    avengers();
  }
  if(b == 2){
    pikachu();
  }
  if(b == 3){
    main();
  }
}
int avengers(){
  char awal[4][10]={"14:15", "17:45", "21:15", "KEMBALI"};
  int b = 1, key = 0, a, c;
  fflush(stdin);
  while(key != 13){
    system("cls");
    headerbelitiket();
    kuning();
    printf("\n\t\t\t\t\t\t\t\t     SILAHKAN PILIH JAM TAYANG FILM\n\n");
    normal();
    for(a = 0; a < 4; a++){
      arrowmenu(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t\t       %d. %s \n", a + 1, awal[a]);
      printf("\t\t\t\t\t\t\t\t\t      ============\n");
    }
    key = getch();
    if(key == 80 && b != 4){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 4;
    }
    else if(key == 80 && b == 4){
      b = 1;
    }
  }
  if(b == 1){
    c = 0;
  }
  if(b == 2){
    c = 1;
  }
  if(b == 3){
    c = 2;
  }
  if(b == 4){
    menufilm();
  }
  kursipenontonavenger(c);
}
int pikachu(){
  char awal[4][10]={"12:15", "14:30", "16:45", "KEMBALI"};
  int b = 1, key = 0, a, c;
  fflush(stdin);
  while(key != 13){
    system("cls");
    headerbelitiket();
    kuning();
    printf("\n\t\t\t\t\t\t\t\t     SILAHKAN PILIH JAM TAYANG FILM\n\n");
    normal();
    for(a = 0; a < 4; a++){
      arrowmenu(a + 1, b);
      printf("\n\t\t\t\t\t\t\t\t\t       %d. %s \n", a + 1, awal[a]);
      printf("\t\t\t\t\t\t\t\t\t      ============\n");
    }
    key = getch();
    if(key == 80 && b != 4){
      b++;
    }
    else if(key == 72 && b != 1){
      b--;
    }
    else if(key == 72 && b == 1){
      b = 4;
    }
    else if(key == 80 && b == 4){
      b = 1;
    }
  }
  if(b == 1){
    c = 0;
  }
  if(b == 2){
    c = 1;
  }
  if(b == 3){
    c = 2;
  }
  if(b == 4){
    menufilm();
  }
  kursipenontonpikachu(c);
}
int resetduduk(){
  fflush(stdin);
  char awal[3][20]={"RESET DATA", "STATISTIK PENONTON", "KEMBALI"};
  int key = 0, b = 1, sum1 = 0, sum2 = 0, a;
  int avenger[8][10][4] = {};
  int pikachu[8][10][4] = {};
  int tes1[8][10][4] = {};
  int tes2[8][10][4] = {};
  system("cls");
  headeradmin();
  merah();
  printf("\n\t\t\t\t\t\t    PERHATIAN! PASTIKAN ANDA MEMPUNYAI IZIN UNTUK MENGAKSES MENU INI\n\n\n");
  normal();
  int i;
  char ch1, password[10], p[10] = "mantap";
  printf("\t\t\t\t\t\t\t\t\t  Password: ");
  for(i = 0; i < 10; i++){
    ch1 = getch();
    password[i] = ch1;
    if(ch1 != 13){
      printf("*");
    }
    if(ch1 == 13){
      break;
    }
  }
  if(p[0] == password[0] && p[1] == password[1] && p[2] == password[2] && p[3] == password[3] && p[4] == password[4] && p[5] == password[5]){
    system("cls");
    headeradmin();
    hijau();
    printf("\n\t\t\t\t\t\t\t\t\t     AKSES DITERIMA\n\n");
    merah();
    printf("\n\t\t\t\t\t\t\t\t\t\t LANJUT\n");
    printf("\t\t\t\t\t\t\t\t\t\t========\n");
    normal();
    getch();
    system("cls");
    while(key != 13){
      system("cls");
      headeradmin();
      kuning();
      printf("\n\t\t\t\t\t\t\t\t     SILAHKAN PILIH SALAH SATU OPSI\n\n");
      normal();
      for(a = 0; a < 3; a++){
        arrowmenu(a + 1, b);
        printf("\n\t\t\t\t\t\t\t\t\t %d. %s  \n", a + 1, awal[a]);
        printf("\t\t\t\t\t\t\t\t\t========================\n");
      }
      key = getch();
      if(key == 80 && b != 3){
        b++;
      }
      else if(key == 72 && b != 1){
        b--;
      }
      else if(key == 72 && b == 1){
        b = 3;
      }
      else if(key == 80 && b == 3){
        b = 1;
      }
    }
    if(b == 1){
      FILE *pika = fopen("pikachu.txt", "w+");
      for(int a = 0; a < 8; a++){
        for(int b = 0; b < 10; b++){
          for(int c = 0; c < 4; c++){
            fprintf(pika, "%d", pikachu[a][b][c]);
          }
        }
      }
      fclose(pika);
      FILE * aveng = fopen("avenger.txt", "w+");
      for(int a = 0; a < 8; a++){
        for(int b = 0; b < 10; b++){
          for(int c = 0; c < 4; c++){
            fprintf(aveng, "%d", avenger[a][b][c]);
          }
        }
      }
      fclose(aveng);
      system("cls");
      headeradmin();
      hijau();
      printf("\n\t\t\t\t\t\t\t\t\t   DATA TELAH DIRESET\n\n");
      merah();
      printf("\n\t\t\t\t\t\t\t\t\t  KEMBALI KE MENU AWAL\n");
      printf("\t\t\t\t\t\t\t\t\t ======================\n");
      normal();
      getch();
      main();
    }
    if(b == 2){
      system("cls");
      headeradmin();
      FILE *p = fopen("avenger.txt", "r");
      for(int a = 0; a < 8; a++){
        for(int b = 0; b < 10; b++){
          for(int c = 0; c < 4; c++){
            fscanf(p, "%1d", &tes1[a][b][c]);
          }
        }
      }
      fclose(p);
      FILE *gg = fopen("pikachu.txt", "r");
      for(int a = 0; a < 8; a++){
        for(int b = 0; b < 10; b++){
          for(int c = 0; c < 4; c++){
            fscanf(gg, "%1d", &tes2[a][b][c]);
          }
        }
      }
      fclose(gg);
      for(int g = 0; g < 8; g++){
        for(int h = 0; h < 10; h++){
          for(int i = 0; i < 4; i++){
            sum1 = sum1 + tes1[g][h][i];
            sum2 = sum2 + tes2[g][h][i];
          }
        }
      }
      kuning();
      printf("\n\t\t\t\t\t\t\t\t\t    JUMLAH PENONTON:\n\n");
      normal();
      printf("\t\t\t\t\t\t\t\t    AVENGERS: ENDGAME          : %d\n", sum1);
      printf("\t\t\t\t\t\t\t\t    POKEMON DETECTIVE PIKACHU  : %d\n\n\n", sum2);
      kuning();
      printf("\t\t\t\t\t\t\t   TINGKAT KELARISAN FILM BERDASARKAN BANYAK PENONTON:\n\n");
      normal();
      printf("\t\t\t\t\t\t\t\t    AVENGERS: ENDGAME          : %d%%\n", (sum1 / 240) * 100);
      printf("\t\t\t\t\t\t\t\t    POKEMON DETECTIVE PIKACHU  : %d%%\n\n", (sum2 / 240) * 100);
    }
    merah();
    printf("\n\t\t\t\t\t\t\t\t\t  KEMBALI KE MENU AWAL\n");
    printf("\t\t\t\t\t\t\t\t\t ======================\n");
    normal();
    getch();
    main();
  }
  else{
    system("cls");
    headeradmin();
    merah();
    printf("\n\t\t\t\t\t\t\t\t  MAAF, PASSWORD YANG ANDA INPUT SALAH\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t  KEMBALI KE MENU AWAL\n");
    printf("\t\t\t\t\t\t\t\t\t ======================\n");
    normal();
    getch();
    main();
  }
}
int tiketavenger(int xx, int yy, int c){
  int ta[8][10][4] = {}, key = 0;
  FILE *baca;
  baca = fopen("avenger.txt", "r");
  for(int a = 0; a < 8; a++){
    for(int b = 0; b < 10; b++){
      for(int d = 0; d < 4; d++){
        fscanf(baca, "%1d", &ta[a][b][d]);
      }
    }
  }
  fclose(baca);
  if(ta[xx - 1][yy - 1][c] == 1){
    merah();
    printf("\n\n\t\t\t\t\t\t\t  MAAF, KURSI YANG ANDA PILIH SUDAH DIPESAN SEBELUMNYA\n\n");
    printf("\n\t\t\t\t\t\t\t\t       KEMBALI KE MENU SEBELUMNYA\n");
    printf("\t\t\t\t\t\t\t\t      ============================\n");
    normal();
    key = getch();
    kursipenontonavenger(c);
  }
  else{
    ta[xx - 1][yy - 1][c] = 1;
    hijau();
    printf("\n\n\t\t\t\t\t\t\t\t\t KURSI BERHASIL DIPESAN\n\n");
    merah();
    printf("\n\t\t\t\t\t\t\t\t\t\t LANJUT\n");
    printf("\t\t\t\t\t\t\t\t\t\t========\n");
    normal();
    key = getch();
  }
  FILE *tulis;
  tulis = fopen("avenger.txt", "w");
  for(int a = 0; a < 8; a++){
    for(int b = 0; b < 10; b++){
      for(int d = 0; d < 4; d++){
        fprintf(tulis, "%d", ta[a][b][d]);
      }
    }
  }
  fclose(tulis);
  printtiketavenger(xx, yy, c);
}
int printtiketavenger(int xx, int yy, int c){
  fflush(stdin);
  int kursi[8][10]={
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80}
  };
  int key = 0;
  system("cls");
  headerbelitiket();
  printf("\n\t\t\t\t\t\t\t\t========================================\n");
  printf("\t\t\t\t\t\t\t\t========================================\n\n");
  printf("\t\t\t\t\t\t\t\t              PTKOM CINEMA              \n");
  printf("\t\t\t\t\t\t\t\t________________________________________\n\n\n\n");
  printf("\t\t\t\t\t\t\t\t    FILM    : AVENGERS: ENDGAME         \n");
  printf("\t\t\t\t\t\t\t\t    KURSI   : %d                        \n", kursi[xx - 1][yy - 1]);
  if(c == 0){
    printf("\t\t\t\t\t\t\t\t    JAM     : 14:15                     \n\n\n\n");
  }
  if(c == 1){
    printf("\t\t\t\t\t\t\t\t    JAM     : 17:45                     \n\n\n\n");
  }
  if(c == 2){
    printf("\t\t\t\t\t\t\t\t    JAM     : 21:15                     \n\n\n\n");
  }
  printf("\t\t\t\t\t\t\t\t========================================\n");
  printf("\t\t\t\t\t\t\t\t========================================\n\n\n");
  kuning();
  printf("\t\t\t\t\t\t\t\t    TERIMA KASIH TELAH MEMBELI TIKET\n");
  merah();
  printf("\n\n\t\t\t\t\t\t\t\t\t  KEMBALI KE MENU AWAL\n");
  printf("\t\t\t\t\t\t\t\t\t ======================\n");
  normal();
  key = getch();
  fflush(stdin);
  main();
}
int tiketpikachu(int xx, int yy, int c){
  int ta[8][10][4] = {}, key = 0;
  FILE *baca;
  baca = fopen("pikachu.txt", "r");
  for(int a = 0; a < 8; a++){
    for(int b = 0; b < 10; b++){
      for(int d = 0; d < 4; d++){
        fscanf(baca, "%1d", &ta[a][b][d]);
      }
    }
  }
  fclose(baca);
  if(ta[xx - 1][yy - 1][c] == 1){
    merah();
    printf("\n\n\t\t\t\t\t\t\t  MAAF, KURSI YANG ANDA PILIH SUDAH DIPESAN SEBELUMNYA\n\n");
    printf("\n\t\t\t\t\t\t\t\t       KEMBALI KE MENU SEBELUMNYA\n");
    printf("\t\t\t\t\t\t\t\t      ============================\n");
    normal();
    key = getch();
    kursipenontonpikachu(c);
  }
  else{
    ta[xx - 1][yy - 1][c] = 1;
    hijau();
    printf("\n\n\t\t\t\t\t\t\t\t\t KURSI BERHASIL DIPESAN\n\n");
    merah();
    printf("\n\t\t\t\t\t\t\t\t\t\t LANJUT\n");
    printf("\t\t\t\t\t\t\t\t\t\t========\n");
    normal();key = getch();
  }
  FILE *tulis;
  tulis = fopen("pikachu.txt", "w");
  for(int a = 0; a < 8; a++){
    for(int b = 0; b < 10; b++){
      for(int d = 0; d < 4; d++){
        fprintf(tulis, "%d", ta[a][b][d]);
      }
    }
  }
  fclose(tulis);
  printtiketpikachu(xx, yy, c);
}
int printtiketpikachu(int xx, int yy, int c){
  fflush(stdin);
  int kursi[8][10]={
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80}
  };
  int key = 0;
  system("cls");
  headerbelitiket();
  printf("\n\t\t\t\t\t\t\t\t========================================\n");
  printf("\t\t\t\t\t\t\t\t========================================\n\n");
  printf("\t\t\t\t\t\t\t\t              PTKOM CINEMA              \n");
  printf("\t\t\t\t\t\t\t\t________________________________________\n\n\n\n");
  printf("\t\t\t\t\t\t\t\t    FILM : POKEMON DETECTIVE PIKACHU    \n");
  printf("\t\t\t\t\t\t\t\t    KURSI: %d                           \n", kursi[xx - 1][yy - 1]);
  if(c == 0){
    printf("\t\t\t\t\t\t\t\t    JAM  : 12:15                        \n\n\n\n");
  }
  if(c == 1){
    printf("\t\t\t\t\t\t\t\t    JAM  : 14:30                        \n\n\n\n");
  }
  if(c == 2){
    printf("\t\t\t\t\t\t\t\t    JAM  : 16:45                        \n\n\n\n");
  }
  printf("\t\t\t\t\t\t\t\t========================================\n");
  printf("\t\t\t\t\t\t\t\t========================================\n\n\n");
  kuning();
  printf("\t\t\t\t\t\t\t\t    TERIMA KASIH TELAH MEMBELI TIKET\n");
  merah();
  printf("\n\n\t\t\t\t\t\t\t\t\t  KEMBALI KE MENU AWAL\n");
  printf("\t\t\t\t\t\t\t\t\t ======================\n");
  normal();
  key = getch();
  fflush(stdin);
  main();
}
int bantuan(){
  int key = 0;
  system("cls");
  headerbantuan();
  kuning();
  printf("\n\t\t\t\t\t\t\t\t\t\tPETUNJUK\n\n");
  normal();
  printf("\t\t\t\t    1. BELI TIKET\n");
  printf("\t\t\t\t       Pilih opsi ini untuk mulai memesan tiket untuk film yang sedang tayang.\n\n");
  printf("\t\t\t\t    2. SINOPSIS FILM\n");
  printf("\t\t\t\t       Pilih opsi ini untuk melihat sinopsis film, baik yang sedang tayang maupun yang akan dirilis.\n\n");
  printf("\t\t\t\t    3. NOW PLAYING\n");
  printf("\t\t\t\t       Pilih opsi ini untuk melihat film yang sedang tayang dan jam tayangnya.\n\n");
  printf("\t\t\t\t    4. COMING SOON\n");
  printf("\t\t\t\t       Pilih opsi ini untuk melihat film yang akan dirilis.\n\n");
  printf("\t\t\t\t    5. BANTUAN\n");
  printf("\t\t\t\t       Pilih opsi ini untuk melihat bantuan program.\n\n");
  printf("\t\t\t\t    6. ADMIN MODE\n");
  printf("\t\t\t\t       Pilih opsi ini untuk mengakses menu administrator.\n\n");
  merah();
  printf("\t\t\t\t       PERHATIAN! PASTIKAN ANDA MEMILIKI PASSWORD UNTUK MENGAKSES MENU INI!\n\n");
  normal();
  printf("\t\t\t\t    7. KELUAR\n");
  printf("\t\t\t\t       Pilih opsi ini untuk mengakhiri program.\n\n\n");
  printf("\t\t\t\t\t\t\t\t\t\tNAVIGASI\n\n");
  printf("\t\t\t\t    1. MENU UTAMA\n");
  printf("\t\t\t\t       Gunakan tombol panah atas dan bawah untuk menseleksi opsi.\n\n");
  printf("\t\t\t\t    2. KONFIRMASI\n");
  printf("\t\t\t\t       Gunakan tombol Enter untuk memilih opsi yang sudah diseleksi.\n\n");
  printf("\t\t\t\t    3. MENU MEMILIH KURSI\n");
  printf("\t\t\t\t       Gunakan tombol panah untuk menseleksi kursi yang akan dipesan.\n\n");
  printf("\t\t\t\t    4. KELUAR PADA MENU MEMILIH KURSI\n");
  printf("\t\t\t\t       Gunakan tombol Escape (Esc) untuk keluar dari menu memilih kursi.\n\n\n");
  merah();
  printf("\n\t\t\t\t\t\t\t\t\t  KEMBALI KE MENU AWAL\n");
  printf("\t\t\t\t\t\t\t\t\t ======================\n");
  normal();
  key = getch();
  fflush(stdin);
  main();
}
