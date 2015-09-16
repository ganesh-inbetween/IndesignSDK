#include "VCPlugInHeaders.h"
#include "CAlert.h"
#include "DocumentID.h"
#include "CResponder.h"
#include "CAlert.h"
#include "CPMUnknown.h"
#include "ISignalMgr.h"
#include "IObserver.h"
#include "IDocumentSignalData.h"
#include "IDocument.h"
#include "ISpreadList.h"
#include "ISpread.h"
#include "PMString.h"
#include <stdlib.h>
#include <string.h>

#include "MyPlugin2Responder.h"
#include "MyPlugin2ID.h"


CREATE_PMINTERFACE(MyPlugin2Responder, kMyPlugin2ResponderImpl);

MyPlugin2Responder::MyPlugin2Responder(IPMUnknown* boss) :CResponder(boss)
{
};

MyPlugin2Responder::~MyPlugin2Responder()
{
};

void MyPlugin2Responder::Respond(ISignalMgr* signalMgr)
{
	ServiceID serviceTrigger = signalMgr->GetServiceID();
	switch (serviceTrigger.Get())
	{

	case kAfterNewDocSignalResponderService://96
	{
		CAlert::InformationAlert("After new document..");

		InterfacePtr<IDocumentSignalData> documentSignalData(signalMgr, UseDefaultIID());
		UIDRef docUIDRef = documentSignalData->GetDocument();
		InterfacePtr<IDocument> document(docUIDRef, UseDefaultIID());
	    /*This observer is on document level and will observer the new page item/ copy page item events
		*/
		InterfacePtr<IObserver> docObserver(docUIDRef, IID_IMYOBSERVER);
		//InterfacePtr<IObserver> myObserver(GetExecutionContextSession(), IID_IMYOBSERVER);

		if (docObserver != nil)
		{
			docObserver->AutoAttach();
			CAlert::InformationAlert("Auto attached called");
		}
		else {
			CAlert::InformationAlert("nill!!!!!");

		}
		break;
	}
	case kAfterOpenDocSignalResponderService://99
	{
		CAlert::InformationAlert("After Open document..");
		break;
	}


	case kAfterSaveDocSignalResponderService:
	{
		CAlert::InformationAlert("Document Saved..");


		InterfacePtr<IDocumentSignalData> documentSignalData(signalMgr, UseDefaultIID());
		UIDRef docUIDRef = documentSignalData->GetDocument();
		InterfacePtr<IDocument> document(docUIDRef, UseDefaultIID());

		InterfacePtr<ISpreadList> spreadList(document, UseDefaultIID());
		IDataBase* database = docUIDRef.GetDataBase();
		int32 spreadCount = spreadList->GetSpreadCount();
		
			UIDRef spreadUIDRef(database, spreadList->GetNthSpreadUID(0));
			InterfacePtr<ISpread> spread(spreadUIDRef, UseDefaultIID());

			int noOfPages = spread->GetNumPages();
			char buffer[10];
			itoa(noOfPages, buffer, 10);
			//PMString s = new PMString(buffer, -1);
			
			CAlert::InformationAlert(buffer);
		
		break;
	}
	
	}
}