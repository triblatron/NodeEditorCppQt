A Node editor using Qt with C++

## Architecture 

It will use Qt Quick and MVC for the GUI and implement the nodebackend FrontEndInterface to communicate with the backend.  As an example, it will do this using gRPC with Protobuffers.

There is no schedule for a release yet.

It depends on an as yet unwritten library for the node backend that is independent of communication mechanism and employs only streams backed by byte buffers to serialise the node graph in support of an undo system based on rollback.

A further library will integrate gRPC with protobuffers as the communication layer.  The UI will use this to pass requests to the Model and get the result.  It should be possible to send and receive parts of the Model necessary to support the UI.  This may mean the entire graph since the nodes are interconnected via ports and graphs are interconnected via their children.
Ideally we should be able to send differences for efficiency when the graphs become large enough but that probably is not necessary for our intended purpose.

It is possible to implement the communication without using gRPC as long as we obey the interface.

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
* set a port value
* connect two ports
* disconnect two ports
* reroute the connection between ports
* evaluate the graph

A template is a graph that can be instantiated in another graph as a child.  The boundary nodes become the inputs and outputs of the template and are wired up to the selection.  An instantiated template may share its nodes with other instantiations to get changes to the original.  This might cause difficulties if the structure of the template changes.  It might therefore be sensible to copy nodes by default.  This will make instantiation independent of the original.  An update template operation might explicitly change the structure of an instance.

Rerouting a connection is a visual operation that has no effect on the graph.  It must be an undoable operation like any other so it is unclear how to put it on rhe undo stack if that is implemented in the backend.  Therefore we could put it in the front end and just tell the backend to perform the primitive operations that are necessary to support undo and other front end operations.  The trick will be to always leave the graph in a consistent state after each primitive operation.  It should not be possible to break encapsulation and change the internal state directly.

These operations constitute the interface for the node editor that must be implemented by both the node editor and any stub used by gRPC or similar communication layers.

Some are already implemented but we have to decide where the implementation belongs.  It is currently in the backend and will be factored out into the library when it is created.
