// Copyright Epic Games, Inc. All Rights Reserved.

#include "Travos.h"
#include "Utility/TravosLog.h"

#if WITH_EDITOR
#include "MessageLogModule.h"
#endif

#define LOCTEXT_NAMESPACE "FTravosModule"

void FTravosModule::StartupModule()
{
	IModuleInterface::StartupModule();

#if WITH_EDITOR
	auto& MessageLog{FModuleManager::LoadModuleChecked<FMessageLogModule>(FName{TEXTVIEW("MessageLog")})};

	FMessageLogInitializationOptions MessageLogOptions;
	MessageLogOptions.bShowFilters = true;
	MessageLogOptions.bAllowClear = true;
	MessageLogOptions.bDiscardDuplicates = true;

	MessageLog.RegisterLogListing(TravosLog::MessageLogName, LOCTEXT("MessageLogLabel", "Travos"), MessageLogOptions);
#endif
}

void FTravosModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTravosModule, Travos)