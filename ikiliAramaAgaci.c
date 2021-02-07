#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> //random icin gerekli

//Agac sola yatıktır. Kok, yani uretilen ilk sayı, en bastaki sutundan itibaren dallanır.

#define BOSLUK 10 

struct Dugum //bagli liste yapisi
{ 
	int veri; 
	struct Dugum *sol;
    struct Dugum *sag; 
}; 

struct Dugum *yeniDugum(int item) 
{ 
	struct Dugum *temp = (struct Dugum *)malloc(sizeof(struct Dugum)); //yeni dugum icin bellekte Dugum boyutunda yer ayir
	temp->veri = item; 
	temp->sol = temp->sag = NULL; 
	return temp; 
} 

// struct Dugum *ara(struct Dugum *root, int veri) //agacta arama fonksiyonu
// { 
// 	if (root != NULL) 
// 	{ 
//         if (veri == root->veri)
//         {
//             return root;
//         }
// 		ara(root->sol,veri); 
// 		ara(root->sag,veri);
//         return NULL;
// 	} 
// } 

struct Dugum* ekle(struct Dugum* node, int veri) 
{ 
	if (node == NULL) return yeniDugum(veri); //agac bossa yeni bir dugum dondur, root.

	if (veri < node->veri) //bos degilse arama yap ve ona gore ekle. kucuksa sola
		node->sol = ekle(node->sol, veri); 
	else if (veri > node->veri) //buyukse saga
		node->sag = ekle(node->sag, veri); 

	return node; //koku dondur.
} 


void yazdirFonk(struct Dugum *root, int bosluk) 
{ 
    if (root == NULL) 
        return; 
  
    bosluk += BOSLUK; //agacigin dallari arasindaki boslugu artir

    yazdirFonk(root->sag, bosluk); //once sag cocuk
  
    printf("\n"); 
    for (int i = BOSLUK; i < bosluk; i++)  //bosluk birakip o anki veriyi yaz
        printf(" "); 
    printf("%d\n", root->veri); 
  
      yazdirFonk(root->sol, bosluk); //sonra sol cocuk
} 
  
void yazdir(struct Dugum *root) 
{  
   yazdirFonk(root, 0); 
} 

struct Dugum * minValueDugum(struct Dugum* Dugum) 
{ 
    //agactaki bir elemani silecegimiz zaman yerine gececek olan elemani bulalim.
    struct Dugum* current = Dugum; 
  
    /* loop down to find the solmost leaf */
    while (current && current->sol != NULL) 
        current = current->sol; 
  
    return current; 
} 
  
struct Dugum* sil(struct Dugum* root, int veri) 
{ 

    if (root == NULL) return root; 
    
    //eger veri kokten kucukse soldadir
    if (veri < root->veri) 
        root->sol = sil(root->sol, veri); 
    
    //eger veri kokten buyukse sagdadir
    else if (veri > root->veri) 
        root->sag = sil(root->sag, veri); 
  
    // veri koke esitse silinecek veri odur
    else
    { 
        
        if (root->sol == NULL) // yapraksiz veya tek yapragi olan dugumler
        { 
            struct Dugum *temp = root->sag; 
            free(root); 
            return temp; 
        } 
        else if (root->sag == NULL) // yapraksiz veya tek yapragi olan dugumler
        { 
            struct Dugum *temp = root->sol; 
            free(root); 
            return temp; 
        } 
  
        // iki cocugu olan dugumler
        struct Dugum* temp = minValueDugum(root->sag); 
        root->veri = temp->veri; 
        root->sag = sil(root->sag, temp->veri); 
    } 
    return root; 
} 
 
int tek_cocuklu_dugum_sayisi(struct Dugum *root){

        int c;


        if (root == NULL){
                 return c;
        }


        if ((root->sol != NULL && root->sag == NULL) ||(
                root->sol == NULL && root->sag != NULL)){
                c++;
        }


        tek_cocuklu_dugum_sayisi(root->sol);
        tek_cocuklu_dugum_sayisi(root->sag);


}

int main() 
{ 
    srand(time(0)); //rastgele sayi uretmek icin
	struct Dugum *root = NULL; //koku olustur
    int dizi[10], sayac = 0;
    int sayi = rand()%100; //0 ile 100 arasi sayi al
    dizi[sayac] = sayi;
    sayac++;    
	root = ekle(root, sayi); //koke bu sayiyi ekle, ilk random
    printf("%d\n",sayi);
    for(int i = 0; i<9; i++) //toplamda 10 sayi eklenecek
    {
        sayi = rand()%100;
        dizi[sayac] = sayi;
        sayac++;
        printf("%d\n",sayi);
        ekle(root, sayi); 
    }
    yazdir(root); //yazdir
    int silinecek = 0, i=0, bulundu = 0;
    printf("\n\n %d\n", tek_cocuklu_dugum_sayisi(root));
    while (root != NULL) //koke kadar silinebilir
    {
        printf("\n\nSilmek istediginiz degeri giriniz: ");
        scanf("%d", &silinecek);
        for ( i = 0; i < 10; i++)
        {
            if (dizi[i] == silinecek)
            {
                bulundu = 1;
                dizi[i] = -1;
                break;  
            }
        }
        if (bulundu == 1)
        {
            sil(root, silinecek);
            printf("Agacin son hali: \n\n");
            yazdir(root);
            bulundu = 0;
        }
        else
        {
            printf("Girdiginiz sayi agacta bulunamadi.");
        }
    }
    
	return 0; 
} 
