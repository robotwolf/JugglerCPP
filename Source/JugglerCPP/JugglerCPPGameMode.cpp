// Copyright Epic Games, Inc. All Rights Reserved.

#include "JugglerCPPGameMode.h"
#include "JugglerCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJugglerCPPGameMode::AJugglerCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
