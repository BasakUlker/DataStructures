#include<stdio.h>
#include<stdlib.h>

struct dugum{

	int anahtar;
	struct dugum *sag_link, *sol_link;
}

int tek_cocuklu_dugum_sayisi(struct dugum *kok){

	int c=0;
    

    	if (kok == NULL){
       		 return c;
    	}
 
    
    	if ((kok->sol_link != NULL && kok->sag_link == NULL) ||( 
        	kok->sol_link == NULL && kok->sag_link != NULL)){
        	c++;
    	}
     
    
    	c = c + tek_cocuklu_dugum_sayisi(kok->sol_link) + tek_cocuklu_dugum_sayisi(kok->sag_link);
    	return c;

}




int main(){

	struct dugum kok;

	return 0;
}
