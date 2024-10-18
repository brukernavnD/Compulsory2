// Copyright Epic Games, Inc. All Rights Reserved.

#include "Compulsory2GameMode.h"
#include "Compulsory2Character.h"
#include "UObject/ConstructorHelpers.h"

ACompulsory2GameMode::ACompulsory2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
