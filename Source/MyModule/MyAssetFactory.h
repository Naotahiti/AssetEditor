// Copyright © 2024 MajorT. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MyAssetFactory.generated.h"

UCLASS()
class MYMODULE_API UMyAssetFactory : public UFactory
{
	GENERATED_BODY()

public:

	UMyAssetFactory();
	//~ Begin UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	//~ End UFactory Interface
};
