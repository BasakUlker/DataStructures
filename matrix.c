#include<stdio.h>
#include<stdlib.h>

void dinamik_matris_olustur(int ***dizi, int satir, int sutun){
    int i,j;
    *dizi=(int**)malloc(satir*sizeof(int*));
    for(i=0; i<satir; i++){
        *(*dizi+i)= (int*)malloc(sutun*sizeof(int));
        for(j=0; j<sutun; j++)
            *(*(*dizi+i)+j)= rand()%100;
    }
}
void matris_geri_ver(int ***matris, int satir){
    
		int i;
		for(i=0;i<satir;i++){
			free(*(*matris+i));
			
			
		}
		free(matris);
}
void matris_bastir(int ***matris, int satir, int sutun){

	int i,j;
	for(i=0;i<satir;i++){
		for(j=0;j<sutun;j++){
			printf("%d ", *(*(*matris+i)+j));
		}
		printf("\n");
	}
}
int main(int argc, char** argv) {
	int **A;
	dinamik_matris_olustur(&A, 10, 15);
	matris_bastir(&A, 10, 15);

	matris_geri_ver(&A, 10);

	matris_bastir(&A, 10, 15);
	return 0;
}
