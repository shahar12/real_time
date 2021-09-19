/* date : 09/05/21  => final project real time telhai collage, system : VxWorks 
    -this  class is the controllar of the simulation 
    -the class will initliz 100 plane object, each plane have a uniq id and massage queue.
    -for each plane that we crate we will crate a uniq atc proc for that plane. 
    -the steps of initliz : 
    - create the controllar inside a loop crate a uniq atc that wil crate massage queue and  
    will create plane . 
    steps of sim = > 
    1. create controllar
    2. create 100 uniq atc => atc create a lisenter for that X plane in is watch. 
    3. create 100 plane.
    4. start sim_run that will init the  simulation 
*/
#include "vxWorks.h"
#include "msgQLib.h"
#include "taskLib.h"
#include "semLib.h"
#include "stdio.h"

#define MAX_NUMBER_OF_PLANE 100 
#define STACK_SIZE  200

/* when creating the objects optional => when creating atc this atc will create x plane 
according to the capcity of a single atc person controllar  */
int init_main_server();
/* will activate each x time*/
int check_plane_stutus();
/* after creating all the sim object will run the objects in a time controll loop
function will  simArgs = {get the time , number of plane for each atc , ....} */
void run_sim(simArgs...);
/* easy format func to print massage to console */
void logger(char *msg){
    static int i = 0;
    ptinf("msg_number : %d , content :  %s \n",i,msg);
} 
