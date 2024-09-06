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
mag_mat_for_list * materialsList = NULL; // list of materials including its stats
int num_materials = 0;
int current_capacity = 10; 

long long numRoles; // basically len of roles 
//FIX MEEEE
//need to make a material name array so input wont depend on order


int checkMatIndex(char * name){
    for ( int i = 0; i < num_materials; i++){
        if(strcmp(materialsList[i].mat_name, name) == 0) // checks if material name is already in the array
        return i;
    }

    if(num_materials >= current_capacity){
        current_capacity *= 2;
        materialsList = realloc(materialsList, sizeof(mag_mat_for_list) * current_capacity);
    }
    materialsList[num_materials].mat_name = strdup(name); // assigns new material name
    return num_materials++; // important 
}


void initRoles() {
    materialsList = malloc(sizeof(mag_mat_for_list) * current_capacity); //init material list
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
            roles[i].item_list[j].amount_needed = amountOfMatNeeded; // store the amount of the material needed

        }
    }
}


void getMagicMaterialValues(){
    for( int i = 0; i < num_materials; i++){
        char  material_name[MAX_STRING];
        long long magic_needed = 0; // scan for name and magic needed
        scanf("%s %lld", material_name, &magic_needed);
        materialsList[i].magic_required = magic_needed;
        materialsList[i].total_amount_needed = 0;

    }
    //for debugging
    for (int i = 0; i < num_materials; i++) {
        printf("Material: %s, Magic Required: %lld\n", materialsList[i].mat_name, materialsList[i].magic_required);
        
        }
}


void fetchAndAssignRoles(){
    int num_deni;
    scanf("%d",&num_deni); // loop num_denizen amount
    //assign each denizen a value 
    // access role to than access itemList to than add to number amount that have that role 
    for (int i = 0; i < num_deni; i++){
        int role_index;
        scanf("%d", &role_index); //adjust to 0 based indexing
        role_index--;

        int matAmt = roles[role_index].materials_needed;
        for (int j = 0; j < matAmt; j++){
            int index_of_material = roles[role_index].item_list[j].type;
            int amnt_of_material_needed = roles[role_index].item_list[j].amount_needed;
            materialsList[index_of_material].total_amount_needed += amnt_of_material_needed;
        }
    }
}

//Calculates total magic needed
void printTotalMagic(){
    long long totalMagic = 0;
    for (int i = 0; i < num_materials; i++){ // iterate through materail List
        long long magic_needed = materialsList[i].magic_required; // get amount required by material
        long long amtOfMaterial = materialsList[i].total_amount_needed; // get total amount of material need by all the roles
        totalMagic += magic_needed * amtOfMaterial;

    }
    printf("Totla Magic: %lld\n", totalMagic);
}

void getUpdates(){
    int numUpdates;
    int walker = 0;
    scanf("%d",&numUpdates); // iterate through updates
    while (walker < numUpdates){
        int updateType;
        scanf("%d",&updateType);


        if (updateType == 1){ //type 1 update
            //1 m x - Change the magic requirement of magical material m to x
            char name[MAX_STRING];
            long long newAmt;
            scanf("%s %llu", name, &newAmt); // get values
            for (int i = 0; i < num_materials; i++){
                if(strcmp(materialsList[i].mat_name, name) == 0){
                    materialsList[i].magic_required = newAmt;
                    break;
                }

            }

        
        }
        else{                //type 2 update 2 r m a - Role r now needs a amount of magical material m. You will be guaranteed
            int rle;         //that role r requires at least 1 of item m before the update.
            long long newAmt;                        
            char name[MAX_STRING];
            scanf("%d %s %lld",&rle,name,&newAmt);
            rle--;

            for (int j = 0; j < roles[rle].materials_needed; j++){
                int matIndex = roles[rle].item_list[j].type;

                    long long oldAmt = roles[rle].item_list[j].amount_needed;            
                     if (strcmp(materialsList[matIndex].mat_name, name) == 0){

                    // Subtract the old amount from the total
                    materialsList[matIndex].total_amount_needed -= oldAmt;

                    // Update the amount for this role
                     roles[rle].item_list[j].amount_needed = newAmt;

                    // Add the new amount to the total
                    materialsList[matIndex].total_amount_needed += newAmt;

                    printf("Updated material %s for role %d from %lld to %lld\n", name, rle + 1, oldAmt, newAmt);
                    }
            }
        }

        walker++;
        printTotalMagic();
    }


}



int main(){
    initRoles();
    
    getMagicMaterialValues();

    fetchAndAssignRoles();
    printf("amount of material needed from %s: %lld\n",materialsList[0].mat_name, materialsList[0].total_amount_needed);
    printTotalMagic();
    getUpdates();

    //printf("%s\n", materialsList[0].mat_name);
    //printf("%lld\n",roles[0].item_list[0].amount_needed);

    for (int i = 0; i < num_materials; i++){
        if(materialsList[i].mat_name != NULL){
            free(materialsList[i].mat_name);
            materialsList[i].mat_name = NULL;
        }
    }

    for (int i = 0; i < MAX_ROLES; i++){
        if(roles[i].item_list != NULL){
            free(roles[i].item_list);  // Free item lists for each role
            roles[i].item_list = NULL;
    
        }
    }
}