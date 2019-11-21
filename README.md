# project01
Membuat sebuah game ludo dengan nama Le-Yu-Di-Oh!.
El-Yu-Di-Oh Skenario
Game ini dimainkan oleh satu user dan akan melawan komputer. User dapat memilih banyaknya komputer yang akan bermain (1-3 komputer). User mendapat empat bidak berikut home base nya. User mendapatkan 1 warna acak yang akan digunakannya selama permainan.  Ketika permainan berlangsung, bidak dipindahkan searah jarum jam mengikuti lintasan permainan yang terdapat di papan. Dalam permainan ini aturan diterangkan sebagai berikut:
1. User mendapat warna bidak dan home base yang akan dimainkan.
2. User melempar dadu.
3.  User harus mendapatkan jumlah enam angka dadu dari hasil pelemparan untuk mengeluarkan bidak. User memilih bidak mana yang dikeluarkan sesuai dengan nomor bidak. Jika tidak mendapat jumlah enam angka dadu, user tidak dapat mengeluarkan bidaknya.
4. Bidak yang dipilih oleh user, akan berpindah petak dimulai dari petak setelah  base sesuai dengan jumlah angka dadu yang didapat. Kemudian dilanjutkan dengan komputer1, komputer2, atau komputer3 (sesuai jumlah lawan yang user pilih).
5. Jika user mendapatkan enam angka dadu lagi, maka user tersebut dapat memilih untuk mengeluarkan bidak yang ada di home base (dengan memasukkan input ((A, n) kemudian tekan enter) dimana n adalah nomor bidak yang mau dikeluarkan) atau memindahkan bidak yang berada di lintasan (dengan memasukkan input F kemudian tekan enter). Dilanjutkan: 
    - Jika baru ada 1 bidak user yang berada di lintasan, maka apabila user menekan tombol F, bidak user akan berpindah secara otomatis.
    - Jika bidak user yang berada di lintasan berjumlah >1, maka apabila user menekan tombol F, user akan memilih bidak mana yang harus dipindahkan dengan menekan tombol 1 atau 2 atau 3 atau 4 sesuai bidak yang ada di lintasan.
6. Ketika user sudah mengeluarkan lebih dari 1 bidak, dan user telah melempar dadu. User dapat memilih bidak mana yang harus berpindah petak.
7. Saat angka enam pada dadu muncul secara 3x berturut-turut maka bidak yang berada paling dekat dengan base akan kembali ke home base.
8. Jika bidak berhenti di petak yang telah terisi oleh bidak lawan, maka bidak lawan diinyatakan “mati” dan haruas kembali ke home base milik lawan.
9. Jika user berhenti pada petak yang telah diisi dengan bidak milik sendiri lainnya, bidak tersebut kemudian akan menempati petak yang sama tanpa harus ada salah satu bidak yang kembali ke home base.
10. Jika bidak sudah hampir melewati satu putaran sesuai lintasan dengan selisih 1 petak, maka bidak akan berbelok dan akan mengikuti lintasan yang sesuai dengan warna bidak dan home base nya.
11. Ketika bidak sudah berada di petak menuju finish, bidak tidak akan berpindah petak jika jumlah angka dadu yang dilempar lebih besar dari jumlah sisa  petak menuju finish.
Contoh: bidak hanya perlu tiga langkah lagi menuju finish, tetapi jumlah yang dihasilkan adalah empat dadu, maka bidak akan diam di petak yang sedang dipijak. Dan seterusnya sampai bidak selesai.
Spesifikasi Input:
1. User menekan spasi untuk melempar dadu.
2. Jika user mendapat jumlah angka dadu 6, user memilih bidak yang akan dikeluarkan dari home base dengan menekan tombol angka pada keyboard (“n” untuk posisi bidak n dimana n adalah angka 1-4).
3. Jika bidak user yang berada di lintasan lebih dari 1 bidak, user menginput bidak mana yang akan digerakkan.
4. Jika user mendapat jumlah angka dadu 6 dan terdapat bidak yang berada di lintasan user memilih apakah mengeluarkan bidak atau memindahkan bidak (input F untuk mengeluarkan bidak dan A untuk memindahkan bidak).
Spesifikasi Output:
1. Jika semua bidak dari salah satu komputer lebih dulu masuk finish maka di layar akan tampil: “Maaf kamu kalah:(“.
2. Jika semua bidak dari user lebih dulu masuk finish maka di layar akan tampil: “Selamat kamu menang☺”.
