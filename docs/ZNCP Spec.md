# Zero-Network Communication Protocol Specification

*This is Draft 0.0.1*

## Terms

| Term | Definition |
| :--: | :--------- |
| node | Some entity that exists on a network and can communicate with other nodes. |
| client | A node that initiates the connection. |
| server | A node that is connected to by a client. |
| resource | Anything that can be identified by a URI (this includes enpoints servicing API commands, documents, binary file, etc.) |
| request | A message that is not a response. A response is not necessarily sent for each request. |
| response | A message that is a result of a request and is associated with that request. |

## Connections

A connection will be made by the client when it wants to perform an some action on a specific resource (just like HTTP). That connection will be closed *by the server* after all the responses are sent (typically the resource requested along with all dependent resources).

The server can leave the connection open and the client will funnell all requests through that connection.

The client can send a `BURST` request which signals to the server that a number of requests will be sent through the connection at once in which case the server should leave the connection open until all the messages are sent.

## Messages

### Format

Every payload sent through the wire is wrapped in a message. A message consists of the following parts.

|     Contents     |  Type  |     Example      |
| :--------------: | :----: | :--------------: |
| Protocol Version | varint |         1        |
|   Message Type   | varint |         1        |
|     Payload      |  raw   |                  |

#### Protocol Version

Each breaking-revision to the the Zero-Network Communication Protocol will increment the version count by 1 (rather than using typical semantic versioning). When a node receives a message with a version protocol it doesn't support (or disallows due to security), it can respond with a `CHANGE_VERSION` request to ask the other node to move to a different version of the protocol.

#### Message Type and Payload

There are a number of different message types. The message type determines what the payload will consist of.

## Message Type: Control Request

A control request is a request that does not deal with a resource. The action it is requesting should typically be performed on the conversation itself, though it depends on the action.

### Format

|     Contents     |  Type  |     Example      |
| :--------------: | :----: | :--------------: |
|     Action       | varint |         1        |
|      UID         | varint |         0        |
|     Payload      |  raw   |   hello world    |

## Message Type: Control Response

A response to a control request has the same layout as the request. The action and the uid will be the same as the request.

## Message Type: Resource Request

A resource request is a request that performs some action on a resource.

### Format

|     Contents     |  Type  |     Example      |
| :--------------: | :----: | :--------------: |
|     Frames       | varint |         1        |
|       UID        | varint |         0        |
|       URI        | string |   urn:get-name   |
|     Action       | varint |         1        |
|     Payload      |  raw   |   hello world    |

#### Frames

A payload can be sent in multiple frames if needed. Each message will be made available to the next layer *as soon as it is fully received*.

#### UID

Each request should have a unique (to the conversation) ID so that responses to that request can be recognized as such.

#### URI

This is the resource the request is concerned with.

#### Action

Each number corresponds to a particular action. Actions, as a concept, are the same as in HTTP.

#### Payload

The contents of the payload are dependent on the action.

## Resource Response

The layout of a resource response is the same as a request.
