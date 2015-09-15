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


#ifndef __MyPlugin1ID_h__
#define __MyPlugin1ID_h__

#include "SDKDef.h"

// Company:
#define kMyPlugin1CompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kMyPlugin1CompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kMyPlugin1PluginName	"MyPlugin1"			// Name of this plug-in.
#define kMyPlugin1PrefixNumber	0xe9400 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kMyPlugin1Version		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kMyPlugin1Author		"Ganesh"					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kMyPlugin1PrefixNumber above to modify the prefix.)
#define kMyPlugin1Prefix		RezLong(kMyPlugin1PrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kMyPlugin1StringPrefix	SDK_DEF_STRINGIZE(kMyPlugin1PrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kMyPlugin1MissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kMyPlugin1MissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kMyPlugin1PluginID, kMyPlugin1Prefix + 0)

// ClassIDs:
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 3)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 4)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 5)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 6)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 7)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 8)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 9)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 10)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 11)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 12)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 13)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 14)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 15)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 16)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 17)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 18)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 19)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 20)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 21)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 22)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 23)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 24)
//DECLARE_PMID(kClassIDSpace, kMyPlugin1Boss, kMyPlugin1Prefix + 25)


// InterfaceIDs:
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 0)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 1)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 2)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 3)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 4)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 5)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 6)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 7)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 8)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 9)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 10)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 11)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 12)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 13)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 14)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 15)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 16)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 17)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 18)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 19)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 20)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 21)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 22)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 23)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 24)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYPLUGIN1INTERFACE, kMyPlugin1Prefix + 25)


// ImplementationIDs:
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 0)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 1)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 2)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 3)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 4)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 5)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 6)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 7)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 8)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 9)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 10)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 11)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 12)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 13)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 14)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 15)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 16)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 17)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 18)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 19)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 20)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 21)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 22)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 23)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 24)
//DECLARE_PMID(kImplementationIDSpace, kMyPlugin1Impl, kMyPlugin1Prefix + 25)


// ActionIDs:
DECLARE_PMID(kActionIDSpace, kMyPlugin1AboutActionID, kMyPlugin1Prefix + 0)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 5)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 6)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 7)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 8)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 9)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 10)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 11)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 12)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 13)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 14)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 15)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 16)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 17)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 18)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 19)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 20)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 21)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 22)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 23)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 24)
//DECLARE_PMID(kActionIDSpace, kMyPlugin1ActionID, kMyPlugin1Prefix + 25)


// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 2)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 3)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 4)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 5)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 6)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 7)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 8)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 9)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 10)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 11)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 12)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 13)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 14)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 15)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 16)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 17)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 18)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 19)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 20)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 21)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 22)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 23)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 24)
//DECLARE_PMID(kWidgetIDSpace, kMyPlugin1WidgetID, kMyPlugin1Prefix + 25)


// "About Plug-ins" sub-menu:
#define kMyPlugin1AboutMenuKey			kMyPlugin1StringPrefix "kMyPlugin1AboutMenuKey"
#define kMyPlugin1AboutMenuPath		kSDKDefStandardAboutMenuPath kMyPlugin1CompanyKey

// "Plug-ins" sub-menu:
#define kMyPlugin1PluginsMenuKey 		kMyPlugin1StringPrefix "kMyPlugin1PluginsMenuKey"
#define kMyPlugin1PluginsMenuPath		kSDKDefPlugInsStandardMenuPath kMyPlugin1CompanyKey kSDKDefDelimitMenuPath kMyPlugin1PluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kMyPlugin1AboutBoxStringKey	kMyPlugin1StringPrefix "kMyPlugin1AboutBoxStringKey"
#define kMyPlugin1TargetMenuPath kMyPlugin1PluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kMyPlugin1FirstMajorFormatNumber  RezLong(1)
#define kMyPlugin1FirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kMyPlugin1CurrentMajorFormatNumber kMyPlugin1FirstMajorFormatNumber
#define kMyPlugin1CurrentMinorFormatNumber kMyPlugin1FirstMinorFormatNumber

#endif // __MyPlugin1ID_h__
