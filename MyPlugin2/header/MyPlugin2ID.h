//========================================================================================
//  
//  $File: $
//  
//  Owner: Ganesh
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __MyPlugin2ID_h__
#define __MyPlugin2ID_h__

#include "SDKDef.h"

// Company:
#define kMyPlugin2CompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kMyPlugin2CompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kMyPlugin2PluginName	"MyPlugin2"			// Name of this plug-in.
#define kMyPlugin2PrefixNumber	0xe9400 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kMyPlugin2Version		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kMyPlugin2Author		"Ganesh"					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kMyPlugin2PrefixNumber above to modify the prefix.)
#define kMyPlugin2Prefix		RezLong(kMyPlugin2PrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kMyPlugin2StringPrefix	SDK_DEF_STRINGIZE(kMyPlugin2PrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kMyPlugin2MissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kMyPlugin2MissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kMyPlugin2PluginID, kMyPlugin2Prefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kMyPlugin2StartupShutdownBoss, kMyPlugin2Prefix + 3)
DECLARE_PMID(kClassIDSpace, kMyPlugin2ResponderBoss, kMyPlugin2Prefix + 4)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 5)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 6)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 7)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 8)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 9)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 10)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 11)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 12)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 13)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 14)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 15)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 16)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 17)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 18)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 19)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 20)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 21)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 22)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 23)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 24)
//DECLARE_PMID(kClassIDSpace, kMyPlugin2Boss, kMyPlugin2Prefix + 25)


// InterfaceIDs:
DECLARE_PMID(kInterfaceIDSpace, IID_IMYOBSERVER, kMyPlugin2Prefix + 1)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 2)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 3)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 4)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 5)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 6)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 7)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 8)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 9)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 10)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 11)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 12)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 13)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 14)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 15)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 16)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 17)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 18)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 19)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 20)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 21)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 22)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 23)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 24)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN2INTERFACE, kMyPlugin2Prefix + 25)


// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace,  kMyPlugin2StartupShutdownServiceImpl, kMyPlugin2Prefix + 0)
DECLARE_PMID(kImplementationIDSpace, kMyPlugin2ObserverImpl, kMyPlugin2Prefix + 1)
DECLARE_PMID(kImplementationIDSpace, kMyPlugin2ResponderImpl, kMyPlugin2Prefix + 2)
DECLARE_PMID(kImplementationIDSpace, kMyPlugin2ServiceProviderImpl, kMyPlugin2Prefix + 3)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 4)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 5)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 6)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 7)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 8)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 9)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 10)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 11)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 12)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 13)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 14)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 15)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 16)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 17)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 18)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 19)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 20)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 21)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 22)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 23)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 24)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin2Impl, kMyPlugin2Prefix + 25)


// ActionIDs:
DECLARE_PMID(kActionIDSpace, kMyPlugin2AboutActionID, kMyPlugin2Prefix + 0)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 5)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 6)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 7)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 8)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 9)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 10)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 11)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 12)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 13)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 14)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 15)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 16)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 17)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 18)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 19)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 20)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 21)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 22)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 23)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 24)
//DECLARE_PMID(kActionIDSpace, kMyPlugin2ActionID, kMyPlugin2Prefix + 25)


// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 2)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 3)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 4)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 5)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 6)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 7)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 8)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 9)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 10)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 11)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 12)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 13)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 14)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 15)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 16)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 17)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 18)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 19)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 20)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 21)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 22)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 23)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 24)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin2WidgetID, kMyPlugin2Prefix + 25)


// "About Plug-ins" sub-menu:
#define kMyPlugin2AboutMenuKey			kMyPlugin2StringPrefix "kMyPlugin2AboutMenuKey"
#define kMyPlugin2AboutMenuPath		kSDKDefStandardAboutMenuPath kMyPlugin2CompanyKey

// "Plug-ins" sub-menu:
#define kMyPlugin2PluginsMenuKey 		kMyPlugin2StringPrefix "kMyPlugin2PluginsMenuKey"
#define kMyPlugin2PluginsMenuPath		kSDKDefPlugInsStandardMenuPath kMyPlugin2CompanyKey kSDKDefDelimitMenuPath kMyPlugin2PluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kMyPlugin2AboutBoxStringKey	kMyPlugin2StringPrefix "kMyPlugin2AboutBoxStringKey"
#define kMyPlugin2TargetMenuPath kMyPlugin2PluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kMyPlugin2FirstMajorFormatNumber  RezLong(1)
#define kMyPlugin2FirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kMyPlugin2CurrentMajorFormatNumber kMyPlugin2FirstMajorFormatNumber
#define kMyPlugin2CurrentMinorFormatNumber kMyPlugin2FirstMinorFormatNumber

#endif // __MyPlugin2ID_h__
