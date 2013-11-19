# Zero Network

The HTTP/1.1 standard shows its age fairly often in modern day applications. Some high-caliber minds have gone towards improving this state of affairs, and SPDY along with the new HTTP/2.0 standard (which is based on SPDY) look very nice. They are very sensible and are clearly the future. Despite this, my lesser-caliber mind decided to have a go at making my own alternative to HTTP.

Zero Network is the name of an alternative to the World Wide Web that I intend to hack together with high hopes and duct tape. I'd like to make alternatives to all of HTTP, HTML, and CSS, but for now I am concentrating on HTTP.

## ZNCP

The Zero Network Communication Protocol attempts to solve the same problem that HTTP does, but goes about it differently. It is a binary protocol and tries to have a more modern outlook on the web than HTTP. For more specifics see the working draft in the `docs/` directory.

One things I'm trying to do is create a solid reference implementation that can be compiled onto a huge variety of platforms so that the internet doesn't get littered with thousands of implementations of the same parsing code. Check out the `lib/` directory for that code.

## Development

If you'd like to help out with development, feel free to dive right in. This is a light-natured project so don't worry.
