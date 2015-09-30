#ifndef _MYPLUGIN2SELECTIONOBSERVER_H_
#define _MYPLUGIN2SELECTIONOBSERVER_H_

#include "VCPlugInHeaders.h"
#include "MyPlugin2SelectionObserver.h"
#include "CPMUnknown.h"
#include "MyPlugin2ID.h"

#include "CAlert.h"
#include "SelectionObserver.h"

#include "ISubject.h"
#include "GenericID.h"
#include "IPMUnknown.h"
#include "CObserver.h"


class MyPlugin2SelectionObserver : public ActiveSelectionObserver
{
public:

	MyPlugin2SelectionObserver(IPMUnknown* boss);

	
	virtual ~MyPlugin2SelectionObserver();


	virtual void HandleSelectionChanged(const ISelectionMessage* message);

	virtual void HandleSelectionAttributeChanged(const ISelectionMessage* message);

	virtual void AutoAttach();

};
#endif