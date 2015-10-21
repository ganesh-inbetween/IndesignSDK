#include "VCPlugInHeaders.h"

#include "ISubject.h"
#include "SelectionObserver.h"
#include "MyPlugin2SelectionObserver.h"
#include "MyPlugin2ID.h"

#include "ISelectionUtils.h"
#include "CAlert.h"
#include "Utils.h"
#include "CObserver.h"
#include "GenericID.h"
#include "CPMUnknown.h"
#include "ITextSelectionSuite.h"
#include "ITextTarget.h"
#include "IXMLUtils.h"
#include "IRangeData.h"
#include "RangeData.h"
#include "IIntegratorTarget.h"
#include "textiterator.h"
#include "ITextModel.h"
#include "IXMLReferenceData.h"
#include "XMLReference.h"
#include "IIDXMLElement.h"
#include "ITableSelectionSuite.h"
#include "ITableLayout.h"
#include "ITableModel.h"
#include "ITableFrame.h"
#include "IFrameType.h"
#include "IAppearanceSuite.h"
#include "IControlView.h"
#include "IGraphicAttributeSuite.h"
#include "IXMLAttributeCommands.h"

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
void MyPlugin2SelectionObserver::HandleSelectionChanged(const ISelectionMessage* selectionMessage)
{
	// get selection manager for active selection.
	ISelectionManager* iSelectionManager = Utils<ISelectionUtils>()->GetActiveSelection();
	return;
	//get pointer to textSelectionSuite using selection manager OR fCurrentSelection.
	InterfacePtr<ITextSelectionSuite> iTextSelectionSuite(iSelectionManager, UseDefaultIID());
	CAlert::InformationAlert("Selection** changed..");
	if (iTextSelectionSuite) {
		//get pointer to integrator target text using textSelectionSuite.
		//Use to  Return a list of interfaces from the "concrete selection"
		InterfacePtr<const IIntegratorTarget> iIntegratorTarget_text(iTextSelectionSuite, UseDefaultIID());
		if (iIntegratorTarget_text == nil)
			return;
		RangeData rangeData(0, RangeData::kLeanForward);
		UIDRef textRef;
		PMString tagName;
		PMString childCountString = "xml child count-";
		PMString tagUIDString = "UID of TAG -";
		UID tagUID;
		TextIndex startPosXML = 0, endPosXML = 0;
		int startIndexSelection;
		int endIndexSelection;
		// Return a list of interfaces from the "concrete selection"
		//auto_ptr automatically makes clean up of objects.
		std::auto_ptr<IIntegratorTarget::TargetSuiteCollection> selectionSuites_text(iIntegratorTarget_text->GetTarget(ITextTarget::kDefaultIID));
		for (IIntegratorTarget::TargetSuiteCollection::size_type i = 0; i < selectionSuites_text->size(); i++)
		{
			//Get target text.
			ITextTarget* target = (ITextTarget*)selectionSuites_text->at(i).get();
			if (!target)
				continue;
			// extract range from target text.
			rangeData = target->GetRange();
			
			// get start and end index of range selected.
			 startIndexSelection = rangeData.Start(nil);
			 endIndexSelection = rangeData.End();
		

			// get text model for target text.
			InterfacePtr<ITextModel>textModel(target->QueryTextModel());
			
			// get UIDRef of text model.
			textRef	= target->GetTextModel();

			// query xml reference data for text model.
			IXMLReferenceData *xmlReferenceData = Utils<IXMLUtils>()->QueryXMLReferenceData(textRef);
			if (xmlReferenceData)
			{
				// get xml reference from xml reference data.
				XMLReference xmlRef = xmlReferenceData->GetReference();
			
				// obtain xml element from xml reference
				InterfacePtr<IIDXMLElement> xmlElement(xmlRef.Instantiate());
				if (xmlElement != nil) {
					childCountString.AppendNumber(xmlElement->GetChildCount());
					XMLReference childRef = xmlElement->GetNthChild(0);
					InterfacePtr<IIDXMLElement> childXMLElement(childRef.Instantiate());
					if (childXMLElement != nil){
						tagUID = childXMLElement->GetTagUID();
						tagName = childXMLElement->GetTagString();
						Utils<IXMLUtils>()->GetElementMarkerPositions(childXMLElement, &startPosXML, &endPosXML);
					}
		    	}

			}
							
		} // for end
		int length = rangeData.Length();
		if (length >= 1) {
			PMString textFrameContentLength = "selected content length-";
			textFrameContentLength.AppendNumber(length);
			PMString srtPosString = "Start Position XML tag-";
			PMString endPosString = "End postion XML tag-";
			PMString srtPosSelString = "Start Position of Selection-";
			PMString endPosSelString = "End postion Selection-";
			srtPosString.AppendNumber(startPosXML);
			endPosString.AppendNumber(endPosXML);
			srtPosSelString.AppendNumber(startIndexSelection);
			endPosSelString.AppendNumber(endIndexSelection);
			CAlert::InformationAlert(textFrameContentLength);
			CAlert::InformationAlert(childCountString);
			CAlert::InformationAlert(tagName);
			CAlert::InformationAlert(srtPosString);
			CAlert::InformationAlert(endPosString);
			CAlert::InformationAlert(srtPosSelString);
			CAlert::InformationAlert(endPosSelString);

			if (startPosXML <= startIndexSelection && endPosXML >= endIndexSelection) {
				CAlert::InformationAlert("Selection inside tag- "+tagName);
			}
			else
			{
				CAlert::WarningAlert("Selection not inside tag- " + tagName);
			}
		}
	}
	// --------:: Table selection ::---------
	InterfacePtr<ITableSelectionSuite> iTableSelectionSuite(fCurrentSelection, UseDefaultIID());
	if (iTableSelectionSuite == nil)
		return;

	InterfacePtr<const IIntegratorTarget> iIntegratorTarget_table(iTableSelectionSuite, UseDefaultIID());
	if (iIntegratorTarget_table == nil)
		return;

	UIDRef 	tableUIDRef;
	GridArea tableGridArea;
	PMString PMRowCount = "Total no of rows-";
	PMString PMColCount = "Total no of cols-";
	std::auto_ptr<IIntegratorTarget::TargetSuiteCollection> selectionSuites_table(iIntegratorTarget_table->GetTarget(ITableTarget::kDefaultIID));
	for (IIntegratorTarget::TargetSuiteCollection::size_type i = 0; i < selectionSuites_table->size(); i++)
	{
		ITableTarget* target = (ITableTarget*)selectionSuites_table->at(i).get();
		if (!target)
			continue;
		tableUIDRef = target->GetModel();
		if (tableUIDRef != UIDRef(nil, kInvalidUID))
		{
			CAlert::WarningAlert("Table selection occured");
			tableGridArea = target->GetRange();
		}
		InterfacePtr<ITableModel>tableModel(target->QueryModel());
		if (tableModel != nil) {
			RowRange totalRows = tableModel->GetTotalRows();
			ColRange totalCols = tableModel->GetTotalCols();
			int rowCount = totalRows.count;
			int colCount = totalCols.count;
			PMRowCount.AppendNumber(rowCount);
			PMColCount.AppendNumber(colCount);
			CAlert::InformationAlert(PMRowCount);
			CAlert::InformationAlert(PMColCount);

			InterfacePtr<ITableLayout> tableLayout(tableModel, UseDefaultIID());
			if (tableLayout == nil) {
				break;
			}
			CAlert::InformationAlert("table layout present");
			ITableLayout::frame_iterator frameIter = tableLayout->begin_frame_iterator();
			CAlert::InformationAlert("Frame Iterator ppresent");
			
			CAlert::InformationAlert("Frame Iterator present");
			
			InterfacePtr<ITableFrame> tableFrame(frameIter->QueryFrame());
			CAlert::InformationAlert("table frame ppresent");
			if (tableFrame == nil){
				break;
			}
			CAlert::InformationAlert("table frame present");
			UIDRef tableContainerUIDRef = tableFrame->GetFrameRef();
			if (tableContainerUIDRef == nil){
				break;
			}
			CAlert::InformationAlert("table container UIDRef present");
			InterfacePtr<IFrameType> frameType(tableContainerUIDRef, UseDefaultIID());
			//if (frameType == nil) {
				//break;
			//}
			CAlert::InformationAlert("container frame present");
			PMString textFrameType = "Is container , text frame-";   // TYPE OF TEXT FRAME
			
		//	bool isTextFrame = frameType->IsTextFrame();
			CAlert::InformationAlert("Is text frame success");

			if (true) {
				textFrameType.Append("YES");
				CAlert::InformationAlert(textFrameType);
			}
			else {
				textFrameType.Append("NO");
				CAlert::InformationAlert(textFrameType);
			}
		}
	}
	
};

void MyPlugin2SelectionObserver::HandleSelectionAttributeChanged(const ISelectionMessage* iSelectionMessage) 
{
	return;
	//CAlert::InformationAlert("Selection Attribute changed..");
	if(iSelectionMessage->WasSuiteAffected(IID_IAPPEARANCESUITE)){
	//	CAlert::InformationAlert("appearacne suite");
	}
	if (iSelectionMessage->WasSuiteAffected(IID_IGRAPHICATTRIBUTESUITE)){
		//CAlert::InformationAlert("Graphic suite");
	}
	if (iSelectionMessage->WasSuiteAffected(IID_IFORMFIELDSUITE)){
	//	CAlert::InformationAlert("form Field suite");
	}

	InterfacePtr<IControlView> controlView(this, IID_ICONTROLVIEW);
	if (controlView !=nil) {
		CAlert::InformationAlert("controlView found");
	   
	}


};

void MyPlugin2SelectionObserver::AutoAttach()
{
	CAlert::InformationAlert("in selection auto attach..");
	ActiveSelectionObserver::AutoAttach();
}