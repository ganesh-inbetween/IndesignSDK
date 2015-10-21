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
#include <IStyleNameTable.h>
#include <IStyleGroupManager.h>
#include "IApplication.h"
#include "IDocumentList.h"
#include "IActiveContext.h"
#include "ICommand.h"
#include "IPanelControlData.h"
#include "IPersistUIDData.h"
#include "ICommandInterceptor.h"
#include "TextPanelID.h"

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
			//if (subject->IsAttached(ISubject::kRegularAttachment, this, IID_ISTYLEINFO, IID_IMYOBSERVER) == kFalse)
			if (subject->IsAttached(ISubject::kRegularAttachment, this, IID_ITEXTATTROBSERVERDATA, IID_IMYOBSERVER) == kFalse)
			{
				CAlert::InformationAlert("observer attached");
				//subject->AttachObserver(ISubject::kRegularAttachment, this, IID_ISTYLEINFO, IID_IMYOBSERVER);
				subject->AttachObserver(ISubject::kRegularAttachment, this, IID_ITEXTATTROBSERVERDATA, IID_IMYOBSERVER);
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
			    	//WideString temp(currentStyle.c_str()); // widestring accept string of type Char * so convert it.
					newStylename.Append(currentStyle.c_str());

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

		InterfacePtr<IControlView> controlView(theSubject, UseDefaultIID());

		InterfacePtr<IPanelControlData> panelControlData(this, UseDefaultIID());

		InterfacePtr<ICommandInterceptor> cmdInterceptor((IPMUnknown *)changedBy, UseDefaultIID());
		
	//	ICommandInterceptor::InterceptResult result =  cmdInterceptor->InterceptProcessCommand(styleCmd);

		if (controlView != nil) {
		
			CAlert::InformationAlert("control view presetn");
		}

		InterfacePtr<IUIDData> iUIDData(styleCmd, IID_IUIDDATA);

		if (iUIDData != nil) {

			CAlert::InformationAlert("iUIDData presetn");
		}
		
		if (panelControlData != nil) {

			CAlert::InformationAlert("iUIDData present");
		}
		if (styleCmd->GetCommandState() == ICommand::CommandState::kNotDone){
	
			CAlert::InformationAlert("command not done");
		}

		else if (styleCmd->GetCommandState() == ICommand::CommandState::kDone){

			CAlert::InformationAlert("Command done");
		}

		else if (styleCmd->GetCommandState() == ICommand::CommandState::kDoneDynamic){
			CAlert::InformationAlert("command done dynamic");

		}
		if (styleCmd) {

			InterfacePtr<IStyleInfo> cmdStyleInfo(styleCmd, UseDefaultIID());
			
			InterfacePtr<IUIDData> uidData(styleCmd, IID_IUIDDATA);

			InterfacePtr<IApplication> app(GetExecutionContextSession()->QueryApplication());
			
			InterfacePtr<IDocumentList> docList(app->QueryDocumentList());

			IDocument *doc = GetExecutionContextSession()->GetActiveContext()->GetContextDocument();
			
			UIDRef ws = doc->GetDocWorkSpace();

			InterfacePtr<IStyleGroupManager> paraStyleNameMngr(ws, IID_IPARASTYLEGROUPMANAGER);

			InterfacePtr<IStyleNameTable> paraStyleNameTable(ws, IID_IPARASTYLENAMETABLE_OBSOLETE); 

			int noOfStyles = paraStyleNameTable->GetNumStyles();

			PMString testStyle = "G@nesh";

			UID pStyleUID = paraStyleNameMngr->FindByName(testStyle);

			if (pStyleUID != kInvalidUID) {
				IDataBase* db = ::GetDataBase(doc);

				UIDRef styleRef(db, pStyleUID);

				InterfacePtr<ICommand> newStyleCmd(CmdUtils::CreateCommand(kRenameStyleCmdBoss));

				InterfacePtr<IStyleInfo> styleInfo(styleRef, IID_ISTYLEINFO);

				if (styleInfo != nil)
				{
					PMString newStyleName = "Ganesh";
					styleInfo->SetName(newStyleName);
				}

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