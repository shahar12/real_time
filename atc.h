/* 
- this class will create X plaens according to the permetr send  from main server
- the class will send and receive massage from palens 
- the class will monitor after the planes, and ask for data about :
1. location 
2. high 
3. speed
4. dest 
5. other relevant data 
- the class will be concted to the main server by permter that  will be  sand from main server
- the class will read and write massage between plane and airport controllar   
 */
#include "Word_control_center.h"

#define MAX_NUMBER_OF_PLANE


typedef struct msgStruct
{
    MSG_Q_ID response; 
    int palne_id;
    char *msg;
    int type;
} msgStruct;


/* plane that atc create  */
typedef struct dataPlane
{
    int task_id;
    Queue *msg_queue;
} dataPlane;

/* FUNCTION  */
/* init plane proc  */
void init_atc();
/* check for status of each plane  */
void check_stutus();
void create_msg(MSG_Q_ID plane_queue, int plane_id, int type);
/* handle event error */
void handle_event_error();
