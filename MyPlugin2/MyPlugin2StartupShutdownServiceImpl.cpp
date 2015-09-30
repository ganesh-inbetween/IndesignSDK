#include "VCPlugInHeaders.h"
#include "MyPlugin2StartupShutdownServiceImpl.h"
#include "MyPlugin2Observer.h"
#include "Myplugin2SelectionObserver.h"
#include "CAlert.h"
#include "IObserver.h"
#include "MyPlugin2ID.h"

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
	
	InterfacePtr<IObserver> mySelectionObserver(GetExecutionContextSession(), IID_IMYSELECTIONOBSERVER);

	if (mySelectionObserver != nil)
	{
		CAlert::InformationAlert("Auto attached called for active selection");
		mySelectionObserver->AutoAttach();
	
	}
	else {
		CAlert::InformationAlert("nill!!!!!");

	}

}


void MyPlugin2StartupShutdownServiceImpl::Shutdown()
{

	CAlert::InformationAlert("Start up servies stopped");

}