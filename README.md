# heist-v2
This is a text-based stealth game running on Borland Turbo C++.

Startup instructions:

If Borland Turbo C++ is not installed, extract Turbo.C.3.2.zip and run setup.exe to install it. The default installation directory is C:\TURBOC3.

Download HEISTX2.CPP and all txt files prefixed 'lvl' (level maps) into C:\TURBOC3\BIN (or the BIN subfolder of whichever directory Turbo C++ is installed in).

Open Turbo C++, find HEISTX2.CPP and run the game.

Notes:

1) The game works on keyboard inputs alone, and does not accept mouse inputs of any kind.

2) The opening screens may look frozen, but are simply waiting for the user to press a key to progress to the next screen.
Similarly, the game map refreshes every time a key is pressed. Enemies will not move until the player moves.

3) There is a HUD element to the top right of the map specifying which weapon/ability is currently equipped (displays 'Locked' if the desired weapon/ability has not yet purchased at the Store). Press the number keys to hot-swap between them.

4) The controls and key bindings may be learned from the main menu.
