#include "Sim_object.h"

/* after creating all the sim object will run the objects in a time controll loop

function will  simArgs = {get the time , number of plane for each atc , ....} */

void run_sim(){

    int task_id; 
    /* amount of plane  by defult  is 50 amount of time by defult is 120 secands */
        amount_of_planes = MAX_NUMBER_OF_PLANE; 
        amount_of_time = MAX_AMOUNT_OF_TIME;    
    /* create main sever */
    logger("create main server");
    task_id = taskSpawn("init_main_server", STACK_SIZE, init_main_server, (int) amount_of_planes, (int)amount_of_time);
}

/* easy format func to print massage to console */

void logger(char *msg)

{

    static int i = 0;

    ptinf("msg_number : %d , content :  %s \n",i++, msg);

    taskDelay(DELAY);

}
