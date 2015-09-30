#include "VCPlugInHeaders.h"

#include "ISubject.h"
#include "MyPlugin2Observer.h"
#include "MyPlugin2ID.h"

#include "CAlert.h"

#include "GenericID.h"

CREATE_PMINTERFACE(MyPlugin2Observer, kMyPlugin2ObserverImpl);



MyPlugin2Observer::~MyPlugin2Observer()
{
};

void  MyPlugin2Observer::AutoAttach()
{
	do{
		InterfacePtr<ISubject> subject(this, IID_ISUBJECT);
		if (subject != nil)
		{
			if (subject->IsAttached(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_IMYOBSERVER) == kFalse)
			{
				subject->AttachObserver(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_IMYOBSERVER);
			}
		}
	//	CAlert::InformationAlert("AUTO Attach");
	} while (false);
}



void  MyPlugin2Observer::AutoDetach()
{
	do {
		InterfacePtr<ISubject> subject(this, UseDefaultIID());

		if (subject != nil)
		{
			if (subject->IsAttached(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_IMYOBSERVER) == kTrue)
			{
				subject->DetachObserver(ISubject::kRegularAttachment, this, IID_IHIERARCHY_DOCUMENT, IID_IMYOBSERVER);
			}
		}

		CAlert::InformationAlert("AUTO Detach");
	} while (false);
}



void MyPlugin2Observer::Update(const ClassID& theChange, ISubject* theSubject,
	const PMIID& protocol, void* changedBy)
{

	//CAlert::InformationAlert("Update");
}