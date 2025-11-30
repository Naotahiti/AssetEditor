#pragma once
//#include "MyGraph.generated.h"

UCLASS()

class ASSETEDITOR_API UMyGraph : public UEdGraphSchema

{
    GENERATED_BODY()

public:

    UPROPERTY()
    TObjectPtr<class UEdGraph> Graph;

    virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override {}
    virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override {}

    

};