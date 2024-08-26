#include <stdio.h>
#include <stdlib.h>
#define max 100

// Jessica Amadea Rahma / C / 200710789 //
typedef struct{
	int uts, uas;
}NilaiType;

typedef struct{
	NilaiType nilaitype;
	int npm;
}Mahasiswa;

typedef Mahasiswa Kelas[max];

void InitKelas(Kelas kelas){
	int a;
	for(a=0;a<max;a++){
		kelas[a].npm=0;
    }
}

void SetNilai(int uts, int uas, NilaiType *temp_nt)
{
	(*temp_nt).uts=uts;
	(*temp_nt).uas=uas;
}
     
void SetMahasiswa(int npm, NilaiType *temp_nt, Mahasiswa *temp_mhs)
{
    (*temp_mhs).npm=npm;
    (*temp_mhs).nilaitype=(*temp_nt);
}

void InsertMhs(Kelas kelas, int npm, int uts, int uas)
{
	int i;
	NilaiType temp_nt;
	Mahasiswa temp_mhs;
	
	i=NbMhs(kelas);
	SetNilai(uts, uas, &temp_nt);
	SetMahasiswa(npm, &temp_nt, &temp_mhs);
	kelas[i]=temp_mhs;
}

void tampilData(Kelas kelas, int i)
{	
	printf("\n NPM : %d", kelas[i].npm);
	printf("\n\t Nilai UTS : %d", kelas[i].nilaitype.uts);
	printf("\n\t Nilai UTS : %d", kelas[i].nilaitype.uas);
}

float reratanilai(Mahasiswa kelas)
{
	float rn;
	rn=(kelas.nilaitype.uts+kelas.nilaitype.uas);
	return (float) rn/2;
}

float reratakelas(Kelas kelas)
{
	int i,l;
	l = NbMhs(kelas);
	float RataRataMahasiswa, ttl=0;
	for(i=0;i<l;i++)
	{
	  RataRataMahasiswa=reratanilai(kelas[i]);
	  ttl+=RataRataMahasiswa;
	}
	return(float)ttl/NbMhs(kelas);
}
void RataNPMlebihdari50(Kelas kelas)
{
	int i,j=0,l;
	float rerata;
	l=NbMhs(kelas);
	printf("\n\tList NPM Mahasiswa dengan rata-rata di atas 50\n");
	for(i=0;i<l;i++)
	{
		rerata=reratanilai(kelas[i]);
		if(rerata>50.0)
		{
			printf("\n\t%d) NPM: %d",j+1,kelas[i].npm);
			j++;										
		}
	}
}

int dataindex(Kelas kelas, int goals)
{
	int i;
	for(i=0;i<max;i++)
	{
		if(kelas[i].npm==goals)
		return i;
	}
	return -1;
}

int isEmpty(Kelas kelas)
{
	int i;
	for(i=0;i<max;i++){
		if(kelas[i].npm!=0)
		return 0;
	}
	return 1;
}

int NbMhs(Kelas kelas)
{
  int i, x=0;
	for(i=0;i<max;i++)
	{
		if(kelas[i].npm!=0)
		{
			x++;
		}
	}
	return x;	
}

int main(int argc, char *argv[]) {
	Kelas kelas;
	int menu, done, index, goals, npm, uts, uas;
	
	do{
		system("cls");
		printf("\n[1] Init Data");
		printf("\n[2] Insert Mahasiswa");
		printf("\n[3] Rata-rata Nilai UTS dan UAS Mahasiswa");
		printf("\n[4] Tampil Nilai Mahasiswa rata-rata>50");
		printf("\n[5] Rata-rata kelas");
		printf("\n[0] Keluar");
		printf("\n>>> ");scanf("%d", &menu);
		switch(menu){
			case 1:
				InitKelas(kelas);
				printf("Berhasil Init Data");
				done=1;
				getch();
				break;
			case 2:
				if(done==1){
					 printf("\nMasukkan NPM: ");scanf("%d",&npm);
					 printf("\nMasukkan nilai UTS: ");scanf("%d",&uts);
					 printf("\nMasukkan nilai UAS: ");scanf("%d",&uas);
					 InsertMhs(kelas, npm, uts, uas);
					 printf("\nBerhasil Insert Data Mahasiswa");
				}else{
					printf("\nHarus init data terlebih dahulu");
				}
				getch();
				break;
			case 3:
				if(done==1){
					if(isEmpty(kelas)==0){
					do
				    {
					printf("\nMasukkan NPM mahasiswa: ");scanf("%d",&goals);
					index=dataindex(kelas,goals);
					if(index==-1)
						printf("\n\tNPM tidak ditemukan!");
				    }
				    while(index==-1);
				    	tampilData(kelas, index);
			        	printf("\nRata-rata nilai mahasiswa: %.2f",reratanilai(kelas[index])); 
					}else
					{
						printf("\n\t Kelas masih kosong");
					}	
			    }else{
					printf("\nInit data terlebih dahulu!");
				}
				getch();
				break;
			case 4:
				if(done==1){
					if(isEmpty(kelas)==0)
					{
					   RataNPMlebihdari50(kelas);
					}else{
						printf("Kelas masih kosong");
					}
				}else{
					printf("Init data terlebih dahulu!");
				}
				getch();
				break;
			case 5:
				if(done==1){
					if(isEmpty(kelas)==0){
					printf("\nRata-rata nilai kelas: %.2f", reratakelas(kelas));	
					}else{
						printf("Kelas masih kosong");
					}
				}else{
					printf("Init data terlebih dahulu");
				}
				getch();
				break;
			case 0:
				exit(0);
				printf("\nKeluar");
				getch();
				break;
			default:
				printf("Menu Tidak Tersedia");
				getch();
				break;
				
		}
		
	}while(menu!=0);

	return 0;
}



