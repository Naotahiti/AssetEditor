#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "MyGraphSchema.generated.h"

USTRUCT()
struct FMyCustomSchemaAction_NewNode : public FEdGraphSchemaAction
{
    GENERATED_BODY()

    FMyCustomSchemaAction_NewNode()
        : FEdGraphSchemaAction() {
    }

    FMyCustomSchemaAction_NewNode(FText InNodeCategory, FText InMenuDesc, FText InToolTip, int32 InGrouping)
        : FEdGraphSchemaAction(InNodeCategory, InMenuDesc, InToolTip, InGrouping) {
    }

    virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};
UCLASS()
class MYMODULE_API UMyGraphSchema : public UEdGraphSchema
{
    GENERATED_BODY()

public:
    // Obtenir les actions du menu contextuel
    virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;

    // Connecter deux pins
    virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;

    // Essayer de créer une connexion
    virtual bool TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const override;

    // Casser toutes les connexions d'un pin
    virtual void BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotification) const override;
};
