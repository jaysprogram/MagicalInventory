
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 101

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
    // number of N roles at school
    int num_roles;
    scanf("%d",num_roles);
    printf("%d",num_roles);

    //for n amount of roles collect the next lines containing 
    //first the i-th role and than the magical material name and amount seperated by spaces
    // example role:2 name:gravedust amt need:5



    //next line will contain number of People D
    //example : 9



    // next line will contain integers D long representing which role each citizen gets, the index is the citezens.
    //example: 1 3 2 1 3 4 2 1 4 3 1


    // Next line integer u representing number of updates. for loop maybe
    //example : 3

    //next u amount of lines are updates. type 1 update changes the material cost taking in
    //from m to x m being name of material x being magic amount type 2 requires roles being r, a being different amount , and 
    // m being the material name 
    //hrldofdf







    return 0;
}