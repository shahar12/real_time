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
 
#define MAX_AMOUNT_OF_TIME 250

#define STACK_SIZE  200

#define DELAY 50 

#define TIME_SIM_IN_SECANDS 100
typedef struct Point{
	int x ; 
	int y ; 
}Point;

typedef struct Plane{
	Point location; 
	int airSpeed ; 
	int high ; 
	int time_to_land; 
	int is_ok; 
}Plane;

//list of planes
Plane plane_list[MAX_NUMBER_OF_PLANE];
/* will activate each x time** after creating all the sim object will run the objects in a time controll loop
function will  simArgs = {get the time , number of plane for each atc , ....} */
void run_sim(int amount_of_planes,int amount_of_time);
/* easy format func to print massage to console */
void logger(char *msg);
//remove only temp 
void init_atc(){
	logger("init atc");
}
