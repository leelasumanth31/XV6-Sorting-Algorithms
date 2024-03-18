#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

#define size 100
static int lines =0;
static int mLines=0;



void swap(char** data, int i, int j){
    char storeData[size];
    strcpy(storeData,data[i]);
    strcpy(data[i],data[j]);
    strcpy(data[j],storeData);
}


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
    //printf("Str1: %s\t Str2: %s\t Value: %d\n",temp,data,strcmp(month, temp));
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
     
   char storeData[size];
    //printf("1MLines: %d\n",mLines);
    for (int i = 0; i < mLines; i++)
    {
        //printf("String: %s .    I: %d\n",data[i],i);
        int start = i;
        strcpy(storeData, data[i]);
        for (int j = i+1; j < mLines; j++)
        {
            
            if (strcmp(storeData, data[j]) > 0)
            {
                strcpy(storeData, data[j]);
                start = j;
            }
        }
        if (start != i)
        {
            swap(data, i, start);
        }
    }
}


void  selectionMonthSortArray(char** data, char** data2){

   char storeData[size];
    for (int i = 0; i < lines+1; i++)
    {
        int start = i;
        strcpy(storeData, data[i]);

      
        strcpy(storeData, data[i]);
        for (int j = i+1; j < lines; j++)
        {
            if (strcmp(storeData, data[j]) > 0)
            {
                strcpy(storeData, data[j]);
                start = j;
            }
        }
        if (start != i)
        {
            swap(data, i, start);
        }
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





void  selectionSortArray(char** data){
     
   char storeData[size];
    for (int i = 0; i < lines-1; i++)
    {
        int start = i;
        strcpy(storeData, data[i]);
        for (int j = i+1; j < lines; j++)
        {
            if (strcmp(storeData, data[j]) > 0)
            {
                strcpy(storeData, data[j]);
                start = j;
            }
        }
        if (start != i)
        {
            swap(data, i, start);
        }
    }
}



void  selectionSortNumberArray(char** data){
     
   char storeData[size];
    for (int i = 0; i < lines-1; i++)
    {
        int start = i;
        strcpy(storeData, data[i]);
        for (int j = i+1; j < lines-1; j++)
        {
            if(atoi(storeData)>atoi(data[j]))
            {
                strcpy(storeData, data[j]);
                start = j;
            }
        }
        if (start != i)
        {
            swap(data, i, start);
        }
    }
}

void uniqueArray(char** data){
    char storeData[size];
    for (int i = 0; i < lines-1; i++)
    {
        int start = i;
        strcpy(storeData, data[i]);
        for (int j = i+1; j < lines; j++)
        {
            if (strcmp(storeData, data[j]) == 0)
            {
                strcpy(storeData, data[j]);
                start = j;
            }
        }
        if (start != i)
        {
            //swap(data, i, start);
            strcpy(data[i],"notUnique");
        }
    }
}



void getMonthsData(int start, int argc,char *argv[argc],char** data,char** data2){
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
                

            if(threeCompare("jan", data[lines])==0){

            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("0",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("feb", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("1",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("mar", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("2",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("apr", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("3",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("may", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("4",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("jun", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("5",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("jul", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("6",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("aug", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("7",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("sep", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("8",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("oct", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData("9",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("nov", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData(":",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        if(threeCompare("dec", data[lines])==0){
            
            data2[mLines] = (char*) malloc(sizeof(char) * 10000);
            strcpy(data2[mLines],addData(";",data[lines]));
            mLines++;
            strcpy(data[lines],"lv u 3000");
            continue;
        }
        lines++;
        //printf("Line Number: %d\n", lines);
        
        }while(EOF_Flag>0);
        // selectionSortArray(data, lines);
        //selectionSortArray(data, lines);
        //insertionSortArray(data, lines);
        //printData(data, lines);
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
        // selectionSortArray(data, lines);
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



void  selectionBlankSortArray(char** data){

    char storeData[size];
    for (int i = 0; i < lines-1; i++)
    {
        int start = i;
        strcpy(storeData, data[i]);
        for (int j = i+1; j < lines; j++)
        {
            if (strcmp(trimLeadingSpaces(storeData),trimLeadingSpaces(data[j]))>0)
            {
                strcpy(storeData, data[j]);
                start = j;
            }
        }
        if (start != i)
        {
            swap(data, i, start);
        }
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
         selectionSortArray(data);
        // printData(data,0);
        for (int i=0;i<lines;i++){
            //printf("I: %d . S: %s\n",i,data[i]);
            printf("%s",data[i]);
        }
    }
    
    if(argc == 2){
        getData(1,argc,argv,data);
        //getData(1, argv, data);
         selectionSortArray(data);
        printData(data,1);
    }
    
    if(argc >= 3){
        if(strcmp(argv[1], "-r")==0){
            getData(1,argc,argv,data);
            //getData(2, argv, data);
             selectionSortArray(data);
            // printData(data);
            // printf("****************\n");
            printSortReverseData(data);
        }
        if(strcmp(argv[1],"-o")==0){
            //printf("\n0\n");
            getData(1,argc,argv,data);
            //getData(3, argv, data);
             selectionSortArray(data);
            char* file = argv[2];
            //printSortData(data);
            printToFile(data, file);
        }
        if(strcmp(argv[1],"-n")==0){
            //printf("\n0\n");
            getData(1,argc,argv,data);
            //getData(2, argv, data);
             selectionSortNumberArray(data);
            //printData(data,1);
            printNumbersData(data,1);
        }
        if(strcmp(argv[1],"-u")==0){
            //printf("\n0\n");
            getData(1,argc,argv,data);
            //getData(2, argv, data);
             selectionSortArray(data);
            uniqueArray(data);
            printWithUnique(data);

        }
        if(strcmp(argv[1],"-M")==0){
            //printf("\n0\n");
            char** data2 = (char**) malloc(sizeof(char*) * 10000);
            //getData(1,argc,argv,data);
            getMonthsData(2, argc, argv, data,data2);
            selectionMonthSortArray(data, data2);
            monthSortArray(data2);
            monthPrintData(data,data2,1);
        }
        if(strcmp(argv[1],"-b")==0){
            //printf("\n0\n");
            //getData(2, argv, data);
            getData(1,argc,argv,data);
            selectionSortArray(data);
            selectionBlankSortArray(data);
            printData(data,2);
        }
    }

    //printf("\n**************************************************\n");
    //printf("Total Ticks: %d\n",uptime()-startTicks);
    exit(0);
}