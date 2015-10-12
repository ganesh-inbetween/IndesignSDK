#include "VCPlugInHeaders.h"

#include "MyPlugin2ServiceProvider.h"

#include "DocFrameworkID.h"      //for switch doc signal
#include "GenericID.h"           //for new PI event
#include "IDocumentSignalData.h" //For getting the document UID from signalMgr
#include "TextID.h"				 //kNewStorySignalResponderService
#include "MyPlugin2ID.h"

CREATE_PMINTERFACE(MyPlugin2ServiceProvider, kMyPlugin2ServiceProviderImpl);


MyPlugin2ServiceProvider::MyPlugin2ServiceProvider(IPMUnknown* boss) :CServiceProvider(boss)
{
	fSupportedServiceIDs.clear();
	//private member function to add service
	addResponder();
};

MyPlugin2ServiceProvider::~MyPlugin2ServiceProvider()
{
};

/*addResponder() add the services for which Notification is required
*/
void MyPlugin2ServiceProvider::addResponder()
{
	fSupportedServiceIDs.clear();

	fSupportedServiceIDs.push_back(kAfterNewDocSignalResponderService);
	fSupportedServiceIDs.push_back(kAfterOpenDocSignalResponderService);
	fSupportedServiceIDs.push_back(kAfterSaveDocSignalResponderService);
	fSupportedServiceIDs.push_back(kDeleteCharStyleRespService);
};


/*@Interface
GetName() initializes the name of the service.
@param pName Ptr to PMString to receive the name.
*/
void MyPlugin2ServiceProvider::GetName(PMString* pName)
{
	pName->SetKey("MY Responder Service");
};

/*@Interface
GetServiceID() returns a single service ID.  This is required, even though
GetServiceIDs() will return the complete list initialized in the constructor.
This method just returns the first service ID in the list.
*/
ServiceID MyPlugin2ServiceProvider::GetServiceID()
{
	// Should never be called given that HasMultipleIDs() returns true.
	return fSupportedServiceIDs[0];
}

/*@Interface
IsDefaultServiceProvider()
*/
bool16 MyPlugin2ServiceProvider::IsDefaultServiceProvider()
{
	return kFalse;
}

/*@Interface
GetInstantiationPolicy() returns a InstancePerX value to indicate that only
one instance per session is needed.
*/
IK2ServiceProvider::InstancePerX MyPlugin2ServiceProvider::GetInstantiationPolicy()
{
	return IK2ServiceProvider::kInstancePerSession;
}

/*@Interface
HasMultipleIDs() returns true in order to force a call to GetServiceIDs().
*/
bool16 MyPlugin2ServiceProvider::HasMultipleIDs() const
{
	return kTrue;
}

/*@Interface
GetServiceIDs() returns a list of services provided.
@param serviceIDs List of IDs describing the services that
CSDTPServiceProviderImpl registers to handle.
*/
void MyPlugin2ServiceProvider::GetServiceIDs(K2Vector<ServiceID>& serviceIDs)
{
	// Append a service IDs for each service provided.
	for (int32 i = 0; i<fSupportedServiceIDs.size(); i++)
		serviceIDs.push_back(fSupportedServiceIDs[i]);
}
