# Zero-Network Communication Protocol Teaser

ZNCP is a simple binary protocol meant to be an alternative to HTTP. Like HTTP, it is an application-level protocol and expects a fairly reliable transport layer protocol (namely TCP).

## Fundamentals

ZNCP is best explained by comparing it to HTTP...

### Resources with Dependencies

A single web page can have a number of associated resources necessary for properly displaying it such as images, style sheets, and scripts. Despite this, when a user makes a request via HTTP, they will only request a single resource, and then only after parsing that resource will it make requests to any other associated resources.

ZNCP addresses this unpleasant behavior by sending all dependencies of a resource immediately upon receiving a request for that resource. To facilitate caching on the client's side, the client can provide URI, checksum, timestamp tuples of dependent resources it has already cached and the server can decide whether the client needs an updated version.
