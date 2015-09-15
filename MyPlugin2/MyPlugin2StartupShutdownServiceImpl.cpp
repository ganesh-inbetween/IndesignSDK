#include "VCPlugInHeaders.h"
#include "MyPlugin2StartupShutdownServiceImpl.h"
#include "MyPlugin2ID.h"
#include "MyPlugin2Observer.h"
#include "CAlert.h"
#include "IObserver.h"


CREATE_PMINTERFACE(MyPlugin2StartupShutdownServiceImpl, kMyPlugin2StartupShutdownServiceImpl);

MyPlugin2StartupShutdownServiceImpl::MyPlugin2StartupShutdownServiceImpl(IPMUnknown *boss) :CPMUnknown<IStartupShutdownService>(boss)
{
}

MyPlugin2StartupShutdownServiceImpl::~MyPlugin2StartupShutdownServiceImpl()
{
}

void MyPlugin2StartupShutdownServiceImpl::Startup()
{

	CAlert::InformationAlert("Start up servies started");

	InterfacePtr<IObserver> myObserver(GetExecutionContextSession(), IID_IMYOBSERVER);
	
	if (myObserver != nil)
	{
		myObserver->AutoAttach();
		CAlert::InformationAlert("Auto attached called");
	}
	else {
		CAlert::InformationAlert("nill!!!!!");
	
	}
}

void MyPlugin2StartupShutdownServiceImpl::Shutdown()
{

	CAlert::InformationAlert("Start up servies started");

}