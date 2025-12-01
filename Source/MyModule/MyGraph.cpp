#include "MyGraph.h"
#include "MyGraphSchema.h"

UMyGraph::UMyGraph()
{
	Schema = UMyGraphSchema::StaticClass();
}
