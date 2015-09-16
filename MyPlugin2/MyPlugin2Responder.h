#ifndef _MYPLUGIN2RESPONDER_H_
#define _MYPLUGIN2RESPONDER_H_

#include "VCPlugInHeaders.h"
#include "DocumentID.h"
#include "CResponder.h"
#include "CAlert.h"
#include "CPMUnknown.h"

#include "ISignalMgr.h"

#include "MyPlugin2ID.h"

class MyPlugin2Responder : public CResponder {
public:

	MyPlugin2Responder(IPMUnknown*);
	~MyPlugin2Responder();

	virtual void Respond(ISignalMgr* signalMgr);

};


#endif 