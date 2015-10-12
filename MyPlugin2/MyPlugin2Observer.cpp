#include "VCPlugInHeaders.h"

#include "ISubject.h"
#include "MyPlugin2Observer.h"
#include "MyPlugin2ID.h"
#include "IPageSetupPrefs.h"
#include "CAlert.h"
#include "IStyleInfo.h"
#include "GenericID.h"
#include "ITextControlData.h"
#include "IWidgetUtils.h"
#include "utils.h"
#include "BehaviorUIID.h"
#include "IWidgetParent.h"
#include "IStringData.h"
#include "IControlView.h"

CREATE_PMINTERFACE(MyPlugin2Observer, kMyPlugin2ObserverImpl);



MyPlugin2Observer::~MyPlugin2Observer()
{
};

/*void  MyPlugin2Observer::AutoAttach()
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

	} while (false);
}*/

void  MyPlugin2Observer::AutoAttach()
{
	do{
		CAlert::InformationAlert("auto attached called * ");
		InterfacePtr<ISubject> subject(this, IID_ISUBJECT);
		if (subject != nil)
		{
			CAlert::InformationAlert("auto attached called subject");
			if (subject->IsAttached(ISubject::kRegularAttachment, this, IID_ISTYLEINFO, IID_IMYOBSERVER) == kFalse)
			{
				CAlert::InformationAlert("observer attached");
				subject->AttachObserver(ISubject::kRegularAttachment, this, IID_ISTYLEINFO, IID_IMYOBSERVER);
			}
		}

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
	if (theChange == kCreateCharStyleCmdBoss)
	{
		CAlert::InformationAlert("Char Style Created");
	}
	else if (theChange == kCreateParaStyleCmdBoss)
	{
		CAlert::InformationAlert("Para Style Created");
	}
	else if (theChange == kRenameStyleCmdBoss)
	{
		CAlert::InformationAlert("Style Renamed");
		InterfacePtr<IControlView> view(theSubject, UseDefaultIID());
		if (view && view->GetWidgetID() == kPreferencesDialogWidgetID)
			CAlert::InformationAlert("aet");
	}

}