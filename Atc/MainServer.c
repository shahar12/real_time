#include "MainServer.h"

void init_main_server()
{
	int i ; 
//	crate main server queue 
    main_Q = msgQCreate(MAX_MSGS, sizeof(msgStruct),MSG_Q_FIFO);
    int server_tsk_id;
    logger(" inside main server ");
    /* create atc  */
    logger("  create atc ");
    for ( i = 0; i < amount_of_planes; i++)
    {
        logger(" atc controllar is created ");
        taskSpwon("atc1", PRIO, 0, STACK_SIZE,init_atc,(int)main_Q,i);
    }
    int res = init_controllar();
    if(res){
        /* start sim loop  */
        logger(" create  server ");
        server_tsk_id = taskSpwon("atc1", PRIO, 0, STACK_SIZE,read_server,(int)main_Q,i);
    }else {
        logger("Error creating controllar exit sim");
        exit(1);
    }
}


/* return 1 if all controllar created ok, else return 0  */

int init_controllar(){

    logger("create controllar"); 

    controllar_list[0].control_queue = msgQCreate(MAX_MSGS, sizeof(msgStruct), MSG_Q_FIFO);

    controllar_list[0].id = taskSpwon("land", PRIO, 0, STACK_SIZE, land_init, (int)controllar_list[0].control_queue, (int)main_Q);

    controllar_list[1].control_queue = msgQCreate(MAX_MSGS, sizeof(msgStruct), MSG_Q_FIFO);

    controllar_list[1].id = taskSpwon("takeoff", PRIO, 0, STACK_SIZE, takeoff_init, (int)controllar_list[1].control_queue, (int)main_Q);

    controllar_list[2].control_queue = msgQCreate(MAX_MSGS, sizeof(msgStruct), MSG_Q_FIFO);

    controllar_list[2].id = taskSpwon("parking", PRIO, 0, STACK_SIZE, park_init, (int)controllar_list[2].control_queue,(int)main_Q);

    if (controllar_list[0].control_queue && controllar_list[1].control_queue && controllar_list[2].control_queue){

        return 1; 

    }

    return 0; 

}

void land_init(){
	logger("create land control ");
}
void  takeoff_init(){
	logger("create takeoff control ");
}

void park_init(){
	logger("create parking control ");
}


/*

   init all atc according to max number of plane to atc = N

   init the server read process that  will listan to massage 

*/

/* when creating the objects optional => when creating atc this atc will create x plane 

according to the capcity of a single atc person controllar*/


/* upon receiveing massage -> send  to currect address */

void receive_and_send_massage_to_destntion(){
	;
}
void server_get_data_from_atc(){
	;
}

// while simuliton is runinig 
void read_server(){
	logger(" stert listening to massage from plane  ");
	//while(!end_of_sim)
	// Receive message = > save data into date base  
	// Read the message - Plane i
	// check data base for Error = > if ok => continue => if not => solve problame 
}
