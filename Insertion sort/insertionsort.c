#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

#define size 100
static int lines =0;
static int mLines=0;






void printData(char** data, int start){
    //printf("\n4\n");
    //printf("LINES : %d\n", lines);
    for (int i=start;i<lines;i++){
        //printf("I: %d . S: %s\n",i,data[i]);
        printf("%s\n",data[i]);
    }
}

void printNumbersData(char** data, int start){
    //printf("\n4\n");
    //printf("LINES : %d\n", lines);
    for (int i=start;i<lines-1;i++){
        //printf("I: %d . S: %s\n",i,data[i]);
        printf("%s\n",data[i]);
    }
}


void monthPrintData(char** data, char** data2, int start){
    //printf("Prints data without months\n");
    for (int i=start;i<lines;i++){
        
        if(strcmp(data[i],"lv u 3000")==0){
            continue;
        }
        //printf("I: %d . S: %s\n",i,data[i]);
        printf("%s\n",data[i]);
    }
    //printf("Prints data with months\n");
    for (int i=0;i<mLines;i++){
        //printf("I: %d . S: ",i);
        for(int j=1;j<strlen(data2[i]);j++){
            printf("%c",data2[i][j]);
        }
        //printf("%s\n",data2[i]);
        printf("\n");
    }
}

int threeCompare(char* month, char* data){
    char temp[3]="";
    temp[0]=data[0];
    temp[1]=data[1];
    temp[2]=data[2];
    int value = strcmp(month, temp);
    return value;
}



char* addData(char* num,char* first){
    
    int length=strlen(first);
    length=length+1;
    char* temp=malloc(length);
    temp[0]=num[0];
    for(int i=0;i<length;i++){
        temp[i+1]=first[i];
    }
    return temp;

}

void monthSortArray(char** data){
   for (int i = 1; i < mLines; i++)
    {
        char storeData[size];
        strcpy(storeData,data[i]);
        int j = i - 1;
        while(j>=0 && strcmp(data[j],storeData)>0)
        {
            strcpy(data[j+1],data[j]);
            j = j - 1;
        }
        strcpy(data[j+1],storeData);
    }
}


void insertionMonthSortArray(char** data, char** data2){
    
   for (int i = 1; i < lines; i++)
    {
        char storeData[size];
        strcpy(storeData,data[i]);
        int j = i - 1;
        if(threeCompare("jan", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("0",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("feb", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("1",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("mar", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("2",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("apr", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("3",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("may", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("4",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("jun", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("5",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("jul", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("6",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("aug", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("7",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("sep", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("8",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("oct", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("9",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("nov", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData(":",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        if(threeCompare("dec", data[i])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData(";",data[i]));
            mLines++;
            strcpy(data[i],"lv u 3000");
            continue;
        }
        while(j>=0 && strcmp(data[j],storeData)>0)
        {
            strcpy(data[j+1],data[j]);
            j = j - 1;
        }
        strcpy(data[j+1],storeData);
    }

}

void printSortReverseData(char** data){
    for (int i=lines-1;i>=2;i--){
        printf("%s\n",data[i]);
    }
}

void printToFile(char** data, char* file){
    int out;
	out = open(file, O_CREATE|O_WRONLY);
	//printf("%d",out);
    for (int i=3;i<lines;i++){
        // fprintf(out,"I: %d . S: %s\n",i,data[i]);
        fprintf(out,"%s\n",data[i]);
    }
	close(out);
}

void printWithUnique(char** data){
    //printf("\n4\n");
    for (int i=2;i<lines;i++){
        if(strcmp(data[i],"notUnique")!=0){
            //printf("I: %d . S: %s\n",i,data[i]);
            printf("%s\n",data[i]);
        }
    }
}





void insertionSortArray(char** data){
   for (int i = 1; i < lines; i++)
    {
        char storeData[size];
        strcpy(storeData,data[i]);
        int j = i - 1;
        while(j>=0 && strcmp(data[j],storeData)>0)
        {
            strcpy(data[j+1],data[j]);
            j = j - 1;
        }
        strcpy(data[j+1],storeData);
    }
}



void insertionSortNumberArray(char** data){
   for (int i = 1; i < lines-1; i++)
    {
        char storeData[size];
        strcpy(storeData,data[i]);
        int j = i - 1;
        while(j>=0 && atoi(data[j])>atoi(storeData))
        {
            strcpy(data[j+1],data[j]);
            j = j - 1;
        }
        strcpy(data[j+1],storeData);
    }
}

void uniqueArray(char** data){
   for(int i=0;i<=lines-1;i++){
      for(int j=i+1;j<=lines-1;j++){
         if(strcmp(data[i],data[j])==0){
            strcpy(data[j],"notUnique");
         }
      }
   }
}






void getData(int start, int argc,char *argv[argc],char** data){
    for(int i=start;i<argc;i++){
        //printf("\n2\n");
        //int lines=0;
        char* file = argv[i];
        int fd = open(file, O_RDONLY);
        int EOF_Flag=1;

        do{
        data[lines] = (char*) malloc(sizeof(char) * 10000); 
        char* line = data[lines];


                int EOF = 0;
                char single;
                while (read(fd, &single, 1) > 0) {
                if (single == '\n') break;
                line[EOF++] = single;
                }
                
                
                if(single != '\n'){
                    EOF_Flag=EOF;
                    //printf("line_len: %d",EOF);
                }
                


        lines++;
        //printf("Line Number: %d\n", lines);
        
        }while(EOF_Flag>0);
        //insertionSortArray(data, lines);
        //selectionSortArray(data, lines);
        //insertionSortArray(data, lines);
        //printData(data, lines);
    }
    
}

char* trimLeadingSpaces(char* str){
    int spaceCount = 0,  k = 0;
    //****************geeksforgeeks********************
    while (str[spaceCount] == ' ' || str[spaceCount] == '\t' || str[spaceCount] == '\n')
    {
        spaceCount++;
    }
    //****************geeksforgeeks********************
    char* temp=malloc(strlen(str));
    for(int i=spaceCount;i<strlen(str);i++){
        temp[k++]=str[i];
    }
    return temp;
}



void insertionBlankSortArray(char** data){

    for (int i = 1; i < lines; i++)
    {
        char storeData[size];
        strcpy(storeData,data[i]);
        int j = i - 1;
        while(j>=0 && strcmp(trimLeadingSpaces(data[j]),trimLeadingSpaces(storeData))>0)
        {
            strcpy(data[j+1],data[j]);
            j = j - 1;
        }
        strcpy(data[j+1],storeData);
    }


}

int main(int argc,char *argv[]) {
    //int startTicks=uptime();
    //printf("\n**************************************************\n");
    char** data = (char**) malloc(sizeof(char*) * 10000);
    
    if(argc<=1){
        char *data[size];
		do{
			data[lines]=malloc(size);
			gets(data[lines],size);
		}while(strcmp(data[lines++],"")!=0);
        insertionSortArray(data);
        // printData(data,0);
        for (int i=0;i<lines;i++){
            //printf("I: %d . S: %s\n",i,data[i]);
            printf("%s",data[i]);
        }
    }
    
    if(argc == 2){
        getData(1,argc,argv,data);
        //getData(1, argv, data);
        insertionSortArray(data);
        printData(data,1);
    }
    
    if(argc >= 3){
        if(strcmp(argv[1], "-r")==0){
            getData(1,argc,argv,data);
            //getData(2, argv, data);
            insertionSortArray(data);
            // printData(data);
            // printf("****************\n");
            printSortReverseData(data);
        }
        if(strcmp(argv[1],"-o")==0){
            //printf("\n0\n");
            getData(1,argc,argv,data);
            //getData(3, argv, data);
            insertionSortArray(data);
            char* file = argv[2];
            //printSortData(data);
            printToFile(data, file);
        }
        if(strcmp(argv[1],"-n")==0){
            //printf("\n0\n");
            getData(1,argc,argv,data);
            //getData(2, argv, data);
            insertionSortNumberArray(data);
            printNumbersData(data,1);
        }
        if(strcmp(argv[1],"-u")==0){
            //printf("\n0\n");
            getData(1,argc,argv,data);
            //getData(2, argv, data);
            insertionSortArray(data);
            uniqueArray(data);
            printWithUnique(data);

        }
        if(strcmp(argv[1],"-M")==0){
            //printf("\n0\n");
            char** data2 = (char**) malloc(sizeof(char*) * 10000);
            getData(1,argc,argv,data);
            //getData(2, argv, data);
            insertionMonthSortArray(data, data2);
            monthSortArray(data2);
            monthPrintData(data,data2,2);
        }
        if(strcmp(argv[1],"-b")==0){
            //printf("\n0\n");
            // getData(2, argv, data);
            getData(1,argc,argv,data);
            insertionSortArray(data);
            insertionBlankSortArray(data);
            printData(data,2);
        }
    }

    //printf("\n**************************************************\n");
    //printf("Total Ticks: %d\n",uptime()-startTicks);
    exit(0);
}