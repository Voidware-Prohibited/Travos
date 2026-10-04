#pragma once

#include "NativeGameplayTags.h"
#include "Components/TravosGameStateComponent.h"
#include "TravosGameStateInterface.generated.h"

UINTERFACE(Blueprintable)
class UTravosGameStateInterface : public UInterface {
	GENERATED_BODY()
};

class TRAVOS_API ITravosGameStateInterface {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Travos Game State Interface")
	TSoftObjectPtr<UTravosGameStateComponent> GetTravosGameStateComponent();
};