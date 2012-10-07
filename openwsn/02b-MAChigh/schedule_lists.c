#include "openwsn.h"
#include "schedule.h"
#include "openserial.h"
#include "idmanager.h"
#include "openrandom.h"
#include "board_info.h"

#include "schedule_lists.h"
//=========================== variables =======================================

//=========================== prototypes ======================================
typedef void (* nodeSchedule)();

void node01(); //the DAGroot
void node02();
void node03();
void node04();
void node05();
void node06();
void node07();
void node08();
void node09();
void node10();

//=========================== public ==========================================

void list_init(uint8_t NODE_ID) {
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   //build array of pointers to functions
   nodeSchedule node[] = {
      node01,
      node02,
      node03,
      node04,
      node05,
      node06,
      node07,
      node08,
      node09,
      node10
   };

   //build invariant slots (ADV, NF, DIO)
   
   // slot 0 is advertisement slot
   i = 0;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_ADV,
         FALSE,
         0,
         &temp_neighbor);
      
   //build id-specific slots
   node[NODE_ID-1]();
   
   //build invariant slots again (ADV, SER, NF, DIO)
   
   // slot 4 is SERIALRX
   i = 4;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);

   // slot 5 is MORESERIALRX
   i = 5;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_MORESERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   // Noise Floor Probe
   /* piggy903: only enable blacklisting in non-DAGroot motes 
   if(NODE_ID==DEBUG_MOTEID_MASTER){
   i = 6; 
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 7; 
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_MORESERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   }
   else */
   {
   i = 6; 
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_NF,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 7; 
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_NF,
         FALSE,
         0,
         &temp_neighbor);
   }
   
   //for RPL DIOs?
   i = 8;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[0]          = 0xff;
   temp_neighbor.addr_64b[1]          = 0xff;
   temp_neighbor.addr_64b[2]          = 0xff;
   temp_neighbor.addr_64b[3]          = 0xff;
   temp_neighbor.addr_64b[4]          = 0xff;
   temp_neighbor.addr_64b[5]          = 0xff;
   temp_neighbor.addr_64b[6]          = 0xff;
   temp_neighbor.addr_64b[7]          = 0xff;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   // slot 9 is SERIALRX
   i = 9;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
}

//DAGroot
void node01(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   // slot 1 is shared TXRX, but with specific neighbour rather than anycast
   i = 1;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_2;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   // slot 2 is shared TXRX, but with specific neighbour rather than anycast
   i = 2;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_3;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);   
   
   i = 3;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_4;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);  
}

void node02(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   // slot 1 is shared TXRX, but with specific neighbour rather than anycast
   i = 1;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_MASTER;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
 
   i = 2;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_5;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);     

   i = 3;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_6;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);   
}

void node03(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_7;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_MASTER;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 3;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_8;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);  
}

void node04(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_9;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_10;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);   
   
   i = 3;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_MASTER;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
}

void node05(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_2;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 3;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
}

void node06(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 3;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_2;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
}

void node07(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_3;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 3;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
}

void node08(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 3;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_3;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
}

void node09(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_4;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 3;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
}

void node10(){
   uint8_t     i;
   open_addr_t temp_neighbor;
   
   i = 1;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 2;
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   temp_neighbor.type             = ADDR_64B;
   temp_neighbor.addr_64b[6]    = 0xED;
   temp_neighbor.addr_64b[7]    = DEBUG_MOTEID_4;
   schedule_addActiveSlot(i,
         CELLTYPE_TXRX,
         FALSE,
         0,
         &temp_neighbor);
   
   i = 3;//place holder
   memset(&temp_neighbor,0,sizeof(temp_neighbor));
   schedule_addActiveSlot(i,
         CELLTYPE_SERIALRX,
         FALSE,
         0,
         &temp_neighbor);
}