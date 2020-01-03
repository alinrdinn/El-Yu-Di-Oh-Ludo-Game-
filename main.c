#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<mmsystem.h>

struct player{
	int giliran;
	int warna;
	char bidak[4];
	COORD posisibidak[4];
	bool bidakdihomebase[4];
	int arahjalanbidak[4]; //0 untuk diam, 1 untuk ke kanan, 2 untuk ke atas, 3 untuk ke kiri, dan 4 untuk kebawah...
	bool bidakdifinish[4]; //true untuk iya dan false untuk tidak.
};

struct player pemain[];

GoToXY(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int MainMenu();
int StartGame();

void PilihBidak(int *nomorbidak){ // Author : Ali
	bool sudahmemilih = false;
	while(!sudahmemilih){
		int nomor;
		scanf("%d", &nomor);
		if (nomor<1 || nomor>4){
			GoToXY(120, 5); printf("Nomor bidak tidak ada (masukkan nomor) ");
		}else{
			*nomorbidak = nomor;
			sudahmemilih = true;
		}
	}
}
					
void GameOver(int pemenang){ //Author : Farra
	system("cls");
	if (pemenang == 0){
		sleep(1);
		GoToXY(27, 4); printf("  ___ ___ _      _   __  __   _ _____   _  __   _   __  __ _   _   __  __ ___ _  _   _   _  _  ___ _ _ _ \n");
		GoToXY(27, 5); printf(" / __| __| |    /_\\ |  \\/  | /_\\_   _| | |/ /  /_\\ |  \\/  | | | | |  \\/  | __| \\| | /_\\ | \\| |/ __| | | |\n");
		GoToXY(27, 6); printf(" \\__ \\ _|| |__ / _ \\| |\\/| |/ _ \\| |   | ' <  / _ \\| |\\/| | |_| | | |\\/| | _|| .` |/ _ \\| .` | (_ |_|_|_|\n");
		GoToXY(27, 7); printf(" |___/___|____/_/ \\_\\_|  |_/_/ \\_\\_|   |_|\\_\\/_/ \\_\\_|  |_|\\___/  |_|  |_|___|_|\\_/_/ \\_\\_|\\_|\\___(_|_|_)\n");
	}
//	if (pemenang == 1){
	//	GoToXY(27, 8); printf(" _  __   _   __  __ _   _   _  __   _   _      _   _  _");
	//	GoToXY(27, 9); printf("| |/ /  /_\\ |  \\/  | | | | | |/ /  /_\\ | |    /_\\ | || |");
	//	GoToXY(27, 10); printf("| ' <  / _ \\| |\\/| | |_| | | ' <  / _ \\| |__ / _ \\| __ |");
	//	GoToXY(27, 11); printf("|_|\\_\\/_/ \\_\\_|  |_|\\___/  |_|\\_\\/_/ \\_\\____/_/ \\_\\_||_|");
	}
	getch();
	MainMenu();
}

void PembunuhBidak(int playerke, int nomorbidak){ //Author : Ali
	int i, j;
	for (i=0; i<4; i++){
		for (j = 0; j<4; j++){
			if ((i != playerke) && (pemain[i].posisibidak[j].X == pemain[playerke].posisibidak[nomorbidak].X) && (pemain[i].posisibidak[j].Y == pemain[playerke].posisibidak[nomorbidak].Y)){
				if (i==0 && j==0){
					pemain[0].posisibidak[0].X = 28;
					pemain[0].posisibidak[0].Y = 8;
					pemain[0].bidakdihomebase[0] = true;
					pemain[0].arahjalanbidak[0] = 1;
				}
				if (i==0 && j==1){
					pemain[0].posisibidak[1].X = 36;
					pemain[0].posisibidak[1].Y = 8;
					pemain[0].bidakdihomebase[1] = true;
					pemain[0].arahjalanbidak[1] = 1;
				}
				if (i==0 && j==2){
					pemain[0].posisibidak[2].X = 28;
					pemain[0].posisibidak[2].Y = 12;
					pemain[0].bidakdihomebase[2] = true;
					pemain[0].arahjalanbidak[2] = 1;
				}
				if (i==0 && j==3){
					pemain[0].posisibidak[3].X = 36;
					pemain[0].posisibidak[3].Y = 12;
					pemain[0].bidakdihomebase[3] = true;
					pemain[0].arahjalanbidak[3] = 1;
				}
				if (i==1 && j==0){
					pemain[1].posisibidak[0].X = 92;
					pemain[1].posisibidak[0].Y = 8;
					pemain[1].bidakdihomebase[0] = true;
					pemain[1].arahjalanbidak[0] = 4;
				}
				if (i==1 && j==1){
					pemain[1].posisibidak[1].X = 100;
					pemain[1].posisibidak[1].Y = 8;
					pemain[1].bidakdihomebase[1] = true;
					pemain[1].arahjalanbidak[1] = 4;
				}
				if (i==1 && j==2){
					pemain[1].posisibidak[2].X = 92;
					pemain[1].posisibidak[2].Y = 12;
					pemain[1].bidakdihomebase[2] = true;
					pemain[1].arahjalanbidak[2] = 4;
				}
				if (i==1 && j==3){
					pemain[1].posisibidak[3].X = 100;
					pemain[1].posisibidak[3].Y = 12;
					pemain[1].bidakdihomebase[3] = true;
					pemain[1].arahjalanbidak[3] = 4;
				}
				if (i==2 && j==0){
					pemain[2].posisibidak[0].X = 92;
					pemain[2].posisibidak[0].Y = 36;
					pemain[2].bidakdihomebase[0] = true;
					pemain[2].arahjalanbidak[0] = 3;
				}
				if (i==2 && j==1){
					pemain[2].posisibidak[1].X = 100;
					pemain[2].posisibidak[1].Y = 36;
					pemain[2].bidakdihomebase[1] = true;
					pemain[2].arahjalanbidak[1] = 3;
				}
				if (i==2 && j==2){
					pemain[2].posisibidak[2].X = 92;
					pemain[2].posisibidak[2].Y = 40;
					pemain[2].bidakdihomebase[2] = true;
					pemain[2].arahjalanbidak[2] = 3;
				}
				if (i==2 && j==3){
					pemain[2].posisibidak[3].X = 100;
					pemain[2].posisibidak[3].Y = 40;
					pemain[2].bidakdihomebase[3] = true;
					pemain[2].arahjalanbidak[3] = 3;
				}
				if (i==3 && j==0){
					pemain[3].posisibidak[0].X = 28;
					pemain[3].posisibidak[0].Y = 36;
					pemain[3].bidakdihomebase[0] = true;
					pemain[3].arahjalanbidak[0] = 2;
				}
				if (i==3 && j==1){
					pemain[3].posisibidak[1].X = 36;
					pemain[3].posisibidak[1].Y = 36;
					pemain[3].bidakdihomebase[1] = true;
					pemain[3].arahjalanbidak[1] = 2;
				}
				if (i==3 && j==2){
					pemain[3].posisibidak[2].X = 28;
					pemain[3].posisibidak[2].Y = 40;
					pemain[3].bidakdihomebase[2] = true;
					pemain[3].arahjalanbidak[1] = 2;
				}
				if (i==3 && j==3){
					pemain[3].posisibidak[2].X = 36;
					pemain[3].posisibidak[2].Y = 40;
					pemain[3].bidakdihomebase[2] = true;
					pemain[3].arahjalanbidak[1] = 2;
				}
			}
		}
	}
}
					
void PenentuPemenang(bool *menang, int *pemenang, int giliran){ // Author : Ali
	int h=0,i;
	while (!(pemain[h].giliran == giliran)){
		h+=1;
	}		
	for (i=0; i<4; i++){
		if (pemain[h].bidakdifinish[i] == false){
			*menang = false;
			return;
		}else {
			*menang = true;
			*pemenang =  h;
		}
	}		
}
int PenggerakBidak(int playerke, int nomorbidak, int dadu){ //Author : Ali
if(playerke == 0 && pemain[playerke].posisibidak[nomorbidak].X == 49 && pemain[playerke].posisibidak[nomorbidak].Y == 24){
		pemain[playerke].posisibidak[nomorbidak].X = 56;
		pemain[playerke].posisibidak[nomorbidak].Y = 24;
		pemain[playerke].arahjalanbidak[nomorbidak] = 0;
		pemain[playerke].bidakdifinish[nomorbidak] = true; //finish hijau (player 1);
	}else if(playerke == 1 && pemain[playerke].posisibidak[nomorbidak].X == 63 && pemain[playerke].posisibidak[nomorbidak].Y == 18){
		pemain[playerke].posisibidak[nomorbidak].X = 63;
		pemain[playerke].posisibidak[nomorbidak].Y = 21;
		pemain[playerke].arahjalanbidak[nomorbidak] = 0;
		pemain[playerke].bidakdifinish[nomorbidak] = true; //finish biru (player 2);
	}else if(playerke == 2 && pemain[playerke].posisibidak[nomorbidak].X == 77 && pemain[playerke].posisibidak[nomorbidak].Y == 24){
		pemain[playerke].posisibidak[nomorbidak].X = 70;
		pemain[playerke].posisibidak[nomorbidak].Y = 24;
		pemain[playerke].arahjalanbidak[nomorbidak] = 0;
		pemain[playerke].bidakdifinish[nomorbidak] = true; //finish merah (player 3);
	}else if(playerke == 3 && pemain[playerke].posisibidak[nomorbidak].X == 63 && pemain[playerke].posisibidak[nomorbidak].Y == 30){
		pemain[playerke].posisibidak[nomorbidak].X = 63;
		pemain[playerke].posisibidak[nomorbidak].Y = 27;
		pemain[playerke].arahjalanbidak[nomorbidak] = 0;
		pemain[playerke].bidakdifinish[nomorbidak] = true; //finish ungu (player 1);
	}else if(playerke == 0 && pemain[playerke].posisibidak[nomorbidak].X == 14 && pemain[playerke].posisibidak[nomorbidak].Y == 24){
		pemain[playerke].posisibidak[nomorbidak].X = 21;
		pemain[playerke].posisibidak[nomorbidak].Y = 24;
		pemain[playerke].arahjalanbidak[nomorbidak] = 1; //menuju garis finish hijau (player 1);
	}else if(playerke == 1 && pemain[playerke].posisibidak[nomorbidak].X == 63 && pemain[playerke].posisibidak[nomorbidak].Y == 3){
		pemain[playerke].posisibidak[nomorbidak].X = 63;
		pemain[playerke].posisibidak[nomorbidak].Y = 6;
		pemain[playerke].arahjalanbidak[nomorbidak] = 4; //menuju garis finish biru (player 2);
	}else if(playerke == 2 && pemain[playerke].posisibidak[nomorbidak].X == 112 && pemain[playerke].posisibidak[nomorbidak].Y == 24){
		pemain[playerke].posisibidak[nomorbidak].X = 105;
		pemain[playerke].posisibidak[nomorbidak].Y = 24;
		pemain[playerke].arahjalanbidak[nomorbidak] = 3; //menuju garis finish merah (player 3);
	}else if(playerke == 3 && pemain[playerke].posisibidak[nomorbidak].X == 63 && pemain[playerke].posisibidak[nomorbidak].Y == 45){
		pemain[playerke].posisibidak[nomorbidak].X = 63;
		pemain[playerke].posisibidak[nomorbidak].Y = 42;
		pemain[playerke].arahjalanbidak[nomorbidak] = 2; //menuju garis finish ungu (player 3);
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 49 && pemain[playerke].posisibidak[nomorbidak].Y == 21){
		pemain[playerke].posisibidak[nomorbidak].X = 56;
		pemain[playerke].posisibidak[nomorbidak].Y = 18;
		pemain[playerke].arahjalanbidak[nomorbidak] = 2;//tengah kiri atas
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 56 && pemain[playerke].posisibidak[nomorbidak].Y == 3){
		pemain[playerke].posisibidak[nomorbidak].X = 63;
		pemain[playerke].posisibidak[nomorbidak].Y = 3;
		pemain[playerke].arahjalanbidak[nomorbidak] = 1;//atas kiri
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 70 && pemain[playerke].posisibidak[nomorbidak].Y == 3){
		pemain[playerke].posisibidak[nomorbidak].X = 70;
		pemain[playerke].posisibidak[nomorbidak].Y = 6;
		pemain[playerke].arahjalanbidak[nomorbidak] = 4;//atas kanan
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 70 && pemain[playerke].posisibidak[nomorbidak].Y == 18){
		pemain[playerke].posisibidak[nomorbidak].X = 77;
		pemain[playerke].posisibidak[nomorbidak].Y = 21;
		pemain[playerke].arahjalanbidak[nomorbidak] = 1;//tengah kanan atas
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 112 && pemain[playerke].posisibidak[nomorbidak].Y == 21){
		pemain[playerke].posisibidak[nomorbidak].X = 112;
		pemain[playerke].posisibidak[nomorbidak].Y = 24;
		pemain[playerke].arahjalanbidak[nomorbidak] = 4;//kanan atas
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 112 && pemain[playerke].posisibidak[nomorbidak].Y == 27){
		pemain[playerke].posisibidak[nomorbidak].X = 105;
		pemain[playerke].posisibidak[nomorbidak].Y = 27;
		pemain[playerke].arahjalanbidak[nomorbidak] = 3;//kanan bawah
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 77 && pemain[playerke].posisibidak[nomorbidak].Y == 27){
		pemain[playerke].posisibidak[nomorbidak].X = 70;
		pemain[playerke].posisibidak[nomorbidak].Y = 30;
		pemain[playerke].arahjalanbidak[nomorbidak] = 4;//tengah kanan bawah
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 70 && pemain[playerke].posisibidak[nomorbidak].Y == 45){
		pemain[playerke].posisibidak[nomorbidak].X = 63;
		pemain[playerke].posisibidak[nomorbidak].Y = 45;
		pemain[playerke].arahjalanbidak[nomorbidak] = 3;//bawah kanan
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 56 && pemain[playerke].posisibidak[nomorbidak].Y == 45){
		pemain[playerke].posisibidak[nomorbidak].X = 56;
		pemain[playerke].posisibidak[nomorbidak].Y = 42;
		pemain[playerke].arahjalanbidak[nomorbidak] = 2;//bawah kiri
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 56 && pemain[playerke].posisibidak[nomorbidak].Y == 30){
		pemain[playerke].posisibidak[nomorbidak].X = 49;
		pemain[playerke].posisibidak[nomorbidak].Y = 27;
		pemain[playerke].arahjalanbidak[nomorbidak] = 3;//tengah kiri bawah
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 14 && pemain[playerke].posisibidak[nomorbidak].Y == 27){
		pemain[playerke].posisibidak[nomorbidak].X = 14;
		pemain[playerke].posisibidak[nomorbidak].Y = 24;
		pemain[playerke].arahjalanbidak[nomorbidak] = 2;//kiri bawah
	}else if(pemain[playerke].posisibidak[nomorbidak].X == 14 && pemain[playerke].posisibidak[nomorbidak].Y == 21){
		pemain[playerke].posisibidak[nomorbidak].X = 21;
		pemain[playerke].posisibidak[nomorbidak].Y = 21;
		pemain[playerke].arahjalanbidak[nomorbidak] = 1;//kiri atas
	}else if(pemain[playerke].arahjalanbidak[nomorbidak] == 1){
		pemain[playerke].posisibidak[nomorbidak].X += 7;
	}else if(pemain[playerke].arahjalanbidak[nomorbidak] == 2){
		pemain[playerke].posisibidak[nomorbidak].Y -= 3;
	}else if(pemain[playerke].arahjalanbidak[nomorbidak] == 3){
		pemain[playerke].posisibidak[nomorbidak].X -= 7;
	}else if(pemain[playerke].arahjalanbidak[nomorbidak] == 4){
		pemain[playerke].posisibidak[nomorbidak].Y += 3;
	}
}
int KeluarHomeBase(int playerke, int nomorbidak){ //Author : Farra & Ali
	if (playerke == 0){
		pemain[playerke].posisibidak[nomorbidak].X = 21;
		pemain[playerke].posisibidak[nomorbidak].Y = 21;
		pemain[playerke].bidakdihomebase[nomorbidak] = false;
	}
	if (playerke == 1){
		pemain[playerke].posisibidak[nomorbidak].X = 70;
		pemain[playerke].posisibidak[nomorbidak].Y = 6;
		pemain[playerke].bidakdihomebase[nomorbidak] = false;
	}
	if (playerke == 2){
		pemain[playerke].posisibidak[nomorbidak].X = 105;
		pemain[playerke].posisibidak[nomorbidak].Y = 27;
		pemain[playerke].bidakdihomebase[nomorbidak] = false;
	}
	if (playerke == 3){
		pemain[playerke].posisibidak[nomorbidak].X = 56;
		pemain[playerke].posisibidak[nomorbidak].Y = 42;
		pemain[playerke].bidakdihomebase[nomorbidak] = false;
	}
}

void PenentuWarna(unsigned short color){ // Author : Farra & Ali
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hCon,color);
}
void RandomDadu(int angkadadu){ //Author : Farra
	switch(angkadadu) {
	case 0 :
	GoToXY(135,10);printf(" ___________");
	GoToXY(135,11);printf("|           |");
	GoToXY(135,12);printf("|           |");
	GoToXY(135,13);printf("|           |");
	GoToXY(135,14);printf("|           |");
	GoToXY(135,15);printf("|___________|");	
	break;
	PenentuWarna(7);
	case  1 :
	PenentuWarna(1); //warna : biru tua
	GoToXY(135,10);printf(" ___________");
	GoToXY(135,11);printf("|           |");
	GoToXY(135,12);printf("|           |");
	GoToXY(135,13);printf("|     *     |");
	GoToXY(135,14);printf("|           |");
	GoToXY(135,15);printf("|___________|");
	PenentuWarna(7);
	break;
	case 2 :
	PenentuWarna(2); //warna : hijau
	GoToXY(135,10);printf(" ___________");
	GoToXY(135,11);printf("|           |");
	GoToXY(135,12);printf("|       *   |");
	GoToXY(135,13);printf("|           |");
	GoToXY(135,14);printf("|   *       |");
	GoToXY(135,15);printf("|___________|");
	PenentuWarna(7);
	break;
	case 3 : 
	PenentuWarna(3); //warna : biru muda
	GoToXY(135,10);printf(" ___________");
	GoToXY(135,11);printf("|           |");
	GoToXY(135,12);printf("|       *   |");
	GoToXY(135,13);printf("|     *     |");
	GoToXY(135,14);printf("|   *       |");
	GoToXY(135,15);printf("|___________|");
	PenentuWarna(7);
	break;
	case 4 : 
	PenentuWarna(4); //warna : merah
	GoToXY(135,10);printf(" ___________");
	GoToXY(135,11);printf("|           |");
	GoToXY(135,12);printf("|  *     *  |");
	GoToXY(135,13);printf("|           |");
	GoToXY(135,14);printf("|  *     *  |");
	GoToXY(135,15);printf("|___________|");
	PenentuWarna(7);
	break;
	case 5 :
	PenentuWarna(5); //warna : ungu
	GoToXY(135,10);printf(" ___________");
	GoToXY(135,11);printf("|           |");
	GoToXY(135,12);printf("|  *     *  |");
	GoToXY(135,13);printf("|     *     |");
	GoToXY(135,14);printf("|  *     *  |");
	GoToXY(135,15);printf("|___________|");
	PenentuWarna(7);
	break;
	case 6 :
	PenentuWarna(6); //warna : orange
	GoToXY(135,10);printf(" ___________");
	GoToXY(135,11);printf("|           |");
	GoToXY(135,12);printf("|  *     *  |");
	GoToXY(135,13);printf("|  *     *  |");
	GoToXY(135,14);printf("|  *     *  |");
	GoToXY(135,15);printf("|___________|");
	PenentuWarna(7);
	break;
	}
}
int * PenentuUrutan(int urutanpemain[], int jumlahpemain){ //Author : Ali
	int a[jumlahpemain], i, urutan;
	int urutanakhir = 0;
	urutan = (rand()%jumlahpemain)+1;
	a[0] = urutan;
	for (i=1; i<jumlahpemain; i++){
        a[i] = a[i-1]-1;
    }
    for(i=1; i<jumlahpemain; i++){        
    	if (a[i]<1 || a[i]>jumlahpemain){
        	a[i] =jumlahpemain;
        	urutanakhir=i;
        	i=jumlahpemain+1;
        }
    }
    if (urutanakhir != 0){
      for (i=urutanakhir+1;i<jumlahpemain;i++){
          a[i]=a[i-1]-1;
      }
    }
      for(i=0; i<jumlahpemain;i++){
          urutanpemain[i] = a[i];
      }
    for(i=0; i<jumlahpemain; i++){
    	if (i>=1){
    		GoToXY(60, 22+i); printf("- Urutan komputer%d : %d", i, urutanpemain[i]);
		}else{
 		   	GoToXY(60, 22+i); printf("- Urutan pemain: %d", urutanpemain[i]);
		}
	}
    
    getch();
    return a;
}
void Opening(){  //Author : Farra
	int i,j,k;
	int d=10;
	GoToXY(75, 6);
	char a[]="           Welcome to\n";

	for (k=0;k<24;k++){
		PenentuWarna(6);
		int q;
		for(q=0;q<10000000;q++){
		}
		printf("%c", a[k]);
	}
	
	char teks1[114]={"------------------------------------------------------------------------------------------------------------------"};
	char teks2[114]={"******************************************************************************************************************"};
	char teks3[114]={"------------------------------------------------------------------------------------------------------------------"};
	char teksLudo1[111]={"       _|_|_|_|  _|            _|      _|                        _|_|_|    _|                _|_|    _|        "};
	char teksLudo2[111]={"       _|        _|              _|  _|    _|    _|              _|    _|                  _|    _|  _|_|_|    "};
	char teksLudo3[111]={"       _|_|_|    _|  _|_|_|_|_|    _|      _|    _|  _|_|_|_|_|  _|    _|  _|  _|_|_|_|_|  _|    _|  _|    _|  "};
	char teksLudo4[111]={"       _|        _|                _|      _|    _|              _|    _|  _|              _|    _|  _|    _|  "};
	char teksLudo5[111]={"       _|_|_|_|  _|_|_|_|          _|        _|_|_|              _|_|_|    _|                _|_|    _|    _|  "};
	char teksLudo6[111]={"                G                        A                              M                          E           "};
	char teks4[114]={"------------------------------------------------------------------------------------------------------------------"};
	char teks5[114]={"******************************************************************************************************************"};
	char teks6[114]={"------------------------------------------------------------------------------------------------------------------"};
	for(i=0;i<114;i++){
		PenentuWarna(1);
		GoToXY(30+i,8);printf("%c",teks1[i]);
		for(j=0;j<900000;j++){
		}
	}
	
	for(i=0;i<114;i++){
		PenentuWarna(3);
		GoToXY(30+i,10);printf("%c",teks2[i]);
		for(j=0;j<900000;j++){
		}
		}
	for(i=0;i<114;i++){
		PenentuWarna(1);
		GoToXY(30+i,12);printf("%c",teks3[i]);
		for(j=0;j<900000;j++){
		}
		}
	for(i=0;i<114;i++){
		PenentuWarna(1);
		GoToXY(30+i,30);printf("%c",teks4[i]);
		for(j=0;j<900000;j++){
		}
	}
	for(i=0;i<114;i++){
		PenentuWarna(3);
		GoToXY(30+i,32);printf("%c",teks5[i]);
		for(j=0;j<900000;j++){
		}
	}
	for(i=0;i<114;i++){
		PenentuWarna(1);
		GoToXY(30+i, 34);printf("%c",teks6[i]);
		for(j=0;j<900000;j++){
		}
	}
	
	for(i=0;i<111;i++){
		PenentuWarna(6);
		GoToXY(30+i,16);printf("%c",teksLudo1[i]);
			for(j=0;j<900000;j++){
		}
	}
	for(i=0;i<111;i++){
		PenentuWarna(6);
		GoToXY(30+i,18);printf("%c",teksLudo2[i]);
			for(j=0;j<900000;j++){
		}
	}
	for(i=0;i<111;i++){
		PenentuWarna(6);
		GoToXY(30+i,20);printf("%c",teksLudo3[i]);
			for(j=0;j<900000;j++){
		}
	}
	for(i=0;i<111;i++){
		PenentuWarna(6);
		GoToXY(30+i,22);printf("%c",teksLudo4[i]);
			for(j=0;j<900000;j++){
		}
	}
	for(i=0;i<111;i++){
		PenentuWarna(6);
		GoToXY(30+i,24);printf("%c",teksLudo5[i]);
			for(j=0;j<900000;j++){
		}
	}
	for(i=0;i<111;i++){
		PenentuWarna(6);
		GoToXY(30+i,26);printf("%c",teksLudo6[i]);
			for(j=0;j<900000;j++){
		}
	}
	char b[]="created by Ali Nurdin (191524004)\n";
	char c[]="and Farra Jessica (191524008)\n";
	GoToXY(69.5, 35);
	for (k=0;k<35;k++){
		PenentuWarna(6);
		int q;
		for(q=0;q<10000000;q++){
		}
		printf("%c", b[k]);
	}
	GoToXY(71.5, 36);
	for (k=0;k<31;k++){
		PenentuWarna(6);
		int q;
		for(q=0;q<10000000;q++){
		}
		printf("%c", c[k]);
	}
	PenentuWarna(4);
	GoToXY(67.5, 37);
	printf("Tekan enter untuk masuk ke main menu");
	getch();
	system("cls");
	PenentuWarna(7);
}
void Instruction(){ //Author : Farra
	system("cls");
	PenentuWarna(6);
	FILE *instruksi;
	char instruksi01[2395];
	
	instruksi = fopen("instruksi.txt", "r");
	
	if(!instruksi){
		printf("File Instruksi tidak ditemukan!.");
	}
	GoToXY(78,1);
	printf("INSTRUKSI\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	while (fgets(instruksi01, 2395, instruksi)!=NULL){
		printf("%s", instruksi01);
		}
	fclose(instruksi);
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	PenentuWarna(4);
	printf("Tekan huruf S untuk memulai permainan...");
	getch();
	system("cls");
	PenentuWarna(7);
	StartGame();
}
void TampilPapanPermainan(){ // Author : Farra & Ali
	int i;
	system("cls");
	for (i=0; i<=8; i+=8){
		PenentuWarna(2);
		GoToXY(26+i, 6); printf(" _____ ");
		GoToXY(26+i, 7); printf("|     |");
		GoToXY(26+i, 8); printf("|     |");
		GoToXY(26+i, 9); printf("|_____|");
		GoToXY(26+i, 10); printf(" _____ ");
		GoToXY(26+i, 11); printf("|     |");
		GoToXY(26+i, 12); printf("|     |");
		GoToXY(26+i, 13); printf("|_____|");
		PenentuWarna(7);	
	}
	
	GoToXY(13, 46);
	for(i=0; i<105; i++){
		printf("_");
	}	
	for (i=14; i<52; i=i+8){
		int y = 19, a = 62;
		if (i!=12){
			i=i-1;
		}
		//timur
		GoToXY(i, y);	printf("______\n");
		GoToXY(i, y+1); printf("      |\n");
		GoToXY(i, y+2); printf("      |\n");
		GoToXY(i, y+3); printf("______|\n");
		if(i>=14 && i<=21){
			PenentuWarna(2);
			GoToXY(i-1, y);	printf(" ______\n");
			GoToXY(i-1, y+1); printf("|      |\n");
			GoToXY(i-1, y+2); printf("|      |\n");
			GoToXY(i-1, y+3); printf("|______|\n");
			GoToXY(i-1, y+4); printf("|      |\n");
			GoToXY(i-1, y+5); printf("|      |\n");
			GoToXY(i-1, y+6); printf("|______|\n");
			}
		if(i>=14){
			PenentuWarna(2);
		}
		GoToXY(i, y+3); printf("______\n");
		GoToXY(i, y+4); printf("      |\n");
		GoToXY(i, y+5); printf("      |\n");
		GoToXY(i, y+6); printf("______|\n");
		PenentuWarna(7);
		GoToXY(i, y+7); printf("      |\n");
		GoToXY(i, y+8); printf("      |\n");
		GoToXY(i, y+9); printf("______|\n");
		//barat
		GoToXY(i+a, y);	  printf(" ______\n");
		GoToXY(i+a, y+1); printf("|      \n");
		GoToXY(i+a, y+2); printf("|      \n");
		GoToXY(i+a, y+3); printf("|______\n");
		if(i>=13 && i<44){
			PenentuWarna(4);
		}
		GoToXY(i+a, y+4); printf("|      \n");
		GoToXY(i+a, y+5); printf("|      \n");
		GoToXY(i+a, y+6); printf("|______\n");
		int barat;
		
		PenentuWarna(7);
		GoToXY(i+a, y+7); printf("|      \n");
		GoToXY(i+a, y+8); printf("|      \n");
		GoToXY(i+a, y+9); printf("|______\n");
		PenentuWarna(4);
		if(i>=35 &&i<54){
		for(barat=0; barat<=4; barat+=4){
			GoToXY(41+a, y+4); printf("|      |\n");
			GoToXY(41+a, y+5); printf("|      |\n");
			GoToXY(41+a, y+6); printf("|______|\n");
			GoToXY(41+a, y+7); printf("|      |\n");
			GoToXY(41+a, y+8); printf("|      |\n");
			GoToXY(41+a, y+9); printf("|______|\n");
			}
		}
		if(i<+42){
			GoToXY(i+a+1, y+3); printf("______\n");
		}
		PenentuWarna(7);
	}
	for (i=3; i<20; i=i+3){
		int x = 54;
		//utara
		GoToXY(x, i-1);	printf("|      |\n");
		GoToXY(x, i); printf("|      |\n");
		GoToXY(x, i+1); printf("|______|\n");
		GoToXY(x+14, i-1); printf("|      |\n");
		GoToXY(x+14, i); printf("|      |\n");
		GoToXY(x+14, i+1); printf("|______|\n");
		int utara;
		if (i==6){
			PenentuWarna(3);
			GoToXY(x+15, i-2); printf("______\n");
			GoToXY(x+8, i-2); printf("______\n");
			GoToXY(x+14, i-1); printf("|      |\n");
			GoToXY(x+14, i); printf("|      |\n");
			GoToXY(x+14, i+1); printf("|______|\n");
		} PenentuWarna(7);
		
		if(i>=6 && i<20){
			PenentuWarna(3);
		}
		GoToXY(x+7, i-1); printf("|      |\n");
		GoToXY(x+7, i); printf("|      |\n");
		GoToXY(x+7, i+1); printf("|______|\n");
		PenentuWarna(7);
		//selatan
		GoToXY(x, i+26); printf("|      |\n");
		GoToXY(x, i+27); printf("|      |\n");
		GoToXY(x, i+28); printf("|______|\n");
		GoToXY(x+14, i+26); printf("|      |\n");
		GoToXY(x+14, i+27); printf("|      |\n");
		GoToXY(x+14, i+28); printf("|______|\n");
		if (i>=0 && i<13){
		PenentuWarna(5);
		}
		GoToXY(x+7, i+26); printf("|      |\n");
		GoToXY(x+7, i+27); printf("|      |\n");
		GoToXY(x+7, i+28); printf("|______|\n");
		PenentuWarna(7);
	}
	GoToXY(13, 1);
	for(i=1; i<=105; i++){
		printf("_");
	}
	for (i=2; i<=46; i++){
		GoToXY(12, i);
		printf("|");
	}
	for (i=2; i<=46; i++){
		GoToXY(117, i);
		printf("|");
	}
	
	i= 15;
	if(i>13){
		int x=54;
		PenentuWarna(5);
		GoToXY(x+1, i+25); printf("______\n");
		GoToXY(x, i+26); printf("|      |\n");
		GoToXY(x, i+27); printf("|      |\n");
		GoToXY(x, i+28); printf("|______|\n");
		GoToXY(x+8, i+25); printf("______\n");
		GoToXY(x+7, i+26); printf("|      |\n");
		GoToXY(x+7, i+27); printf("|      |\n");
		GoToXY(x+7, i+28); printf("|______|\n");
		PenentuWarna(7);
	}
	for (i=0; i<=8; i+=8){
		int j=34;
		PenentuWarna(5);
		GoToXY(26+i, j); printf(" _____ ");
		GoToXY(26+i, j+1); printf("|     |");
		GoToXY(26+i, j+2); printf("|     |");
		GoToXY(26+i, j+3); printf("|_____|");
		GoToXY(26+i, j+4); printf(" _____ ");
		GoToXY(26+i, j+5); printf("|     |");
		GoToXY(26+i, j+6); printf("|     |");
		GoToXY(26+i, j+7); printf("|_____|");
		PenentuWarna(7);
	}	
	for (i=0; i<=8; i+=8){
		PenentuWarna(3);
		int j=90;
		GoToXY(j+i, 6); printf(" _____ ");
		GoToXY(j+i, 7); printf("|     |");
		GoToXY(j+i, 8); printf("|     |");
		GoToXY(j+i, 9); printf("|_____|");
		GoToXY(j+i, 10); printf(" _____ ");
		GoToXY(j+i, 11); printf("|     |");
		GoToXY(j+i, 12); printf("|     |");
		GoToXY(j+i, 13); printf("|_____|");
		PenentuWarna(7);	
	}
	for (i=0; i<=8; i+=8){
		PenentuWarna(4);
		int j=90, n=34;
		GoToXY(j+i, n); printf(" _____ ");
		GoToXY(j+i, n+1); printf("|     |");
		GoToXY(j+i, n+2); printf("|     |");
		GoToXY(j+i, n+3); printf("|_____|");
		GoToXY(j+i, n+4); printf(" _____ ");
		GoToXY(j+i, n+5); printf("|     |");
		GoToXY(j+i, n+6); printf("|     |");
		GoToXY(j+i, n+7); printf("|_____|");
		PenentuWarna(7);	
	}
	GoToXY(55, 28); printf("______ ");
	PenentuWarna(5); GoToXY(62, 28); printf("______ "); PenentuWarna(7);
	GoToXY(69, 28); printf("______ ");
	
	GoToXY(32, 4); PenentuWarna(2); printf("User");
	GoToXY(91, 4); PenentuWarna(3); printf("Komputer 1");
	GoToXY(91, 32); PenentuWarna(4); printf("Komputer 2");
	GoToXY(27, 32); PenentuWarna(5); printf("Komputer 3");
	PenentuWarna(7);
	GoToXY(75, 28); printf("|");
	GoToXY(55, 20); printf("      :      :      "); 
	GoToXY(55, 21); printf("      :      :      "); 
	GoToXY(55, 22); printf("......:......:......");
	GoToXY(55, 23); printf("      :      :      ");
	GoToXY(55, 24); printf("      :      :      ");
	GoToXY(55, 25); printf("......:......:......");
	GoToXY(55, 26); printf("      :      :      ");
	GoToXY(55, 27); printf("      :      :      ");
	GoToXY(61, 28); printf(":");GoToXY(68, 28); printf(":");
	  
	
}
MainMenu(){ //Author : Farra
	int i;
	PenentuWarna(6);
	GoToXY(80.5, 10);
	printf("S. Start Game\n");
	GoToXY(80.5,15);
	printf("I.  Instruction\n");
	GoToXY(80.5,20);
	printf("E. Exit\n");
	PenentuWarna(4);
	GoToXY(70.5, 25);
	printf("Masukkan huruf yang tertera diatas ");
	PenentuWarna(7);
	scanf("%c", &i);
		if (i == 'S' || i == 's'){
			StartGame();
		} else if (i == 'I' || i == 'i'){
			Instruction();
		} else if(i == 'E' || i == 'e'){
			exit(1);
		}
		PenentuWarna(7);
}
int JumlahPemain(){ // Author : Farra
	int j=60;
	PenentuWarna(4);
	GoToXY(j, 20);
	printf("Masukkan jumlah lawan (komputer) (1-3):  \n");
	PenentuWarna(7);
	int jumlahpemain, i;
	GoToXY(j+40, 20); scanf("%d", &jumlahpemain);
	if (jumlahpemain<1 || jumlahpemain>3){
		PenentuWarna(4);
		GoToXY(62, 20); printf("Masukan jumlah pemain >= 1 atau <=3.\n");
		PenentuWarna(7);
		return JumlahPemain();
	}
	return jumlahpemain;
}

void initial(int jumlahpemain){ //Author : Ali
	int j, i;
	for (j=0; j<jumlahpemain; j++){	
		for(i=0; i<4; i++){
			pemain[j].bidakdihomebase[i] = true;
			pemain[j].bidakdifinish[i] = false;
		}
	}
	for(i=0; i<4; i++){
		pemain[0].arahjalanbidak[i] = 1;
		pemain[1].arahjalanbidak[i] = 4;
		pemain[2].arahjalanbidak[i] = 3;
		pemain[3].arahjalanbidak[i] = 2;
	}
	if(jumlahpemain >= 2){
		pemain[0].posisibidak[0].X = 28;
		pemain[0].posisibidak[0].Y = 8;	
		pemain[0].posisibidak[1].X = 36;
		pemain[0].posisibidak[1].Y = 8;
		pemain[0].posisibidak[2].X = 28;
		pemain[0].posisibidak[2].Y = 12;
		pemain[0].posisibidak[3].X = 36;
		pemain[0].posisibidak[3].Y = 12;
		pemain[1].posisibidak[0].X = 92;
		pemain[1].posisibidak[0].Y = 8;	
		pemain[1].posisibidak[1].X = 100;
		pemain[1].posisibidak[1].Y = 8;
		pemain[1].posisibidak[2].X = 92;
		pemain[1].posisibidak[2].Y = 12;
		pemain[1].posisibidak[3].X = 100;
		pemain[1].posisibidak[3].Y = 12;
	}
	if (jumlahpemain >= 3){
		pemain[2].posisibidak[0].X = 92;
		pemain[2].posisibidak[0].Y = 36;	
		pemain[2].posisibidak[1].X = 100;
		pemain[2].posisibidak[1].Y = 36;
		pemain[2].posisibidak[2].X = 92;
		pemain[2].posisibidak[2].Y = 40;
		pemain[2].posisibidak[3].X = 100;
		pemain[2].posisibidak[3].Y = 40;
	}
	if (jumlahpemain == 4){
		pemain[3].posisibidak[0].X = 28;
		pemain[3].posisibidak[0].Y = 36;	
		pemain[3].posisibidak[1].X = 36;
		pemain[3].posisibidak[1].Y = 36;
		pemain[3].posisibidak[2].X = 28;
		pemain[3].posisibidak[2].Y = 40;
		pemain[3].posisibidak[3].X = 36;
		pemain[3].posisibidak[3].Y = 40;
	}
}
void printbidak(int jumlahpemain){ //Author : Ali
	int j, i;
	for(j=0; j<jumlahpemain+1; j++){
		for(i=0; i<4; i++){
			PenentuWarna(pemain[j].warna);
			GoToXY(pemain[j].posisibidak[i].X, pemain[j].posisibidak[i].Y);
			printf("%d", i+1);
			PenentuWarna(7);
		}
	}
}
StartGame(){ //Author : Farra & Ali
	int jumlahpemain, penentuurutan, i, n;
	system("cls");
	jumlahpemain = JumlahPemain();
	int urutanpemain[jumlahpemain+1];
	PenentuUrutan(urutanpemain, jumlahpemain+1);
	for(i=0; i<jumlahpemain+1; i++){
		int j;
		pemain[i].giliran = urutanpemain[i];
		pemain[i].warna = i+2;
		for (j=0; j<4; j++){
			pemain[i].bidak[j] = j;
		}
	}
	initial(jumlahpemain+1);
	system("cls");
	bool menang = false;
	int pemenang;
	int playerke = 0;
	while (menang != true){
		int giliran, m;
		for (giliran=1; giliran<=jumlahpemain+1; giliran++){
			TampilPapanPermainan();
			printbidak(jumlahpemain+1);
			int nomorbidak, jumlahbidakdilintasan = 0;
			bool semuabidakdibase = true, sudahmilih = false , adabidakdilintasan = false;
			int dadu = rand()%6 + 1;
			if (pemain[playerke].giliran == giliran){
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == false && pemain[playerke].bidakdifinish[m] == false){
						adabidakdilintasan = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == false && pemain[playerke].bidakdifinish[m] == false){
						jumlahbidakdilintasan++;
					}
				}
				PenentuWarna(4);
				GoToXY(120, 4); printf("Tekan enter untuk mengocok dadu...");
				PenentuWarna(7);
				getch();
				int TampilDadu01, waktudadu;
				for(TampilDadu01=0; TampilDadu01<=dadu;TampilDadu01++){
					RandomDadu(TampilDadu01);
				for(waktudadu=0; waktudadu<=90000000; waktudadu++){
			 		}
				}
			
				GoToXY(120, 4); printf("Kamu mendapat angka dadu %d             ", dadu);
				if(!adabidakdilintasan && (semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Kamu tidak bisa mengeluarkan bidak...\n");
					GoToXY(120, 6); system("pause");
				}else if(!adabidakdilintasan && (!semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Kamu tidak bisa mengeluarkan bidak...\n");
					GoToXY(120, 6); system("pause");
				}else if(!adabidakdilintasan && semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak yang mau dikeluarkan (1-4) ");
					PenentuWarna(7);
					PilihBidak(&nomorbidak);
					KeluarHomeBase(playerke, nomorbidak-1);
				}else if(!semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak (1-4) ");
					PenentuWarna(7);
					PilihBidak(&nomorbidak);//scanf("%d", &nomorbidak);
					if (pemain[playerke].bidakdihomebase[nomorbidak-1] == true ){
						KeluarHomeBase(playerke, nomorbidak-1);
					}else{
						if((jumlahbidakdilintasan<=1) && (pemain[playerke].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<56) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24)){	
							bool tidakbisa = true;
							while (tidakbisa){
								PenentuWarna(4);
								GoToXY(120, 5); printf("Pilih bidak lain...                 ");
								PenentuWarna(7);
								PilihBidak(&nomorbidak);
								if((pemain[playerke].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<56) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24)){
								}else{
									tidakbisa = false;
								}
							}
						}
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke, nomorbidak-1, dadu);
						}
					}	
				}else if(adabidakdilintasan && !semuabidakdibase && dadu<6){
					//code baru
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih bidak yang mau dijalankan ");
					PenentuWarna(7);
					PilihBidak(&nomorbidak);
					if (jumlahbidakdilintasan>1){
						while((pemain[playerke].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<56) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24)){
							PenentuWarna(4);
							GoToXY(120, 5); printf("Pilih bidak lain...             ");
							PenentuWarna(7);
							PilihBidak(&nomorbidak);
						}
					}
					bool boleh = false;
					while  (!boleh){
						if (pemain[playerke].bidakdihomebase[nomorbidak-1] == false && pemain[playerke].bidakdifinish[nomorbidak-1] == false){
							boleh = true;
						}else{
							PenentuWarna(4);
							GoToXY(120, 5); printf("Pilih bidak lain...                ");
							PenentuWarna(7);
							PilihBidak(&nomorbidak);
						}
					}
						if((pemain[playerke].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<56) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24)){
						}else if (pemain[playerke].bidakdihomebase[nomorbidak-1] == false ){
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke, nomorbidak-1, dadu);
						}
					}
				}
				PembunuhBidak(playerke, nomorbidak-1);
			}else if (pemain[playerke+1].giliran == giliran){
				//Beginnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
				for (m=0; m<4; m++){
					if (pemain[playerke+1].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke+1].bidakdihomebase[m] == false && pemain[playerke+1].bidakdifinish[m] == false){
						adabidakdilintasan = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke+1].bidakdihomebase[m] == false && pemain[playerke+1].bidakdifinish[m] == false){
						jumlahbidakdilintasan++;
					}
				}
				GoToXY(120, 4); printf("Komputer 1 mengocok dadu...             ");
				int TampilDadu01, waktudadu;
				for(TampilDadu01=0; TampilDadu01<=dadu;TampilDadu01++){
					RandomDadu(TampilDadu01);
				for(waktudadu=0; waktudadu<=90000000; waktudadu++){
			 		}
				}
				GoToXY(120, 4); printf("Komputer 1 mendapat angka dadu %d.......", dadu);
				if(!adabidakdilintasan && (semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Komputer 1 tidak bisa mengeluarkan bidak...\n");
					sleep(2);
				}else if(!adabidakdilintasan && (!semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Komputer 1 tidak bisa mengeluarkan bidak...\n");
					sleep(2);
				}else if(!adabidakdilintasan && semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak yang mau dikeluarkan (1-4) ");
					PenentuWarna(7);
					sleep(2);
					nomorbidak = rand()%4+1;
					KeluarHomeBase(playerke+1, nomorbidak-1);
					GoToXY(120, 6); printf("Komputer 1 mengeluarkan bidak nomor %d", nomorbidak);
					sleep(2);
				}else if(!semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak (1-4) ");
					PenentuWarna(7);
					sleep(2);
					nomorbidak = rand()%4+1;
					if (pemain[playerke+1].bidakdihomebase[nomorbidak-1] == true ){
						KeluarHomeBase(playerke+1, nomorbidak-1);
						GoToXY(120, 6); printf("Komputer 1 mengeluarkan bidak nomor %d", nomorbidak);
						sleep(2);
					}else{
						if((jumlahbidakdilintasan<=1) && (pemain[playerke+1].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke+1].posisibidak[nomorbidak-1].X) && (pemain[playerke+1].posisibidak[nomorbidak-1].X<56) && (pemain[playerke+1].posisibidak[nomorbidak-1].Y == 24)){	
							bool tidakbisa = true;
							while (tidakbisa){
								nomorbidak = rand()%4+1;
								if((pemain[playerke].posisibidak[nomorbidak-1].Y+(dadu*3) > 24) && (6<=pemain[playerke+1].posisibidak[nomorbidak-1].Y) && (pemain[playerke+1].posisibidak[nomorbidak-1].Y<21) && (playerke==1) && (pemain[playerke+1].posisibidak[nomorbidak-1].X == 63)){
								}else{
									tidakbisa = false;
								}
							}
						}
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke+1, nomorbidak-1, dadu);
						}
						GoToXY(120, 6); printf("Komputer 1 menggerakkan bidak nomor %d", nomorbidak);
						sleep(2);
					}	
				}else if(adabidakdilintasan && !semuabidakdibase && dadu<6){
					//code baru
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih bidak yang mau dijalankan");
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					if (jumlahbidakdilintasan>1){
						while((pemain[playerke].posisibidak[nomorbidak-1].Y+(dadu*3) > 24) && (6<=pemain[playerke+1].posisibidak[nomorbidak-1].Y) && (pemain[playerke+1].posisibidak[nomorbidak-1].Y<21) && (playerke==1) && (pemain[playerke+1].posisibidak[nomorbidak-1].X == 63)){
							nomorbidak = rand()%4+1;
						}
					}
					bool boleh = false;
					while  (!boleh){
						if (pemain[playerke+1].bidakdihomebase[nomorbidak-1] == false && pemain[playerke+1].bidakdifinish[nomorbidak-1] == false){
							boleh = true;
						}else{
							nomorbidak = rand()%4+1;
						}
					}
						if((pemain[playerke].posisibidak[nomorbidak-1].Y+(dadu*3) > 24) && (6<=pemain[playerke+1].posisibidak[nomorbidak-1].Y) && (pemain[playerke+1].posisibidak[nomorbidak-1].Y<21) && (playerke==1) && (pemain[playerke+1].posisibidak[nomorbidak-1].X == 63)){
						}else if (pemain[playerke+1].bidakdihomebase[nomorbidak-1] == false ){
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke+1, nomorbidak-1, dadu);
							GoToXY(120, 6); printf("Komputer 1 menggerakkan bidak nomor %d", nomorbidak);
							sleep(2);
						}
					}
				}
				PembunuhBidak(playerke+1, nomorbidak-1);
				//Enddddddddddddddddddddddddddddddddddddddd
			}else if (pemain[playerke+2].giliran == giliran){
				//Beginnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
				for (m=0; m<4; m++){
					if (pemain[playerke+2].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke+2].bidakdihomebase[m] == false && pemain[playerke+2].bidakdifinish[m] == false){
						adabidakdilintasan = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke+2].bidakdihomebase[m] == false && pemain[playerke+2].bidakdifinish[m] == false){
						jumlahbidakdilintasan++;
					}
				}
				GoToXY(120, 4); printf("Komputer 2 mengocok dadu...             ");
				int TampilDadu01, waktudadu;
				for(TampilDadu01=0; TampilDadu01<=dadu;TampilDadu01++){
					RandomDadu(TampilDadu01);
				for(waktudadu=0; waktudadu<=90000000; waktudadu++){
			 		}
				}
				GoToXY(120, 4); printf("Komputer 2 mendapat angka dadu %d.......", dadu);
				if(!adabidakdilintasan && (semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Komputer 2 tidak bisa mengeluarkan bidak...\n");
					sleep(2);
				}else if(!adabidakdilintasan && (!semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Komputer 2 tidak bisa mengeluarkan bidak...\n");
					sleep(2);
				}else if(!adabidakdilintasan && semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak yang mau dikeluarkan (1-4) ");
					PenentuWarna(7);
					sleep(2);
					nomorbidak = rand()%4+1;
					KeluarHomeBase(playerke+2, nomorbidak-1);
					GoToXY(120, 6); printf("Komputer 2 mengeluarkan bidak nomor %d", nomorbidak);
					sleep(2);
				}else if(!semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak (1-4) ");
					PenentuWarna(7);
					sleep(2);
					nomorbidak = rand()%4+1;
					if (pemain[playerke+2].bidakdihomebase[nomorbidak-1] == true ){
						KeluarHomeBase(playerke+2, nomorbidak-1);
						GoToXY(120, 6); printf("Komputer 2 mengeluarkan bidak nomor %d", nomorbidak);
						sleep(2);
					}else{
						if((jumlahbidakdilintasan<=1) && (pemain[playerke+2].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke+2].posisibidak[nomorbidak-1].X) && (pemain[playerke+2].posisibidak[nomorbidak-1].X<56) && (pemain[playerke+2].posisibidak[nomorbidak-1].Y == 24)){	
							bool tidakbisa = true;
							while (tidakbisa){
								nomorbidak = rand()%4+1;
								if((pemain[playerke+2].posisibidak[nomorbidak-1].X-(dadu*7) < 70) && (70<pemain[playerke+2].posisibidak[nomorbidak-1].X) && (pemain[playerke+2].posisibidak[nomorbidak-1].X<=105) && (playerke==2) && (pemain[playerke+2].posisibidak[nomorbidak-1].Y == 24)){
								}else{
									tidakbisa = false;
								}
							}
						}
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke+2, nomorbidak-1, dadu);
						}
						GoToXY(120, 6); printf("Komputer 2 menggerakkan bidak nomor %d", nomorbidak);
						sleep(2);
					}	
				}else if(adabidakdilintasan && !semuabidakdibase && dadu<6){
					//code baru
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih bidak yang mau dijalankan");
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					if (jumlahbidakdilintasan>1){
						while((pemain[playerke+2].posisibidak[nomorbidak-1].X-(dadu*7) < 70) && (70<pemain[playerke+2].posisibidak[nomorbidak-1].X) && (pemain[playerke+2].posisibidak[nomorbidak-1].X<=105) && (playerke==2) && (pemain[playerke+2].posisibidak[nomorbidak-1].Y == 24)){
							nomorbidak = rand()%4+1;
						}
					}
					bool boleh = false;
					while  (!boleh){
						if (pemain[playerke+2].bidakdihomebase[nomorbidak-1] == false && pemain[playerke+2].bidakdifinish[nomorbidak-1] == false){
							boleh = true;
						}else{
							nomorbidak = rand()%4+1;
						}
					}
						if((pemain[playerke+2].posisibidak[nomorbidak-1].X-(dadu*7) < 70) && (70<pemain[playerke+2].posisibidak[nomorbidak-1].X) && (pemain[playerke+2].posisibidak[nomorbidak-1].X<=105) && (playerke==2) && (pemain[playerke+2].posisibidak[nomorbidak-1].Y == 24)){
						}else if (pemain[playerke+2].bidakdihomebase[nomorbidak-1] == false ){
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke+2, nomorbidak-1, dadu);
							GoToXY(120, 6); printf("Komputer 2 menggerakkan bidak nomor %d", nomorbidak);
							sleep(2);
						}
					}
				}
				PembunuhBidak(playerke+2, nomorbidak-1);
				//Enddddddddddddddddddddddddddddddddddddddd
			}else if (pemain[playerke+3].giliran == giliran){
				//Beginnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
				for (m=0; m<4; m++){
					if (pemain[playerke+3].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke+3].bidakdihomebase[m] == false && pemain[playerke+3].bidakdifinish[m] == false){
						adabidakdilintasan = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke+3].bidakdihomebase[m] == false && pemain[playerke+3].bidakdifinish[m] == false){
						jumlahbidakdilintasan++;
					}
				}
				GoToXY(120, 4); printf("Komputer 3 mengocok dadu...             ");
				int TampilDadu01, waktudadu;
				for(TampilDadu01=0; TampilDadu01<=dadu;TampilDadu01++){
					RandomDadu(TampilDadu01);
				for(waktudadu=0; waktudadu<=90000000; waktudadu++){
			 		}
				}
				GoToXY(120, 4); printf("Komputer 3 mendapat angka dadu %d.......", dadu);
				if(!adabidakdilintasan && (semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Komputer 3 tidak bisa mengeluarkan bidak...\n");
					sleep(2);
				}else if(!adabidakdilintasan && (!semuabidakdibase && dadu<6)){
					GoToXY(120, 5); printf("Maaf Komputer 3 tidak bisa mengeluarkan bidak...\n");
					sleep(2);
				}else if(!adabidakdilintasan && semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak yang mau dikeluarkan (1-4) ");
					PenentuWarna(7);
					sleep(2);
					nomorbidak = rand()%4+1;
					KeluarHomeBase(playerke+3, nomorbidak-1);
					GoToXY(120, 6); printf("Komputer 3 mengeluarkan bidak nomor %d", nomorbidak);
					sleep(2);
				}else if(!semuabidakdibase && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak (1-4) ");
					PenentuWarna(7);
					sleep(2);
					nomorbidak = rand()%4+1;
					if (pemain[playerke+3].bidakdihomebase[nomorbidak-1] == true ){
						KeluarHomeBase(playerke+3, nomorbidak-1);
						GoToXY(120, 6); printf("Komputer 3 mengeluarkan bidak nomor %d", nomorbidak);
						sleep(2);
					}else{
						if((pemain[playerke+3].posisibidak[nomorbidak-1].Y-(dadu*3) < 27) && (27<pemain[playerke+3].posisibidak[nomorbidak-1].Y) && (pemain[playerke+3].posisibidak[nomorbidak-1].Y<=42) && (playerke==3) && (pemain[playerke+3].posisibidak[nomorbidak-1].X == 63)){	
							bool tidakbisa = true;
							while (tidakbisa){
								nomorbidak = rand()%4+1;
								if((pemain[playerke+3].posisibidak[nomorbidak-1].Y-(dadu*3) < 27) && (27<pemain[playerke+3].posisibidak[nomorbidak-1].Y) && (pemain[playerke+3].posisibidak[nomorbidak-1].Y<=42) && (playerke==3) && (pemain[playerke+3].posisibidak[nomorbidak-1].X == 63)){
								}else{
									tidakbisa = false;
								}
							}
						}
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke+3, nomorbidak-1, dadu);
						}
						GoToXY(120, 6); printf("Komputer 3 menggerakkan bidak nomor %d", nomorbidak);
						sleep(2);
					}	
				}else if(adabidakdilintasan && !semuabidakdibase && dadu<6){
					//code baru
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih bidak yang mau dijalankan");
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					if (jumlahbidakdilintasan>1){
						while((pemain[playerke+3].posisibidak[nomorbidak-1].Y-(dadu*3) < 27) && (27<pemain[playerke+3].posisibidak[nomorbidak-1].Y) && (pemain[playerke+3].posisibidak[nomorbidak-1].Y<=42) && (playerke==3) && (pemain[playerke+3].posisibidak[nomorbidak-1].X == 63)){
							nomorbidak = rand()%4+1;
						}
					}
					bool boleh = false;
					while  (!boleh){
						if (pemain[playerke+3].bidakdihomebase[nomorbidak-1] == false && pemain[playerke+3].bidakdifinish[nomorbidak-1] == false){
							boleh = true;
						}else{
							nomorbidak = rand()%4+1;
						}
					}
						if((pemain[playerke+3].posisibidak[nomorbidak-1].Y-(dadu*3) < 27) && (27<pemain[playerke+3].posisibidak[nomorbidak-1].Y) && (pemain[playerke+3].posisibidak[nomorbidak-1].Y<=42) && (playerke==3) && (pemain[playerke+3].posisibidak[nomorbidak-1].X == 63)){
						}else if (pemain[playerke+3].bidakdihomebase[nomorbidak-1] == false ){
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke+3, nomorbidak-1, dadu);
							GoToXY(120, 6); printf("Komputer 1 menggerakkan bidak nomor %d", nomorbidak);
							sleep(2);
						}
					}
				}
				PembunuhBidak(playerke+3, nomorbidak-1);
				//Enddddddddddddddddddddddddddddddddddddddd
			}
			PenentuPemenang(&menang, &pemenang, giliran);//cek menang atau engga...
		}
	}
	GameOver(pemenang);
}
	
int main(){ // Author : Farra
	PlaySound(TEXT("D:\\documents\\TEKNIK INFORMATIKA\\DDP\\TUGAS BESAR GAME LUDO\\El-Yu-Di-Oh FIX\\soundtrack.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	Opening();
	MainMenu();
	StartGame();
	
}
