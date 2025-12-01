#include "MyGraphSchema.h"
#include "MyNode.h"
#include "MyGraph.h"

UEdGraphNode* FMyCustomSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
    UMyNode* NewNode = NewObject<UMyNode>(ParentGraph);
    NewNode->CreateNewGuid();
    NewNode->NodePosX = Location.X;
    NewNode->NodePosY = Location.Y;

    ParentGraph->AddNode(NewNode, true, bSelectNewNode);

    NewNode->AllocateDefaultPins();

    if (FromPin)
    {
        NewNode->AutowireNewNode(FromPin);
    }

    return NewNode;
}

void UMyGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{

    
        TSharedPtr<FMyCustomSchemaAction_NewNode> NewNodeAction(
            new FMyCustomSchemaAction_NewNode(
                FText::FromString(TEXT("Nodes")),
                FText::FromString(TEXT("Add Custom Node")),
                FText::FromString(TEXT("Crée un nouveau node")),
                0
            )
        );

        ContextMenuBuilder.AddAction(NewNodeAction);
    

}

const FPinConnectionResponse UMyGraphSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
    if (!A || !B)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Invalid pins"));
    }

    if (A == B)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Cannot connect pin to itself"));
    }

    if (A->Direction == B->Direction)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Cannot connect input to input or output to output"));
    }

    return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT(""));
}

bool UMyGraphSchema::TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const
{
    if (CanCreateConnection(A, B).Response == CONNECT_RESPONSE_MAKE)
    {
        A->MakeLinkTo(B);
        return true;
    }

    return false;
}

void UMyGraphSchema::BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotification) const
{
    TargetPin.BreakAllPinLinks();
}
