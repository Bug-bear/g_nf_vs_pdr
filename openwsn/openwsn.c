/**
\brief General OpenWSN definitions

\author Thomas Watteyne <watteyne@eecs.berkeley.edu>, August 2010
\author Ankur Mehta <mehtank@eecs.berkeley.edu>, September 2010
*/

#include "openwsn.h"
//l7
#include "layerdebug.h"
//#include "rrube.h"
//#include "rheli.h"
#include "rinfo.h"
//#include "rxl1.h"
#include "rex.h"
#include "rt.h"
#include "rwellknown.h"
#include "rleds.h"
#include "rreg.h"
//#include "heli.h"
//#include "imu.h"
#include "ohlone.h"
#include "tcpecho.h"
#include "tcpinject.h"
#include "tcpprint.h"
#include "udpecho.h"
#include "udpinject.h"
#include "udpprint.h"
//#include "udprand.h"
//#include "udpstorm.h"
#include "bbk.h"
//#include "hdl.h"
//l4
#include "opencoap.h"
#include "openudp.h"
#include "opentcp.h"
//l3b
#include "icmpv6rpl.h"
#include "icmpv6router.h"
#include "icmpv6echo.h"
#include "icmpv6.h"
#include "forwarding.h"
//l3a
#include "iphc.h"
#include "openbridge.h"
//l2b
#include "neighbors.h"
#include "res.h"
#include "schedule.h"
#include "noiseprobe.h" //noise floor module

//l2a
#include "IEEE802154E.h"
//cross-layer
#include "idmanager.h"
#include "openqueue.h"
#include "openrandom.h"
#include "opentimers.h"
// drivers
#include "openserial.h"


//=========================== variables =======================================

//=========================== prototypes ======================================

void openwsn_init();

//=========================== public ==========================================

void openwsn_init() {
   // drivers
   openserial_init();
   
   // stack
   // cross-layer
   idmanager_init(); // call first since initializes e.g. EUI64
   openqueue_init();
   openrandom_init();
   opentimers_init();
   // 02a-TSCH
   ieee154e_init();
   // 02b-RES
   schedule_init();
   res_init();
   neighbors_init(); 
   nf_init(); //noise floor module
   // 03a-IPHC
   openbridge_init();
   iphc_init();
   // 03b-IPv6
   forwarding_init();
   icmpv6_init();
   icmpv6echo_init();
   icmpv6router_init();
   icmpv6rpl_init();
   // 04-TRAN
   opentcp_init();
   openudp_init();
   opencoap_init(); // initialize before any of the CoAP clients
   // 07-App
   //--CoAP
   //rwellknown_init();
   //rreg_init();
   //rinfo_init();
   //rleds_init();
   //rt_init();
   //rex_init();
   //rheli_init();
   //rrube_init();
   //rxl1_init();
   //layerdebug_init();
   //--UDP
   /*udpecho_init();
   udpinject_init();
   udpprint_init();*/
   //udprand_init();
   //udpstorm_init();
   //--TCP
   /*ohlone_init();
   tcpecho_init();
   tcpinject_init();
   tcpprint_init();*/
   //--misc
   //heli_init();
   //imu_init();
   
   //bbk_init();
   //hdl_init();
}

//=========================== private =========================================
