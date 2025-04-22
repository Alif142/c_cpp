#include <stdio.h>
#include <string.h>
struct Book_info{
    char name[10];
    int id;
    int publishYear;
    char author[15];
    float presentPrice;

};
int main(){
    struct Book_info b[100];

    printf("Enter book name:");
    fgets(b[0].name,sizeof(b[0].name),stdin);
    b[0].name[strcspn(b[0].name, "\n")] = '\0';

    printf("Enter author:");
    fgets(b[0].author,sizeof(b[0].author),stdin);
    b[0].author[strcspn(b[0].author, "\n")] = '\0';

    while (getchar() != '\n');

    printf("Enter book id:");
    scanf("%d",&b[0].id);
    getchar();
    printf("Enter publish year:");
    scanf("%d",&b[0].publishYear);
    getchar();
    printf("Enter present Price:");
    scanf("%f",&b[0].presentPrice);
    getchar();

    FILE *file = fopen("file1.txt", "w");
    fprintf(file,"Book name:%s\n",b[0].name);
    fprintf(file,"Book author:%s\n",b[0].author);
    fprintf(file,"Book ID:%d\n",b[0].id);
    fprintf(file,"Book publish year:%d\n",b[0].publishYear);
    fprintf(file,"Present price:%f\n",b[0].presentPrice);



}
