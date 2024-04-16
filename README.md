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
* update a template

A template is a graph that can be instantiated in another graph as a child.  The boundary nodes become the inputs and outputs of the template and are wired up to the selection.  An instantiated template may share its nodes with other instantiations to get changes to the original.  This might cause difficulties if the structure of the template changes.  It might therefore be sensible to copy nodes by default.  This will make instantiation independent of the original.  An update template operation might explicitly change the structure of an instance.

These operations constitute the interface for the node editor that must be implemented by both the node editor and any stub used by gRPC or similar communication layers.

Some are already implemented but we have to decide where the implementation belongs.  It is currently in the backend and will be factored out into the library when it is created.
