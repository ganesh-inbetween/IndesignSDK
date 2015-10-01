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
	
	ISelectionManager* iSelectionManager = Utils<ISelectionUtils>()->GetActiveSelection();

	InterfacePtr<ITextSelectionSuite> iTextSelectionSuite(iSelectionManager, UseDefaultIID());
	if (iTextSelectionSuite) {
		//CAlert::InformationAlert("Text is selected..");
		InterfacePtr<const IIntegratorTarget> iIntegratorTarget_text(iTextSelectionSuite, UseDefaultIID());
		if (iIntegratorTarget_text == nil)
			return;
		RangeData rangeData(0, RangeData::kLeanForward);
		UIDRef textRef;
		std::auto_ptr<IIntegratorTarget::TargetSuiteCollection> selectionSuites_text(iIntegratorTarget_text->GetTarget(ITextTarget::kDefaultIID));
		for (IIntegratorTarget::TargetSuiteCollection::size_type i = 0; i < selectionSuites_text->size(); i++)
		{
			ITextTarget* target = (ITextTarget*)selectionSuites_text->at(i).get();
			if (!target)
				continue;

			rangeData = target->GetRange();
			
			//int startIndex = rangeData.Start();
			//int endIndex = rangeData->GetEnd();
			//int length = rangeData.Length();

			InterfacePtr<ITextModel>textModel(target->QueryTextModel());
			
			
				//PMString textFrameContentLength = "selected content length-";
				//textFrameContentLength.AppendNumber(textModel->TotalLength());
			//	CAlert::InformationAlert(textFrameContentLength);
			
		}
		int length = rangeData.Length();
		PMString textFrameContentLength = "selected content length-";
		textFrameContentLength.AppendNumber(length);
		CAlert::InformationAlert(textFrameContentLength);

	}
	
};

void MyPlugin2SelectionObserver::HandleSelectionAttributeChanged(const ISelectionMessage* message) 
{
	//CAlert::InformationAlert("Selection Attribute changed..");
};

void MyPlugin2SelectionObserver::AutoAttach()
{
	CAlert::InformationAlert("in selection auto attach..");
	ActiveSelectionObserver::AutoAttach();
}