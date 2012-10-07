#ifndef __NEIGHBORS_H
#define __NEIGHBORS_H

/**
\addtogroup MAChigh
\{
\addtogroup Neighbors
\{
*/
#include "openwsn.h"

//=========================== define ==========================================

#define MAXNUMNEIGHBORS            10
#define MAXPREFERENCE               2
#define BADNEIGHBORMAXRSSI        -80 //dBm
#define GOODNEIGHBORMINRSSI       -90 //dBm
#define SWITCHSTABILITYTHRESHOLD    3

//=========================== typedef =========================================
PRAGMA(pack(1));
typedef struct {
   bool             used;
   uint8_t          parentPreference;
   bool             stableNeighbor;
   uint8_t          switchStabilityCounter;
   open_addr_t      addr_64b;
   dagrank_t        DAGrank;
   int8_t           rssi;
   uint8_t          numRx;
   uint8_t          numTx;
   uint8_t          numTxACK;
   asn_t            asn;
} neighborRow_t;
PRAGMA(pack());

PRAGMA(pack(1));
typedef struct {
   uint8_t         row;
   neighborRow_t   neighborEntry;
} debugNeighborEntry_t;
PRAGMA(pack());
//this structure is used by layer debug app to debug through the network.

PRAGMA(pack(1));
typedef struct{
   uint8_t last_addr_byte;//last byte of the address; poipoi could be [0]; endianness
   int8_t rssi; //SIGNED!
   uint8_t parentPreference;
   uint8_t DAGrank;
   uint16_t asn; 
}netDebugNeigborEntry_t;
PRAGMA(pack());
//=========================== variables =======================================

//=========================== prototypes ======================================

          void          neighbors_init();
          void          neighbors_receiveDIO(OpenQueueEntry_t* msg);
          void          neighbors_updateMyDAGrankAndNeighborPreference();
          void          neighbors_indicateRx(open_addr_t* l2_src,
                                             int8_t       rssi,
                                             asn_t*       asnTimestamp);
          void          neighbors_indicateTx(open_addr_t* dest,
                                             uint8_t      numTxAttempts,
                                             bool         was_finally_acked,
                                             asn_t*       asnTimestamp);
          open_addr_t*  neighbors_KaNeighbor();
          bool          neighbors_isStableNeighbor(open_addr_t* address);
          bool          neighbors_isPreferredParent(open_addr_t* address);
          dagrank_t     neighbors_getMyDAGrank();
          uint8_t       neighbors_getNumNeighbors();
          void          neighbors_getPreferredParent(open_addr_t* addressToWrite,
                                                     uint8_t addr_type);
          //debug
          bool          debugPrint_neighbors();
          void          neighbors_getAll(neighborRow_t *nlist);//deprecated
          void          neighbors_getNetDebugInfo(netDebugNeigborEntry_t *schlist,uint8_t maxbytes);
          uint8_t       neighbors_getNumberOfNeighbors(); 
/**
\}
\}
*/
          /* piggy701: neighbour's channel mask */
          uint16_t      neighbors_getMask(open_addr_t*);
          void          neighbors_setMask(open_addr_t*, uint16_t);
          /* piggy702: get own parent addr */
          open_addr_t*  neighbors_getMaster();

#endif
