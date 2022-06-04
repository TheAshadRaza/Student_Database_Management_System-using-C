#include<stdio.h>
#include<conio.h>

      
void addStudent();
void studentRecord();
void searchStudent();
void delete();

struct student{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
    char vill[20];
    float per;
};

void main(){
    int choice;
    while(choice!=5){
        printf("\t\t\t========= STUDENT DATABSE MANAGEMENT SYSTEM ========");
        printf("\n\n\n\t\t\t\t 1.Add Student Record\n");
        printf("\t\t\t\t 2.Student Records\n");
        printf("\t\t\t\t 3.Search Students\n");
        printf("\t\t\t\t 4.Delete Records\n");
        printf("\t\t\t\t 5.Exit\n");
        printf("\t\t\t\t  ________________________\n");
        printf("\t\t\t\t  ");
        scanf("%dd",&choice);

        switch(choice){
                                                                case 1:
                                                                // clrscr();
                                                                addStudent();
                                                                // clrscr();
                                                                break;

                                            case 2:
                                            // clrscr();
                                            studentRecord();
                                            printf("\t\t\t\tPress any key to exit\n");
                                            getch();
                                            // clrscr();
                                            break;

                        case 3:
                        // clrscr();
                        searchStudent();
                        printf("\n\t\t\t\tPress any key to exit\n");
                        getch();
                        // clrscr();
                        break;

    case 4:
    // clrscr();
    delete();
    printf("\n\t\t\t\tPress any key to exit\n");
    getch();
    // clrscr();
    break;

        }
    }
};

// define the addStudent() function and it's logic ;
void addStudent(){
    char another;
    FILE *fp;
    struct student info;

    do{

        // clrscr();
        printf("\t\t\t\t=============Add Student Info=======\n\n\n");
        fp=fopen("student_info.txt","a");
        printf("\n\t\t\tEnter First Name: ");
        scanf("%s",&info.first_name);
        printf("\n\t\t\tEnter Last Name: ");
        scanf("%s",&info.last_name);
        printf("\n\t\t\tEnter Roll No : ");
        scanf("%d",&info.roll_no);
        printf("\n\t\t\tEnter Class : ");
        scanf("%s",&info.Class);
        printf("\n\t\t\tEnter Address: ");
        scanf("%s",&info.vill);
        printf("\n\t\t\tEnter Percentage: ");
        scanf("%f",&info.per);
        printf("\n\t\t\t_________________________\n");

        if(fp==NULL){
            fprintf(stderr,"\t\t\tCan't open file");
        }else{
            printf("\t\t\tRecord stored successfully\n");
        }
        fwrite(&info,sizeof(struct student),1,fp);
        fclose(fp);
        printf("\t\t\tDo You want to add another record ?(y/n) : ");
        scanf("%s",&another);
    }while(another=='y'|| another=='Y');
}

// now, we make some logic for showing record from dtabase :


                        void studentRecord(){
                        FILE *fp;
                        struct student info;
                        fp=fopen("student_info.txt","r");
                                printf("\t\t\t\t=============Student Records=======\n\n\n");

                                if(fp==NULL){
                                    fprintf(stderr,"\t\t\tCan't open file");
                                }else{
                                    printf("\t\t\tRecords\n");
                                    printf("\t\t\t\t______________\n\n");
                                }
                            while(fread(&info,sizeof(struct student),1,fp)){
                                printf("\n\t\t\t\tStudent Name :    %s %s",info.first_name,info.last_name);
                                printf("\n\t\t\t\tRoll No :    %d",info.roll_no);
                                printf("\n\t\t\t\tClass :    %s",info.Class);
                                printf("\n\t\t\t\tAddress :     %s",info.vill);
                                printf("\n\t\t\t\tPercentage :     %f",info.per);
                                printf("\n\t\t\t\t___________________________________________________________\n");
                            }
                        fclose(fp);
                        getch();

                        }
        // now we build some logic for seraching students via roll_no  ::::::::::::::::::::::::::::::://

void searchStudent(){
    FILE *fp;
    struct student info;
    int roll_no,found=0;

    fp=fopen("student_info.txt","r");
     printf("\t\t\t\t============= Search Student =======\n\n\n");
     printf("\t\t\tEnter Roll No : ");
     scanf("%d",&roll_no);

      while(fread(&info,sizeof(struct student),1,fp)){
                                 if(info.roll_no==roll_no){

                                found=1;
                                printf("\n\t\t\t\tStudent Name :    %s %s",info.first_name,info.last_name);
                                printf("\n\t\t\t\tRoll No :    %d",info.roll_no);
                                printf("\n\t\t\t\tClass :    %s",info.Class);
                                printf("\n\t\t\t\tAddress :     %s",info.vill);
                                printf("\n\t\t\t\tPercentage :     %f",info.per);
                                printf("\n\t\t\t\t___________________________________________________________\n");
                            }
 }

                    if(!found){
                        printf("\n\t\t\tRecord not Found\n");
                    }
                        fclose(fp);
                        getch();
}


// last but not the least -----> we build a logic for delete() students records from database   ::::::::::
void delete(){
     FILE *fp,*fp1;
    struct student info;
    int roll_no,found=0;

     printf("\t\t\t\t============= Search Student =======\n\n\n");
    fp=fopen("student_info.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\tEnter roll no : ");
    scanf("%d",&roll_no);

 if(fp==NULL){
  fprintf(stderr,"\t\t\tCan't open file\n");
 }

 while(fread(&info,sizeof(struct student),1,fp)){

    if(info.roll_no==roll_no){
     found=1;
  }
  else{
      fwrite(&info,sizeof(struct student),1,fp1);
  }
 }
 fclose(fp);
 fclose(fp1);
 if(found){
     remove("student_info.txt");
     rename("temp.txt","student_info.txt");
     printf("\n\t\t\tRecord delete successfully\n");
 }
if(!found){
    printf("\n\t\t\tRecord not found");
}
getch();

}
//   The End thank you