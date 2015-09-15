#ifndef _MYPLUGIN2OBSERVER_H_
#define _MYPLUGIN2OBSERVER_H_

#include "VCPlugInHeaders.h"
#include "MyPlugin2Observer.h"
#include "CPMUnknown.h"
#include "MyPlugin2ID.h"

#include "CAlert.h"
#include "CObserver.h"
#include "ISubject.h"
#include "string.h"

#include "GenericID.h"

class MyPlugin2Observer : public CObserver
{
public:
	
	MyPlugin2Observer(IPMUnknown* boss) : CObserver(boss) {};

	
	virtual ~MyPlugin2Observer();

	/**
	Called by the application to allow the observer to attach to the subjects
	to be observed, in this case the dialog's widgets.
	*/
	virtual void AutoAttach();

	/** Called by the application to allow the observer to detach from the subjects being observed. */
	virtual void AutoDetach();

	/**
	Called by the host when the observed widgets change.
	@param theChange specifies the class ID of the change to the subject. Frequently this is a command ID.
	@param theSubject points to the ISubject interface for the subject that has changed.
	@param protocol specifies the ID of the changed interface on the subject boss.
	@param changedBy points to additional data about the change. Often this pointer indicates the class ID of the command that has caused the change.
	*/
	virtual void Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy);

	

};
#endif 