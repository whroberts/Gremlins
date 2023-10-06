// Copyright Epic Games, Inc. All Rights Reserved.

#include "GremlinsGameMode.h"
#include "GremlinsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGremlinsGameMode::AGremlinsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
