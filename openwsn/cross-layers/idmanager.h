#ifndef __IDMANAGER_H
#define __IDMANAGER_H

/**
\addtogroup cross-layers
\{
\addtogroup IDManager
\{
*/

#include "openwsn.h"

//=========================== define ==========================================

//=========================== typedef =========================================

typedef struct {
   bool          isDAGroot;
   bool          isBridge;
   open_addr_t   my16bID;
   open_addr_t   my64bID;
   open_addr_t   myPANID;
   open_addr_t   myPrefix;
} debugIDManagerEntry_t;

//=========================== variables =======================================

//=========================== prototypes ======================================

		void         idmanager_init();
		bool         idmanager_getIsDAGroot();
		void         idmanager_setIsDAGroot(bool newRole);
		bool         idmanager_getIsBridge();
		void         idmanager_setIsBridge(bool newRole);
		open_addr_t* idmanager_getMyID(uint8_t type);
		error_t      idmanager_setMyID(open_addr_t* newID);
		bool         idmanager_isMyAddress(open_addr_t* addr);
		void         idmanager_triggerAboutBridge();
		void         idmanager_triggerAboutRoot();
		bool         debugPrint_id();

/**
\}
\}
*/

#endif
