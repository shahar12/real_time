/* 
-this class will function as the main server of the progrome 
-there will be 100 clients => {plane objects} 
-this main server will init all the atc if each one of atc create 5 plane 
-then we will init 20 atc to create 100 planes
-after init atc objects,
 we will create a server reader that will pass massage from one atc to the other
 can pass massage to other contrllar like  
 -------------tasks for main server:------------- 
 - init all the atc + read massage function  =>  init_main_server(). 
 - init all other controllar  => init_controllar()
 --------------- get data from all atc and check if all ok----------------
 -will init a new server_get_data_from atc() 
*/
#include "Word_control_center.h"
#define NUMBER_OF_CONTROLLAR 3
static int N; 

/* store data from check in struct data array  */
typedef struct Controllar{
    int control_id;
    MSG_Q_ID control_queue;
}

Controllar controllar_list[NUMBER_OF_CONTROLLAR];

typedef struct msgStruct
{
    MSG_Q_ID response;
    int palne_id;
    char *msg;
    int type;
} msgStruct;

/* functions */
/* will push all the relevante controllar inside ->controllar_list */
/*create controller = > { landing_server, takeoff_server, parking_server }  */
void init_controllar();
/*
   init all atc according to max number of plane to atc = N
   init the server read process that  will listan to massage 
*/
void init_main_server();
/* upon receiveing massage -> send  to currect address */
void receive_and_send_massage_to_destntion(from, to);
void server_get_data_from atc()
