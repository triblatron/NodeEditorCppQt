A Node editor using Qt with Go.

It will use MVC for the GUI and gRPC with ProtocolBuffers to talk to the backend.
There is no schedule for a release yet.

It depends on an as yet unwritten library for the node backend that is independent of communication mechanism and employs only streams backed by byte buffers to serialise the node graph in support of an undo system based on rollback.

A further library will integrate gRPC with protobuffers as the communication layer.  The UI will use this to pass requests to the Model and get the result.  It should be possible to send and receive parts of the Model necessary to support the UI.  This may mean the entire graph since the nodes are interconnected via ports and graphs are interconnected via their children.
Ideally we should be able to send differences for efficiency when the graphs become large enough but that probably is not necessary for our intended purpose.

Supported operations are:
* create a graph
* delete a graph
* create a node
* delete a node
* create a child graph
* delete a child graph
* create a template
* instantiate a template
* delete an instance
* delete a template
