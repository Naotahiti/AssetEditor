#include "MyNode.h"

UMyNode::UMyNode()
{
	NodeData = TEXT("Custom Node");
	NodeValue = 0;
}

FText UMyNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(NodeData);
}

FLinearColor UMyNode::GetNodeTitleColor() const
{
	return FLinearColor(0.2f, 0.6f, 1.0f);
}

FText UMyNode::GetTooltipText() const
{
	return FText::FromString(FString::Printf(TEXT("Node: %s\nValue: %d"), *NodeData, NodeValue));
}

void UMyNode::AllocateDefaultPins()
{
	// input pin
	CreatePin(EGPD_Input, TEXT("MyPinType"), TEXT("Input"));

	// output pin
	CreatePin(EGPD_Output, TEXT("MyPinType"), TEXT("Output"));
}
