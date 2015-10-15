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
#include "widgetID.h"
#include "CObserver.h"
#include "ITextAttributes.h"
#include "IUIDData.h"
#include "UIDList.h"
#include <boost\regex.hpp>
#include <boost\regex.h>
#include <string.h>

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
	CAlert::InformationAlert("update called");
	if (theChange == kCreateCharStyleCmdBoss)
	{
		CAlert::InformationAlert("Char Style Created");
		InterfacePtr<ICommand> styleCmd((IPMUnknown*)changedBy, UseDefaultIID());
		IDataBase* db = ::GetDataBase(theSubject);


		if (styleCmd) {

			InterfacePtr<IStyleInfo> cmdStyleInfo(styleCmd, UseDefaultIID());
			InterfacePtr<IUIDData> styleUIDData(theSubject, UseDefaultIID());
			if (cmdStyleInfo) {
				
				CAlert::InformationAlert("uid data found");
				CAlert::InformationAlert(cmdStyleInfo->GetName());
			}
			else{
				CAlert::InformationAlert("cmdStyleInfo nil");
			}
		}
		else {
			CAlert::InformationAlert("style cmd nil");
		}
	}
	else if (theChange == kCreateParaStyleCmdBoss)
	{
		CAlert::InformationAlert("Para Style Created");
	}
	else if (theChange == kEditStyleGroupCmdBoss) {

		CAlert::InformationAlert("style group edited");
	} 
	else if (theChange == kEditTextStyleCmdBoss) { // Style edited change occurred. 

		CAlert::InformationAlert("style edited"); 
		InterfacePtr<ICommand> styleCmd((IPMUnknown*)changedBy, UseDefaultIID()); //Get Command which changed the style.
		InterfacePtr<IControlView> controlView(theSubject, UseDefaultIID());

		if (styleCmd) { // If command found.

			InterfacePtr<IStyleInfo> cmdStyleInfo(styleCmd, UseDefaultIID()); // Get style Information related to command.
			InterfacePtr<IUIDData> styleUIDData(theSubject, UseDefaultIID());
						
			if (cmdStyleInfo) {   // If style Information found
				PMString styleName = cmdStyleInfo->GetName();
				styleName.StripWhiteSpace();
				std::string currentStyle(styleName.GetPlatformString()); // convert style name to string type
				boost::regex re("[^A-Za-z0-9_-]"); // regular ex to check special symbols.
				bool result = regex_search(currentStyle, re); // check if style name contains special symbols.

				if (result){ // If special symbol found.
					CAlert::InformationAlert("Style Name contains special Symbols, hence will replace it by (_)" );
					currentStyle = regex_replace(currentStyle, re, "_");
					PMString newStylename;
			    	WideString temp(currentStyle.c_str()); // widestring accept string of type Char * so convert it.
					newStylename.Append(temp);
					cmdStyleInfo->SetName(newStylename);
					CAlert::InformationAlert(newStylename);
				}
				else{
					CAlert::InformationAlert("special symbol not found");
				}
			}
		}

		
	}
	else if (theChange == kRenameStyleCmdBoss)    // Style renamed change occurred.
	{
		CAlert::InformationAlert("Style Renamed");
		InterfacePtr<ICommand> styleCmd((IPMUnknown*)changedBy, UseDefaultIID());
		IDataBase* db = ::GetDataBase(theSubject);
	  
		if (styleCmd) {
			InterfacePtr<IStyleInfo> cmdStyleInfo(styleCmd, UseDefaultIID());
			CAlert::InformationAlert("style cmd found");
			if (cmdStyleInfo) {
			   CAlert::InformationAlert("uid data found");
		    }
		   else{
			   CAlert::InformationAlert("cmdStyleInfo nil");
		    }
		}
		else {
			CAlert::InformationAlert("style cmd nil");
		}
	}
}