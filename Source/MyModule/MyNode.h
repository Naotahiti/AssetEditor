#pragma once
#include "MyNode.generated.h"

UCLASS()

class MYMODULE_API UMyNode : public UEdGraphNode
{
    GENERATED_BODY()

public:
    UMyNode();

    // Titre du node
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

    // Couleur du node
    virtual FLinearColor GetNodeTitleColor() const override;

    // Tooltip
    virtual FText GetTooltipText() const override;

    // Allouer les pins par défaut
    virtual void AllocateDefaultPins() override;

    UPROPERTY(EditAnywhere, Category = "Node")
    FString NodeData;

    UPROPERTY(EditAnywhere, Category = "Node")
    int32 NodeValue;
};
