#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cell{
        char *anahtar;
        struct cell *next;
};

struct table_node{
        int count;
        struct cell *header;
};

struct hash_tablosu{

        struct table_node *tablo_basi;
        int tablo_uzunlugu;
        int multiplier;
};

unsigned int hash(char *s, int multiplier, int table_size){

        int i = 0;
        unsigned int value = 0;
        while(s[i] != '\0'){
                value = (s[i]+multiplier*value)%table_size;
                i++;
        }
        return value;
}

void listeyi_hash_tablosuna_donusturme(struct hash_tablosu *htable, struct cell **liste_basi){

        while(*liste_basi){

                int hindex = hash((*liste_basi)->anahtar, htable->multiplier, htable->tablo_uzunlugu);
                struct cell *bos = NULL;
                bos = (*liste_basi)->next;
                (*liste_basi)->next = NULL;

                if(!((htable->tablo_basi + hindex)->header)){
                        (htable->tablo_basi + hindex)->header = *liste_basi;
                        (htable->tablo_basi + hindex)->count++;
                }else{
                        struct cell *temp = NULL;
                        temp = (htable->tablo_basi + hindex)->header;

                        while(temp){

                                if(strcmp((*liste_basi)->anahtar, temp->anahtar)){
                                     if(temp->next != NULL){

                                                temp = temp->next;
                                        }else{
                                                temp->next = *liste_basi;
                                                (htable->tablo_basi + hindex)->count++;
                                        }
                                }else break;
                        }
                }
                *liste_basi = bos;
        }
}

int main(){
        return 0;
}

