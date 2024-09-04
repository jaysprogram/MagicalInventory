#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 101
#define MAX_ROLES 100000
#define MAX_DENI 200000
#define MAX_UNIQUE_MAT 100000

typedef struct mag_mat_for_role {
int type ; // index into the list of magical materials
long long amount_needed ;
}mag_mat_for_role;

typedef struct role {
int materials_needed ;
mag_mat_for_role * item_list ;
}role;

typedef struct mag_mat_for_list {
char * mat_name ; // this is where i index to
long long total_amount_needed ;
long long magic_required ;
}mag_mat_for_list;




role roles[MAX_ROLES];
int denizenRole[MAX_DENI];
mag_mat_for_list * materialsList; // list of materials including its stats
int num_materials = 0; // basically index for material list

int checkMatIndex(char * name){
    for ( int i = 0; i < num_materials; i++){
        if(strcmp(materialsList[i].mat_name, name) == 0) // checks if material name is already in the array
        return i;
    }
    
    materialsList[num_materials].mat_name = strdup(name); // assigns new material name
    return num_materials++; // important 


}


void initRoles() {
    materialsList = malloc(sizeof(mag_mat_for_list) * num_materials);

    long long numRoles;
    scanf("%lld",&numRoles);
    for (int i = 0; i < numRoles; i++){


        int differentMatNeeded;
        scanf(" %d", &differentMatNeeded);
        roles[i].materials_needed = differentMatNeeded; //amnt of different material needed
        roles[i].item_list = malloc(sizeof(mag_mat_for_role) * differentMatNeeded); // dynamically create a list for the differentr materials

        for (int j = 0; j < differentMatNeeded; j++){
            char materialName[MAX_STRING];
            long long amountOfMatNeeded;
            scanf("%s %lld", materialName, &amountOfMatNeeded);
            
            int matIndex = checkMatIndex(materialName);

            roles[i].item_list[j].type = matIndex; //store the material index
            roles[i].item_list[j].amount_needed = amountOfMatNeeded; // stire the amount of the material needed

        }
    }
}


void getMagicMaterialValues(){
    for( int i = 0; i < num_materials; i++){
        char   material_name[MAX_STRING];
        long long magic_needed; // scan for name and magic needed
        scanf("%s %lld", material_name, &magic_needed);
        materialsList[i].magic_required = magic_needed;
        materialsList[i].mat_name = strdup(material_name);

    }

    for (int i = 0; i < num_materials; i++) {
        printf("Material: %s, Magic Required: %lld\n", materialsList[i].mat_name, materialsList[i].magic_required);
        
        }
}



int main(){
    initRoles();
    
    getMagicMaterialValues();


    printf("%s\n", materialsList[0].mat_name);
    printf("%lld\n",roles[0].item_list[0].amount_needed);

    for (int i = 0; i < num_materials; i++)
        free(materialsList[i].mat_name);

    for (int i = 0; i < MAX_ROLES; i++)
        free(roles[i].item_list);  // Free item lists for each role





}