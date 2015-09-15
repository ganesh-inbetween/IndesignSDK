#ifndef _MYPLUGIN2STARTUPSHUTDOWNSERVICE_H_
#define _MYPLUGIN2STARTUPSHUTDOWNSERVICE_H_

//includes
#include "VCPlugInHeaders.h"
#include "IStartupShutdownService.h"
#include "CPMUnknown.h"
#include "MyPlugin2ID.h"

#include "CAlert.h"

#include "string.h"


class MyPlugin2StartupShutdownServiceImpl : public CPMUnknown<IStartupShutdownService>
{

public:
	MyPlugin2StartupShutdownServiceImpl(IPMUnknown* boss);
	virtual ~MyPlugin2StartupShutdownServiceImpl();

	/*@Interface
	Startup() Called when app(Indesign) is starting up
	*/
	virtual void Startup();

	/*@Interface
	Shutdown() Called when app(Indesign) is shutting up
	*/
	virtual void Shutdown();

	/*messageEventDispatcher() dispatches message to HTML5 handler registered extension id
	@param msgType : the type of message eg: "Selection.Frame", "Frame.new" etc
	@param msgData : the data to be sent as part of selction
	*/
	
};


#endif //_CSDTPSTARTUPSHUTDOWNSERVICE_H_