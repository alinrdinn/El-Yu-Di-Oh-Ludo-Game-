# El-Yu-Di-Oh Ludo Game
1. Dekripsi Aplikasi:
Deskripsi aplikasi adalah uraian mengenai aplikasi secara utuh. Bagian ini juga akan menjelaskan detail elemen-elemen dari permainan El-Yu-Di-Oh dan cara kerja aplikasi nya..
a).	Pemain, permainan ini dimainkan oleh 2 jenis pemain, yaitu :
1.	User(manusia), permainan El-Yu-Di-Oh ini hanya bisa dimainkan oleh satu user/ pemain manusia yang akan melawan pemain komputer.
2.	Pemain Komputer, yaitu pemain yang berasal dan dimainkan oleh komputer. Permainan El-Yu-Di-Oh ini dapat dimainkan oleh 1-3 komputer sesuai dengan permintaan dari pemain manusia.
b).	Bidak, home base dan papan permainan.
-	Setiap pemain memiliki 4 bidak yang bisa dijalankan. Dan 1 home base sebagai tempat untuk bidak yang dimiliki nya.
-	User dan pemain dari pihak komputer masing-masing mendapat warna yang telah ditentukan secara random untuk empat bidak dan home base nya yang akan ditampilkan pada papan permainan.
-	Warna yang menjadi identitas masing-masing pemain tersebut digunakann selama permainan berlangsung.
-	Ketika permainan berlangsung, bidak dipindahkan searah jarum jam mengikuti lintasan permainan yang terdapat pada papan permainan .
-	Papan permainan El-Yu-Di-Oh terdiri dari 52 petak sebagai lintasan, 4 home base dan 4 lintasan menuju finish dengan warna berbeda, dan 4 petak finish.
1.1	Alur Permainan
Pada game El-Yu-Di-Oh ini, ketika program dibuka akan tampil pada layar berupa sambutan selamat datang di permainan dan informasi mengenai kreator.
Setelah itu, akan ada tampilan main menu yang di dalamnya terdapat beberapa pilihan yang dijelaskan di bawah ini :
●	Start Game, adalah menu untuk memulai permainan.
Untuk mulai bermain user harus menginputkan huruf S, kemudian setelah itu akan muncul pilihan berupa jumlah pemain yang akan bermain. Untuk memilih berapa pemain yang akan bermain, user harus menginputkan angka diantaranya :
-	Angka 1 untuk bermain dengan 2 pemain ( 1 user dan 1 komputer)
-	Angka 2 untuk bermain dengan 3 pemain ( 1 user dan 2 komputer)
-	Angka 3 untuk bermain dengan 4 pemain ( 1 user dan 3 komputer)
-	Huruf E untuk kembali ke menu utama
●	Instruction, adalah menu untuk menampilkan petunjuk atau cara memainkan El-Yu-Di-Oh Game.
Untuk mengetahui cara bermain, user harus menginputkan huruf I, kemudian di layar akan muncul penjelasan teks yang berisi aturan bermain.
●	Exit, adalah menu untuk keluar dari program El-Yu-Di-Oh Game.
Untuk keluar dari program El-Yu-Di-Oh, user harus menginputkan huruf E di tampilan Menu Utama
Jika user memilih Start Game, maka user dapat menentukan jumlah pemain komputer yang akan dijadikan lawan, setelah itu akan ditampilkan urutan bermain yang ditentukan secara random. Tahap selanjutnya adalah tampilnya papan permainan, yang menandakan permainan dimulai.
1.2	Aturan Permainan
Dalam permainan El-Yu-Di-Oh terdapat beberapa aturan untuk bermain selama game dimainkan. Aturan permainan yang digunakan adalah sebagai berikut:
1.	Ketika pemain sudah mendapat giliran bermain, pemain harus melempar dadu dan menggerakan bidak nya atau mengeluarkan bidak nya dari home base.
2.	Pemain harus mendapatkan jumlah enam angka dadu dari hasil pelemparan untuk mengeluarkan bidak dari home base.
3.	Pemain menentukan bidak mana yang akan dikeluarkan sesuai dengan nomor bidak yang tertera pada bidak miliknya. Jika tidak mendapat jumlah enam angka dadu, pemain tidak dapat mengeluarkan bidaknya.
4.	Bidak yang dipilih oleh pemain, akan berpindah petak dimulai dari petak setelah base sesuai dengan jumlah angka dadu yang didapat. Kemudian dilanjutkan dengan pemain lainnya.
5.	Ketika user sudah mengeluarkan lebih dari 1 bidak, dan user telah melempar dadu. User dapat memilih bidak mana yang harus berpindah petak.
7.	Jika bidak berhenti di petak yang telah terisi oleh bidak lawan, maka bidak lawan diinyatakan “mati” dan akan kembali ke home base milik lawan.
8.	Jika user berhenti pada petak yang telah diisi dengan bidak milik sendiri lainnya, bidak tersebut kemudian akan menempati petak yang sama tanpa harus ada salah satu bidak yang kembali ke home base.
9.	Jika bidak sudah hampir melewati satu putaran sesuai lintasan dengan selisih 1 petak, maka bidak akan berbelok dan akan mengikuti lintasan yang sesuai dengan warna bidak dan home base nya.
10.	Ketika bidak sudah berada di petak pada lintasan menuju finish, bidak tidak akan berpindah petak jika jumlah angka dadu yang dilempar lebih besar dari jumlah sisa petak menuju finish.
Contoh: bidak hanya perlu tiga langkah lagi menuju finish, tetapi jumlah yang dihasilkan adalah empat dadu, maka bidak akan diam di petak yang sedang dipijak. Dan seterusnya sampai bidak selesai.
1.3	Spesifikasi Input:
1.	Setelah tampilan opening pada layar, user menekan tombola pa saja untuk memasuki tahap selanjutnya, yaitu tampilan main menu.
2.	Pada main menu, user dapat menginputkan :
-	Huruf S jika memilih Start Game(untuk memulai permainan);
-	Huruf I jika memilih Instruction(untuk melihat aturan dan cara bermain);
-	Huruf E jika memilih Exit(untuk keluar dari permainan).
3.	Untuk memilih berapa pemain yang akan bermain, user harus menginputkan angka diantaranya :
-	Angka 1 untuk bermain dengan 2 pemain ( 1 user dan 1 komputer)
-	Angka 2 untuk bermain dengan 3 pemain ( 1 user dan 2 komputer)
-	Angka 3 untuk bermain dengan 4 pemain ( 1 user dan 3 komputer)
4.	User menekan enter untuk melempar dadu.
5.	Jika bidak user yang berada di lintasan lebih dari 1 bidak, user menginput bidak mana yang akan digerakkan.
1.4	Spesifikasi Output:
1.	Jika semua bidak dari salah satu komputer lebih dulu masuk finish maka di layar akan tampil: “Kamu Kalah“ .
2.	Jika semua bidak dari user lebih dulu masuk finish maka di layar akan tampil: “Selamat kamu menang“.
1.5	Fitur tambahan:
1. User dapat menjeda permainan dengan ketentuan sebagai berikut:
-	User dapat menjeda permainan tetapi program (permainan) tidak boleh ditutup.
-	Jika program ditutup, maka permainan harus diulang dari awal.
