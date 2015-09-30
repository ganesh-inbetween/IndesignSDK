#include "VCPlugInHeaders.h"

#include "ISubject.h"
#include "SelectionObserver.h"
#include "MyPlugin2SelectionObserver.h"
#include "MyPlugin2ID.h"

#include "CAlert.h"

#include "CObserver.h"
#include "GenericID.h"
#include "CPMUnknown.h"

CREATE_PMINTERFACE(MyPlugin2SelectionObserver, kMyPlugin2SelectionObserverImpl)

/* Constructor
*/
MyPlugin2SelectionObserver::MyPlugin2SelectionObserver(IPMUnknown* boss) :ActiveSelectionObserver(boss, IID_IMYSELECTIONOBSERVER)
{
}

/* Destructor
*/
MyPlugin2SelectionObserver::~MyPlugin2SelectionObserver()
{
};

/*
*/
void MyPlugin2SelectionObserver::HandleSelectionChanged(const ISelectionMessage* message)
{
	CAlert::InformationAlert("Selection changed..");
};

void MyPlugin2SelectionObserver::HandleSelectionAttributeChanged(const ISelectionMessage* message) 
{
	CAlert::InformationAlert("Selection Attribute changed..");
};

void MyPlugin2SelectionObserver::AutoAttach()
{
	CAlert::InformationAlert("in selection auto attach..");
	ActiveSelectionObserver::AutoAttach();
}