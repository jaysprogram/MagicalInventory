
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct mag_mat_for_role {
int type ; // index into the list of magical materials
long long amount_needed ;
}mag_mat_for_role;


typedef struct role {
int materials_needed ;
mag_mat_for_role * item_list ;
}role;

typedef struct mag_mat_for_list {
char * mat_name ;
long long total_amount_needed ;
long long magic_required ;
}mag_mat_for_list;





int main(){
    // number of roles at school
    int num_roles;
    scanf("%d",num_roles);







    return 0;
}