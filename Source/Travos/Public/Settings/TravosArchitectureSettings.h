// MIT

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "TravosArchitectureSettings.generated.h"

/**
 * 
 */
UCLASS(config = Travos, DefaultConfig)
class TRAVOS_API UTravosArchitectureSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UTravosArchitectureSettings();
	
	// True = Integrate with Abraxas, False = Local Mode
	UPROPERTY(Config, EditAnywhere, Category = "Architecture")
	bool bAbraxasIntegration {false};

	UPROPERTY(Config, EditAnywhere, Category = "Architecture")
	FString AbraxasAddress;

	UPROPERTY(Config, EditAnywhere, Category = "Architecture|Abraxas")
	FString AbraxasApiKey;
	
#if WITH_EDITOR
	virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
	virtual FText GetSectionText() const override { return NSLOCTEXT("Travos", "TravosSectionText", "Travos Settings"); }
	virtual FText GetSectionDescription() const override { return NSLOCTEXT("Travos", "TravosSectionDesc", "Configure Travos Architecture Settings"); }
#endif
};