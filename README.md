# OpenRazer keyboard rgb software (for my use cases)
I created this project to allow me to have my keyboard follow the color of screen contents.

As of now it has a simple auto detection of the device (on linux only, razer synapse on windows does what I need). 
On startup it does a brightness and color change to confirm everything works. The performance is acceptable, I was able to do 2000 color changes of the entire Ornata Chroma V2 in 47 seconds during my tests.
Screenshoting was not yet added but has the potential to slow it down quite a bit, still should be better at that than a python script.

Planned features:
- screenshot based color detection with wayland support
- multi monitor support
- maybe some kind of animation support
