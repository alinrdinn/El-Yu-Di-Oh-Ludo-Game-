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

// Nama Modul : GoToXY
// Jenis Modul : Procedure
// Deskripsi : Modul untuk menentukan letak penempatan apapun yang di print atau di tampilkan di layar user.
// Author : https://www.daniweb.com/programming/software-development/threads/360984/need-help-understanding-gotoxy
GoToXY(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MainMenu();
int StartGame();


// Nama Modul : PilihBidak
// Jenis Modul : Procedure
// Deskripsi : Modul untuk mengeluarkan langkah selanjutnya setelah pemain mendapatkan angka dadu 6 yang kedua kalinya atau ketika pemain mendapatkan 6 angka dadu dan sudah ada bidak pemain di lintasan.
// Inisial State :  Pemain mendapat angka dadu dan bidak pemain masih berada di petak semula.
// Final State : Terpilih langkah selanjutnya, diantara pengeluaran bidak atau penggerakan bidak.
// Modul Pemanggil : Procedure_PlayerUser()
// Modul yang Dipanggil : Procedure_GoToXY()
// Author : Ali
void PilihBidak(int *nomorbidak){
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
		
// Nama Modul : GameOver
// Jenis Modul : Procedure
// Dekripsi : Modul untuk menampilkan tampilan "Selamat Kamu Menang" di layar user yang berarti bahwa gameover untuk pemain komputer.Atau jika semua bidak dari salah satu komputer lebih dulu masuk finish maka di layar akan tampil: "Kamu Kalah".
// Initial State : Layar Kosong
// Final State : Modul untuk menampilkan "Kamu Kalah" atau  "Selamat kamu menang" di layar user.
// Modul Pemanggil : Function_StartGame()
// Modul yang Dipanggil : Procedure_GoToXY(), Function_MainMenu(), Procedure_PenentuWarna()
// Author : Farra
void GameOver(int pemenang){
	system("cls");
	if (pemenang == 0){
		sleep(1);
		GoToXY(27, 4); printf("  ___ ___ _      _   __  __   _ _____   _  __   _   __  __ _   _   __  __ ___ _  _   _   _  _  ___ _ _ _ \n");
		GoToXY(27, 5); printf(" / __| __| |    /_\\ |  \\/  | /_\\_   _| | |/ /  /_\\ |  \\/  | | | | |  \\/  | __| \\| | /_\\ | \\| |/ __| | | |\n");
		GoToXY(27, 6); printf(" \\__ \\ _|| |__ / _ \\| |\\/| |/ _ \\| |   | ' <  / _ \\| |\\/| | |_| | | |\\/| | _|| .` |/ _ \\| .` | (_ |_|_|_|\n");
		GoToXY(27, 7); printf(" |___/___|____/_/ \\_\\_|  |_/_/ \\_\\_|   |_|\\_\\/_/ \\_\\_|  |_|\\___/  |_|  |_|___|_|\\_/_/ \\_\\_|\\_|\\___(_|_|_)\n");
	}else{
		GoToXY(27, 8); printf(" _  __   _   __  __ _   _   _  __   _   _      _   _  _");
		GoToXY(27, 9); printf("| |/ /  /_\\ |  \\/  | | | | | |/ /  /_\\ | |    /_\\ | || |");
		GoToXY(27, 10); printf("| ' <  / _ \\| |\\/| | |_| | | ' <  / _ \\| |__ / _ \\| __ |");
		GoToXY(27, 11); printf("|_|\\_\\/_/ \\_\\_|  |_|\\___/  |_|\\_\\/_/ \\_\\____/_/ \\_\\_||_|");
}
	getch();
	MainMenu();
}

// Nama Modul : PembunuhBidak
// Jenis Modul : Procedure
// Deskripsi : Modul dieksekusi pada saat bidak pemain yang mendapat giliran bermain menempati petak yang sudah ditempati bidak lawan. (bidak lawan akan dikembalikan ke home base-nya).
// Inisial State : Bidak pemain yang sedang mendapat giliran bermain menempati petak yang sudah terisi oleh bidak lawan.
// Final State : Bidak lawan kembali ke homebase nya
// Modul Pemanggil : Procedure_PlayerUser(), Procedure_PlayerKomputer1(), Procedure_PlayerKomputer2(), & Procedure_PlayerKomputer3
// Modul yang Dipanggil : -
// Author : Ali
void PembunuhBidak(int playerke, int nomorbidak){
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
	
// Nama Modul : PenentuPemenang	
// Jenis Modul : Procedure
// Deskripsi : 	Ketika ada pemain yang semua bidaknya sudah menempati petak finish maka permainan selesai.
// Initial State : Belum ada pemain yang menjadi pemenang.
// Final State : Tampilan "Selamat kamu menang" atau "Game Over".
// Modul Pemanggil : Function_StartGame()
// Modul yang Dipanggil -
// Author : Ali
void PenentuPemenang(bool *menang, int *pemenang, int playerke){
	int i;		
	for (i=0; i<4; i++){
		if (pemain[playerke].bidakdifinish[i] == false){
			*menang = false;
			return;
		}else {
			*menang = true;
			*pemenang =  playerke;
		}
	}		
}

// Nama Modul : PenggerakBidak
// Jenis Modul : Procedure
// Deskripsi : Modul untuk menggerakan bidak pemain.
// Initial State : Bidak berada dalam petak.
// Final State : Bidak berpindah petak.
// Modul Pemanggil : Procedure_PlayerUser(), Procedure_PlayerKomputer1(), Procedure_PlayerKomputer2(), & Procedure_PlayerKomputer3
// Modul yang Dipanggil : -
// Author : Ali
void PenggerakBidak(int playerke, int nomorbidak, int dadu){
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

// Nama Modul : KeluarHomeBase
// Jenis Modul : Procedure
// Deskripsi : Modul untuk mengeluarkan bidak pemain dari home base.
// Initial State : Bidak berada dalam sebuah petak di homebase
// Final State : Bidak pemain berada di lintasan pada papan permainan
// Modoul Pemanggil : Procedure_PlayerUser(), Procedure_PlayerKomputer1(), Procedure_PlayerKomputer2(), & Procedure_PlayerKomputer3
// Modul yang Dipanggil : -
// Author : Farra & Ali
void KeluarHomeBase(int playerke, int nomorbidak){
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

// Nama Modul : PenentuWarna
// Jenis Modul : Procedure
// Dekripsi :Modul untuk menentukan warna yang akan ditampilkan pada layar
// Modul Pemanggil : Procedure_TampilPapanPermainan(), Procedure_Opening(), Procedure_RandomDadu()
// Author : Laras & Nauval
void PenentuWarna(unsigned short color){ // Author : Farra & Ali
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hCon,color);
}

// Nama Modul : RandomDadu
// Jenis Modul : Procedure
// Deskripsi : Modul untuk mengeluarkan jumlah angka dadu yang ditentukan secara random dan akan dipakai untuk menggerakkan bidak.
// Initial State : Belum ada tampilan angka dadu yang di dapat oleh pemain yang mendapat giliran.
// Final State : Tampilnya jumlah angka mata dadu yang didapat oleh pemain yang mendapat giliran. 
// Modul Pemanggil : Procedure_PlayerUser(), Procedure_PlayerKomputer1(), Procedure_PlayerKomputer2(), & Procedure_PlayerKomputer3
// Modul yang Dipanggil : Procedure_PenentuWarna(), Procedure_GoToXY()
// Author : Farra
void RandomDadu(int angkadadu){
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

// Nama Modul : PenentuUrutan
// Jenis Modul : Function
// Deskripsi : Modul untuk menentukan urutan para pemain untuk bermain secara random.
// Input : Jumlah Pemain
// Output : Tampilan urutan pemain yang telah ditentukan secara random sesuai dengan jumlah pemain.
// Modul Pemanggil : Function_StartGame()
// Modul yang Dipanggil : -
// Author : Ali
int * PenentuUrutan(int urutanpemain[], int jumlahpemain){
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

// Nama Modul : Opening
// Jenis Modul : Procedure
// Deskripsi : Modul untuk menampilkan berupa sambutan selamat datang dan informasi mengenai kreator kepada user pada layar
// Initial State : Layar Kosong
// Final State : Menampilkan tampilan pembuka sebagai sambutan selamat datang pada user dan informasi mengenai kreator pada layar
// Modul Pemanggil : Function_Main()
// Modul yang Dipanggil : Procedure_GoToXY(), Procedure_PenentuWarna()
// Author : Farra
void Opening(){
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

// Nama Modul : Instruction
// Jenis Modul : Procedure
// Deskripsi : Modul untuk menampilkan aturan bermain.
// Initial State : Layar Kosong
// Final State : Tampil nya instruksi/aturan bermain.
// Modul Pemanggil : Procedure_MainMenu()
// Modul yang Dipanggil : Procedure_PenentuWarna(), Procedure_GoToXY, Function_StartGame
// Author : Farra
void Instruction(){
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

// Nama Modul : TampilPapanPermainan
// Jenis Modul : Procedure
// Deskripsi : Modul untuk menampilkan papan permainan.
// Initial State : Layar Kosong 
// Final State : Tampilnya papan permainan
// Modul Pemanggil : Function_StartGame()
// Modul yang Dipanggil : Procedure_PenentuWarna(), Procedure_GoToXY()
// Author : Farra & Ali
void TampilPapanPermainan(){
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

// Nama Modul : MainMenu
// Jenis Modul : Function
// Deskripsi : Program awal yang akan menampilkan pilihan untuk Start Game, Instruction, dan Exit.User menginput huruf S untuk pilihan Start Game(akan memanggil modul jumlahpemain), huruf I untuk pilihan Instruction(akan memanggil modul instruction), dan huruf E untuk exit(akan memanggil modul exit).
// Input : User menekan tombol enter
// Output : Tampilnya pilihan "Start Game", "Instruction", dan "Exit"
// Modul Pemanggil : Function_Main()
// Modul yang Dipanggil : Function_StartGame(), Prosedur_Instruction(), Function_Exit(), Procedure_PenentuWara(), & Procedure_GoToXY
// Author : Farra
MainMenu(){
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

// Nama Modul : Jumlah Pemain
// Jenis Modul : Function
// Deskripsi : Modul yang berperan sebagai program utama yang akan menampilkan pilihan untuk bermain dengan berapa pemain (1, 2, atau 3 komputer).
// Input : Layar Kosong
// Output : Tampilnya pilihan jumlah pemain komputer untuk lawan dari user, yaitu 1 pemain, 2 pemain, dan 3 pemain.
// Modul Pemanggil : Function_StartGame()
// Modul yang dipanggil : -
// Author : Farra
int JumlahPemain(){
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

// Nama Modul : Initial
// Jenis Modul :Procedure
// Deskripsi : Modul untuk menentukan perbedaan pemain (digunakan untuk membedakan bidak dan home base setiap pemain).
// Initial State : Pemain belum mendapatkan warna
// Final State :  Tampilan warna untuk masing-masing pemain.
// Modul Pemanggil : Function_StartGame()
// Modul yang Dipanggil : -
// Author : Ali
void initial(int jumlahpemain){
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

// Nama Modul : PrintBidak
// Jenis Modul : Procedure
// Deskripsi : Modul untuk menampilkan bidak pada papan permainan.
// Initial state : Bidak belum ditampilkan pada papan permainan.
// Final State : Bidak sudah ditampilkan pada papan permainan.
// Modul Pemanggil : Procedure_StartGame()
// Modul yang Dipanggil : Function_JumlahPemain(), Procedure_GoToXY & Function_PenentuWarna()
// Author : Farra & Ali
void printbidak(int jumlahpemain){
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

// Nama Modul : PlayerUser
// Jenis Modul : Procedure
// Deskripsi : Modul untuk mengoprasikan bidak user 
// Initial state : Bidak masih beradaa dalam kondisi awal baik di home base maupun di lintasan
// Final State : Bidak sudah berpindah posisi
// Modul Pemanggil : Prosedur_StartGame()
// Modul yang Dipanggil : Procedure_PenggerakBidak(), Procedure_KeluarHomeBase(), Procedure_PembunuhBidak(), Procedure_PilihBidak(), Procedure_RandomDadu(), Procedure_GoToXY(), Procedure_PenentuWarna(), & Function_PenentuWarna()
// Author : Farra & Ali
void playeruser(int playerke){
	int n, m, nomorbidak, dadu = rand()%6 + 1;
				bool semuabidakdibase = true, sudahmilih = false , adabidakdilintasan = false, adabidakdibase = false;
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == true){
						adabidakdibase = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if((!(pemain[playerke].bidakdihomebase[m]) && !(pemain[playerke].bidakdifinish[m])) && !((pemain[playerke].posisibidak[m].X+(dadu*7) > 56) && (21<= pemain[playerke].posisibidak[m].X) && (pemain[playerke].posisibidak[m].X<56) && (pemain[playerke].posisibidak[m].Y == 24)) ){
						adabidakdilintasan = true;
						break;
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
				if(!adabidakdilintasan && dadu<6){
					GoToXY(120, 5); printf("Kamu tidak bisa mengeluarkan/menjalankan bidak\n");
					GoToXY(120, 6); system("pause");
				}else if (!adabidakdilintasan && !adabidakdibase && dadu<=6){
					GoToXY(120, 5); printf("Komputer 1 tidak bisa menjalankan bidak\n");
					sleep(2);
				}else if(!adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak yang mau dikeluarkan (1-4) (error2)");
					PenentuWarna(7);
					PilihBidak(&nomorbidak);
					bool tidakboleh0102 = true;
					while(tidakboleh0102){
						if(pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
							tidakboleh0102 = false;
						}else{
							PenentuWarna(4);
							GoToXY(120, 5); printf("Pilih bidak lain...             ");
							PenentuWarna(7);
							PilihBidak(&nomorbidak);
						}
					}
					KeluarHomeBase(playerke, nomorbidak-1);
				}else if(adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih angka bidak (1-4) ");
					PenentuWarna(7);
					PilihBidak(&nomorbidak);
					
					if (pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
						KeluarHomeBase(playerke, nomorbidak-1);
					}else{
						if((pemain[playerke].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<56) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24)){	
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
				}else if(adabidakdilintasan && dadu<6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Pilih bidak yang mau dijalankan ");
					PenentuWarna(7);
					PilihBidak(&nomorbidak);
					
					bool boleh = false;
					
					while(!boleh){
						if ((pemain[playerke].bidakdihomebase[nomorbidak-1] == true || pemain[playerke].bidakdifinish[nomorbidak-1] == true) || ((pemain[playerke].posisibidak[nomorbidak-1].X+(dadu*7) > 56) && (21<= pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<56) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24))){
							PenentuWarna(4);
							GoToXY(120, 5); printf("Pilih bidak lain...             ");
							PenentuWarna(7);
							PilihBidak(&nomorbidak);
						}else{
							boleh = true;
						}
					}
					for(n=0; n<dadu;n++){
						PenggerakBidak(playerke, nomorbidak-1, dadu);
					}
				}
				PembunuhBidak(playerke, nomorbidak-1);
}

// Nama Modul : PlayerKomputer1
// Jenis Modul : Procedure
// Deskripsi : Modul untuk mengoprasikan bidak komputer1 
// Initial state : Bidak masih berada dalam kondisi awal baik di home base maupun di lintasan
// Final State : Bidak sudah berpindah posisi
// Modul Pemanggil : Prosedur_StartGame()
// Modul yang Dipanggil : Procedure_PenggerakBidak(), Procedure_KeluarHomeBase(), Procedure_PembunuhBidak(), Procedure_RandomDadu(), Procedure_GoToXY(), Procedure_PenentuWarna(), & Function_PenentuWarna()
// Author : Farra & Ali
void playerkomputer1(int playerke){
	int n, m, nomorbidak, dadu = rand()%6 + 1;
				bool semuabidakdibase = true, sudahmilih = false , adabidakdilintasan = false, adabidakdibase = false;
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == true){
						adabidakdibase = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if((!(pemain[playerke].bidakdihomebase[m]) && !(pemain[playerke].bidakdifinish[m])) && !((pemain[playerke].posisibidak[m].Y+(dadu*3) > 21) && (6<=pemain[playerke].posisibidak[m].Y) && (pemain[playerke].posisibidak[m].Y<21) && (playerke==1) && (pemain[playerke].posisibidak[m].X == 63)) ){
						adabidakdilintasan = true;
						break;
					}
				}
				PenentuWarna(4);
				GoToXY(120, 4); printf("Komputer mengocok dadu...");
				sleep(2);
				PenentuWarna(7);
				int TampilDadu01, waktudadu;
				for(TampilDadu01=0; TampilDadu01<=dadu;TampilDadu01++){
					RandomDadu(TampilDadu01);
				for(waktudadu=0; waktudadu<=90000000; waktudadu++){
			 		}
				}
				GoToXY(120, 4); printf("Komputer 1 mendapat angka dadu %d         ", dadu);
				sleep(2);
				if(!adabidakdilintasan && dadu<6){
					GoToXY(120, 5); printf("Komputer 1 tidak bisa menjalankan bidak\n");
					sleep(2);
				}else if (!adabidakdilintasan && !adabidakdibase && dadu<=6){
					GoToXY(120, 5); printf("Komputer 1 tidak bisa menjalankan bidak\n");
					sleep(2);
				}else if(!adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 1 memilih bidak (1-4)");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					
					bool tidakboleh0102 = true;
					while(tidakboleh0102){
						if(pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
							tidakboleh0102 = false;
						}else{
							nomorbidak = rand()%4+1;
						}
					}
					GoToXY(120, 5); printf("Komputer 1 memilih bidak (1-4) %d", nomorbidak);
					sleep(2);
					KeluarHomeBase(playerke, nomorbidak-1);
				}else if(adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 1 memilih angka bidak (1-4) ");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					if (pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
						KeluarHomeBase(playerke, nomorbidak-1);
					}else{
						if(((pemain[playerke].posisibidak[nomorbidak-1].Y+(dadu*3) > 21) && (6<=pemain[playerke].posisibidak[nomorbidak-1].Y) && (pemain[playerke].posisibidak[nomorbidak-1].Y<21) && (playerke==1) && (pemain[playerke].posisibidak[nomorbidak-1].X == 63))){	
							bool tidakbisa = true;
							while (tidakbisa){
								nomorbidak = rand()%4+1;
								if(((pemain[playerke].posisibidak[nomorbidak-1].Y+(dadu*3) > 21) && (6<=pemain[playerke].posisibidak[nomorbidak-1].Y) && (pemain[playerke].posisibidak[nomorbidak-1].Y<21) && (playerke==1) && (pemain[playerke].posisibidak[nomorbidak-1].X == 63))){
								}else{
									tidakbisa = false;
								}
							}
						}
						GoToXY(120, 5); printf("Komputer 1 memilih bidak (1-4) %d", nomorbidak);
						sleep(2);
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke, nomorbidak-1, dadu);
						}
					}	
				}else if(adabidakdilintasan && dadu<6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 1 memilih angka bidak (1-4)");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					
					bool boleh = false;
					
					while(!boleh){
						if ((pemain[playerke].bidakdihomebase[nomorbidak-1] == true || pemain[playerke].bidakdifinish[nomorbidak-1] == true) || ((pemain[playerke].posisibidak[nomorbidak-1].Y+(dadu*3) > 21) && (6<=pemain[playerke].posisibidak[nomorbidak-1].Y) && (pemain[playerke].posisibidak[nomorbidak-1].Y<21) && (playerke==1) && (pemain[playerke].posisibidak[nomorbidak-1].X == 63))){
							nomorbidak = rand()%4+1;
						}else{
							boleh = true;
						}
					}
					GoToXY(120, 5); printf("Komputer 1 memilih bidak (1-4) %d", nomorbidak);
					sleep(2);
					for(n=0; n<dadu;n++){
						PenggerakBidak(playerke, nomorbidak-1, dadu);
					}
				}
				PembunuhBidak(playerke, nomorbidak-1);
}

// Nama Modul : PlayerKomputer2
// Jenis Modul : Procedure
// Deskripsi : Modul untuk mengoprasikan bidak komputer2
// Initial state : Bidak masih berada dalam kondisi awal baik di home base maupun di lintasan
// Final State : Bidak sudah berpindah posisi
// Modul Pemanggil : Prosedur_StartGame()
// Modul yang Dipanggil : Procedure_PenggerakBidak(), Procedure_KeluarHomeBase(), Procedure_PembunuhBidak(), Procedure_PilihBidak(), Procedure_RandomDadu(), Procedure_GoToXY(), Procedure_PenentuWarna(), & Function_PenentuWarna()
// Author : Farra & Ali
void playerkomputer2(int playerke){
	int n, m, nomorbidak, dadu = rand()%6 + 1;
				bool semuabidakdibase = true, sudahmilih = false , adabidakdilintasan = false, adabidakdibase = false;
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == true){
						adabidakdibase = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if((!(pemain[playerke].bidakdihomebase[m]) && !(pemain[playerke].bidakdifinish[m])) && !((pemain[playerke].posisibidak[m].X-(dadu*7) < 70) && (70<pemain[playerke].posisibidak[m].X) && (pemain[playerke].posisibidak[m].X<=105) && (playerke==2) && (pemain[playerke].posisibidak[m].Y == 24)) ){
						adabidakdilintasan = true;
						break;
					}
				}
				PenentuWarna(4);
				GoToXY(120, 4); printf("Komputer 2 mengocok dadu...");
				sleep(2);
				PenentuWarna(7);
				int TampilDadu01, waktudadu;
				for(TampilDadu01=0; TampilDadu01<=dadu;TampilDadu01++){
					RandomDadu(TampilDadu01);
				for(waktudadu=0; waktudadu<=90000000; waktudadu++){
			 		}
				}
				GoToXY(120, 4); printf("Komputer 2 mendapat angka dadu %d         ", dadu);
				sleep(2);
				if(!adabidakdilintasan && dadu<6){
					GoToXY(120, 5); printf("Komputer 2 tidak bisa menjalankan bidak\n");
					sleep(2);
				}else if (!adabidakdilintasan && !adabidakdibase && dadu<=6){
					GoToXY(120, 5); printf("Komputer 2 tidak bisa menjalankan bidak\n");
					sleep(2);
				}else if(!adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 2 memilih bidak (1-4)");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					
					bool tidakboleh0102 = true;
					while(tidakboleh0102){
						if(pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
							tidakboleh0102 = false;
						}else{
							nomorbidak = rand()%4+1;
						}
					}
					GoToXY(120, 5); printf("Komputer 2 memilih bidak (1-4) %d ", nomorbidak);
					sleep(2);
					KeluarHomeBase(playerke, nomorbidak-1);
				}else if(adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 2 memilih bidak (1-4) ");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					if (pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
						KeluarHomeBase(playerke, nomorbidak-1);
					}else{
						if(((pemain[playerke].posisibidak[nomorbidak-1].X-(dadu*7) < 70) && (70<pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<=105) && (playerke==2) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24))){	
							bool tidakbisa = true;
							while (tidakbisa){
								nomorbidak = rand()%4+1;
								if(((pemain[playerke].posisibidak[nomorbidak-1].X-(dadu*7) < 70) && (70<pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<=105) && (playerke==2) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24))){
								}else{
									tidakbisa = false;
								}
							}
						}
						GoToXY(120, 5); printf("Komputer 2 memilih bidak (1-4) %d", nomorbidak);
						sleep(2);
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke, nomorbidak-1, dadu);
						}
					}	
				}else if(adabidakdilintasan && dadu<6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 2 memilih bidak (1-4)");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					
					bool boleh = false;
					
					while(!boleh){
						if ((pemain[playerke].bidakdihomebase[nomorbidak-1] == true || pemain[playerke].bidakdifinish[nomorbidak-1] == true) || ((pemain[playerke].posisibidak[nomorbidak-1].X-(dadu*7) < 70) && (70<pemain[playerke].posisibidak[nomorbidak-1].X) && (pemain[playerke].posisibidak[nomorbidak-1].X<=105) && (playerke==2) && (pemain[playerke].posisibidak[nomorbidak-1].Y == 24))){
							nomorbidak = rand()%4+1;
						}else{
							boleh = true;
						}
					}
					GoToXY(120, 5); printf("Komputer 2 bidak (1-4) %d", nomorbidak);
					sleep(2);
					for(n=0; n<dadu;n++){
						PenggerakBidak(playerke, nomorbidak-1, dadu);
					}
				}
				PembunuhBidak(playerke, nomorbidak-1);
}

// Nama Modul : PlayerKomputer3
// Jenis Modul : Procedure
// Deskripsi : Modul untuk mengoprasikan bidak komputer3
// Initial state : Bidak masih berada dalam kondisi awal baik di home base maupun di lintasan
// Final State : Bidak sudah berpindah posisi
// Modul Pemanggil : Prosedur_StartGame()
// Modul yang Dipanggil : Procedure_PenggerakBidak(), Procedure_KeluarHomeBase(), Procedure_PembunuhBidak(), Procedure_PilihBidak(), Procedure_RandomDadu(), Procedure_GoToXY(), Procedure_PenentuWarna(), & Function_PenentuWarna()
// Author : Farra & Ali
void playerkomputer3(int playerke){
	int n, m, nomorbidak, dadu = rand()%6 + 1;
				bool semuabidakdibase = true, sudahmilih = false , adabidakdilintasan = false, adabidakdibase = false;
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == false){
						semuabidakdibase = false;
						break;
					}
				}
				for (m=0; m<4; m++){
					if (pemain[playerke].bidakdihomebase[m] == true){
						adabidakdibase = true;
						break;
					}
				}
				for (m=0; m<4; m++){
					if((!(pemain[playerke].bidakdihomebase[m]) && !(pemain[playerke].bidakdifinish[m])) && !((pemain[playerke].posisibidak[m].Y-(dadu*3) < 27) && (27<pemain[playerke].posisibidak[m].Y) && (pemain[playerke].posisibidak[m].Y<=42) && (playerke==3) && (pemain[playerke].posisibidak[m].X == 63)) ){
						adabidakdilintasan = true;
						break;
					}
				}
				PenentuWarna(4);
				GoToXY(120, 4); printf("Komputer 3 mengocok dadu...");
				sleep(2);
				PenentuWarna(7);
				int TampilDadu01, waktudadu;
				for(TampilDadu01=0; TampilDadu01<=dadu;TampilDadu01++){
					RandomDadu(TampilDadu01);
				for(waktudadu=0; waktudadu<=90000000; waktudadu++){
			 		}
				}
				GoToXY(120, 4); printf("Komputer 3 mendapat angka dadu %d         ", dadu);
				sleep(2);
				if(!adabidakdilintasan && dadu<6){
					GoToXY(120, 5); printf("Komputer 3 tidak bisa menjalankan bidak\n");
					sleep(2);
				}else if (!adabidakdilintasan && !adabidakdibase && dadu<=6){
					GoToXY(120, 5); printf("Komputer 3 tidak bisa menjalankan bidak\n");
					sleep(2);
				}else if(!adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 3 memilih bidak (1-4)");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					
					bool tidakboleh0102 = true;
					while(tidakboleh0102){
						if(pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
							tidakboleh0102 = false;
						}else{
							nomorbidak = rand()%4+1;
						}
					}
					GoToXY(120, 5); printf("Komputer 3 memilih bidak (1-4) %d ", nomorbidak);
					sleep(2);
					KeluarHomeBase(playerke, nomorbidak-1);
				}else if(adabidakdilintasan && dadu==6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 3 memilih bidak (1-4) ");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					if (pemain[playerke].bidakdihomebase[nomorbidak-1] == true){
						KeluarHomeBase(playerke, nomorbidak-1);
					}else{
						if(((pemain[playerke].posisibidak[nomorbidak-1].Y-(dadu*3) < 27) && (27<pemain[playerke].posisibidak[nomorbidak-1].Y) && (pemain[playerke].posisibidak[nomorbidak-1].Y<=42) && (playerke==3) && (pemain[playerke].posisibidak[nomorbidak-1].X == 63))){	
							bool tidakbisa = true;
							while (tidakbisa){
								nomorbidak = rand()%4+1;
								if(((pemain[playerke].posisibidak[nomorbidak-1].Y-(dadu*3) < 27) && (27<pemain[playerke].posisibidak[nomorbidak-1].Y) && (pemain[playerke].posisibidak[nomorbidak-1].Y<=42) && (playerke==3) && (pemain[playerke].posisibidak[nomorbidak-1].X == 63))){
								}else{
									tidakbisa = false;
								}
							}
						}
						GoToXY(120, 5); printf("Komputer 3 memilih bidak (1-4) %d", nomorbidak);
						sleep(2);
						for(n=0; n<dadu;n++){
							PenggerakBidak(playerke, nomorbidak-1, dadu);
						}
					}	
				}else if(adabidakdilintasan && dadu<6){
					PenentuWarna(4);
					GoToXY(120, 5); printf("Komputer 3 memilih bidak (1-4)");
					sleep(2);
					PenentuWarna(7);
					nomorbidak = rand()%4+1;
					
					bool boleh = false;
					
					while(!boleh){
						if ((pemain[playerke].bidakdihomebase[nomorbidak-1] == true || pemain[playerke].bidakdifinish[nomorbidak-1] == true) || ((pemain[playerke].posisibidak[nomorbidak-1].Y-(dadu*3) < 27) && (27<pemain[playerke].posisibidak[nomorbidak-1].Y) && (pemain[playerke].posisibidak[nomorbidak-1].Y<=42) && (playerke==3) && (pemain[playerke].posisibidak[nomorbidak-1].X == 63))){
							nomorbidak = rand()%4+1;
						}else{
							boleh = true;
						}
					}
					GoToXY(120, 5); printf("Komputer 3 bidak (1-4) %d", nomorbidak);
					sleep(2);
					for(n=0; n<dadu;n++){
						PenggerakBidak(playerke, nomorbidak-1, dadu);
					}
				}
				PembunuhBidak(playerke, nomorbidak-1);
}



// Nama Modul : Start Game
// Jenis Modul : Function
// Deskripsi : Modul utama (sebagai wadah untuk bermain) dalam permainan Ludo. Modul ini akan memanggil beberapa modul yang berperan dalam permainan.
// Input : Kondisi layar masih di Main Menu
// Output : Modul Prosedur_JumlahPemain() terpanggil
// Modul Pemanggil : Function_MainMenu()
// Modul yang Dipanggil : Function_JumlahPemain(), Procedure_Initial(), Function_PenentuUrutan(), Procedure_TampilPapanPermainan(), Procedure_PenentuPemenang, Procedure_GameOver, Procedure_PlayerUser, Procedure_PlayerKomputer1, Procedure_PlayerKomputer2, Procedure_PlayerKomputer3, Procedure_GameOver & Procedure_PrintBidak()
// Author : Farra & Ali
StartGame(){
	int jumlahpemain, i;
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
		int giliran/*, m*/;
		for (giliran=1; giliran<=jumlahpemain+1; giliran++){
			TampilPapanPermainan();
			printbidak(jumlahpemain+1);
			if (pemain[playerke].giliran == giliran){
				playeruser(0);
				PenentuPemenang(&menang, &pemenang, 0);
			}else if (pemain[playerke+1].giliran == giliran){
				playerkomputer1(1);
				PenentuPemenang(&menang, &pemenang, 1);
			}else if (pemain[playerke+2].giliran == giliran){
				playerkomputer2(2);
				PenentuPemenang(&menang, &pemenang, 2);
			}else if (pemain[playerke+3].giliran == giliran){
				playerkomputer3(3);
				PenentuPemenang(&menang, &pemenang, 3);
			}
		}
	}
	GameOver(pemenang);
}

// Nama Modul : Main
// Jenis Modul : Function
// Deskripsi : Modul yang berfungsi sebagai wadah atau tempat dari modul lainnya.
// Input : -
// Output : -
// Modul Pemanggil : -
// Modul yang Dipanggil : Procedure_Opening() & Function_MainMenu()
// Author : Farra
int main(){
	Opening();
	MainMenu();
	
}
