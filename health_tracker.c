// "C:\Users\Admin\Desktop\health.txt" health tracker
#include<stdio.h>
#include<stdlib.h>
void ReadData();
void StoreData();
struct healthtracker{//structure to store data
    char date[11];
    char bp[10];
    float sugar;
    float w;
};
int main(){
    char n;
    while(1){// project on health tracker asking for choice....
    printf("----------HEALTH TRACKER--------\n");
    printf("\nEnter your choice\n'r' to read health data\n's' to store health data\n'e' to exit\n");
    scanf(" %c", &n);
    switch(n){
        case 'r':
        ReadData();
        break;
        case 's':
        StoreData();
        break;
        case 'e':
        printf("Exiting....\n");
        return 0;
        default:
        printf("Invalid Choice\n");
        break;
    }}
    return 0;
    }

void ReadData()//method to read the already stored data of patient
    {
        char ch;
        FILE *fptr;
        fptr=fopen("C:\\Users\\Admin\\Desktop\\health.txt", "r");
        ch=fgetc(fptr);
        while(ch != EOF)
        {
            printf("%c", ch);
            ch=fgetc(fptr);
        }
        fclose(fptr);
        printf("\n----------DATA PRINTED--------------\n");
        
    }
        
    void StoreData(){//method to store new data of patient
    struct healthtracker h;
        printf("enter date in format \"dd-mm-yyyy\"\n");
        scanf("%10s", h.date);
        printf("enter blood pressure reading in format aaa/bbb\n");
        scanf("%9s", h.bp);
        printf("enter sugar reading\n");
        scanf("%f", &h.sugar);
        printf("enter weight\n");
        scanf("%f", &h.w);
        FILE *fptr;
        fptr=fopen("C:\\Users\\Admin\\Desktop\\health.txt","a");
        if(fptr==NULL){
        
            printf("\n****ERROR:File Not Opening****\n");
            return;
        }
        fprintf(fptr, "\nDate: %s", h.date);
        fprintf(fptr, "\nBP: %s", h.bp);
        fprintf(fptr, "\nSugar: %.2f", h.sugar);
        fprintf(fptr, "\nWeight: %.2f kg\n", h.w);
        fprintf(fptr, "--------------------------\n");
        fclose(fptr);
        printf("Data Stored Successfully\n");
    }
