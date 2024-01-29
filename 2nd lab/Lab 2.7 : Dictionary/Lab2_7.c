// Kamin Jittapassorn 66070503409

#include<stdio.h>
#include<string.h>

struct dict{
    char value[100];
    char key[100];
};

void editdict(struct dict *dic, int size, char *editKey, char *editValue){
    int found = 0;
    for(int i=0; i<size; i++){
        // Compare the key with editKey
        if(strcmp(dic[i].key, editKey) == 0){
            // If found, change the value
            strcpy(dic[i].value, editValue);
            found = 1;
            break;
        }
    }
    if(found == 0){ // If not found, print "No change"
        printf("No change\n");
    }
}

void printdict(struct dict *dic, int size){
    for(int i=0; i<size ; i++){
        printf("%s : %s\n",dic[i].key,dic[i].value);
    }
}

int main(){
    int size;
    scanf("%d",&size);
    struct dict dic[size];

    for(int i=0; i<size; i++){
        scanf("%s %s", dic[i].key, dic[i].value);
    }

    char editKey[100], editValue[100];
    scanf("%s %s", editKey, editValue);

    editdict(dic, size, editKey, editValue);
    printdict(dic, size);

    return 0;
}
