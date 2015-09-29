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
#include "IHierarchy.h"
#include <stdlib.h>
#include <string.h>
#include "UIDList.h"
#include "IFrameType.h"
#include "IIDXMLElement.h"
#include "IXMLUtils.h"
#include "XMLReference.h"
#include "IXMLReferenceData.h"
#include "textiterator.h"

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

		InterfacePtr<ISpreadList> spreadList(document, UseDefaultIID()); // GET SPREAD LIST USING DOCUMENT POINTER
		IDataBase* database = docUIDRef.GetDataBase(); // GET DATABASE OF DOCUMENT.
		int32 spreadCount = spreadList->GetSpreadCount();
		
			UIDRef spreadUIDRef(database, spreadList->GetNthSpreadUID(0));
			InterfacePtr<ISpread> spread(spreadUIDRef, UseDefaultIID());

			int noOfPages = spread->GetNumPages();// get number of pages
			PMString str1 = "Number of pages - ";
			str1.AppendNumber(noOfPages);
			CAlert::InformationAlert(str1);
		

			UIDList itemsOnPage(database);
			const bool16 bIncludePage = kFalse;
			const bool16 bIncludePasteboard = kFalse;
			spread->GetItemsOnPage(0, &itemsOnPage, bIncludePage,
				bIncludePasteboard);

			int itemCount = itemsOnPage.Length(); // get number of items on page
			PMString str2 = "Number of items on page -";
			str2.AppendNumber(itemCount);
			CAlert::InformationAlert(str2);


			UIDRef pageitemUIDRef = itemsOnPage.GetRef(0);
			InterfacePtr<IFrameType> frameType(pageitemUIDRef, UseDefaultIID());

			//-------------------------------------------------------------------------------------------------------------
			                                                 // GET XML REFERENCE DATA USING PAGEITEM UID REF.
			InterfacePtr<IXMLReferenceData> referenceData (Utils<IXMLUtils>()->QueryXMLReferenceData(pageitemUIDRef, kFalse));

			XMLReference xmlRef = referenceData->GetReference(); //GET XMLREFERECE USING REFERENCE DATA.

			InterfacePtr<IIDXMLElement> element(xmlRef.Instantiate());     //INSATATIATE XML ELEMENT USING XML REFERENCE. 
			                                                        
			PMString xmltagChildCount = "Child count-";            // XML CHILD COUNT.
			xmltagChildCount.AppendNumber(element->GetChildCount());
			CAlert::InformationAlert(xmltagChildCount);
		                                                     // GET TAG NAMES.
			PMString xmltagStringValue = "XML tag string-";
			WideString xmlTagString = element->GetTagString();
			xmltagStringValue.Append(xmlTagString + "->");

			for (int childCount = 0; childCount < element->GetChildCount(); childCount++) {
				XMLReference currentChildReference = element->GetNthChild(childCount);
				InterfacePtr<IIDXMLElement> currentChild(currentChildReference.Instantiate());
				WideString currentTagString = currentChild->GetTagString();
				xmltagStringValue.Append(currentTagString + ",");
			}
		//-------------------------------------------------------------------------------------------------
			InterfacePtr<ITextModel> textModel(Utils<IXMLUtils>()->QueryTextModel(element));
		                                                      	// FRAME CONTENT AND FRAME CONTENT LENGTH.
			PMString textFrameContentLength = "frame Contents length-";
			textFrameContentLength.AppendNumber(textModel->TotalLength());
			CAlert::InformationAlert(textFrameContentLength);
			
			TextIterator begin(textModel, 0);
			TextIterator end(textModel,textModel->TotalLength());
			WideString ws;
			ws.reserve(textModel->TotalLength());
			std::copy(begin, end, std::back_inserter(ws));
		

			PMString textFrameContents = "------frame Contents------\n \n";
			textFrameContents.Append(ws);
			CAlert::InformationAlert(textFrameContents);

		//-------------------------------------------------------------------------------------------------
			PMString textFrameType = "Is text frame-";   // TYPE OF TEXT FRAME
			bool isTextFrame = frameType->IsTextFrame();
			if (isTextFrame) {
				textFrameType.Append("YES");
			
			}
			else {
				textFrameType.Append("NO");
			}
		 //------------------------------------------------------------------------------------------------     
			
			CAlert::InformationAlert(textFrameType);
			CAlert::InformationAlert(xmltagStringValue);
					
					
		break;
	}
	
	}
};

void MyPlugin2Responder::VisitChildren(IHierarchy* parent) {
	int childCount = parent->GetChildCount();
	PMString str = "";
	str.AppendNumber(childCount);
	CAlert::InformationAlert(str);


}