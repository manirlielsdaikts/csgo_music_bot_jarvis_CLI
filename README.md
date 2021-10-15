# csgo_music_bot_jarvis_CLI
A Linux music bot with a simple CLI for loading songs.
# Installation (compile from source)
## Prerequisites
* Have `gcc` and `ncurses` installed (`ncurses` come default with modern gcc installations)
## Compilation
1. Download files `main.c` and `help.c`
2. Edit the directories in `help.c` in order for them to match your music and CS:GO folder locations, as well as choose where and in what file to store the list of your music
3. Compile the source code by executing `gcc main.c -o jarvis -lncurses` in the directory where the source files are held in
4. Now you can delete the source files and perhaps even add `jarvis` to your `$PATH` in order for it to be executable in any folder by just typing `jarvis`. Otherwise, just navigate to the folder where jarvis is held in and type `./jarvis`
## Config and Usage
In order to be able to play the songs in-game, you have to create a config file for CS:GO:
1. Navigate to your CS:GO config folder (common location: `~/.steam/steam/userdata/[YOUR_USER_ID]/730/local/cfg/`)
2. Copy the file `jarvis.cfg` from the github project into the aforementioned folder
3. Load the config while in-game by typing `jarvis` in the CS:GO console
4. Load a song to be played using jarvis application from before and play it using the key `X` (can be changed in the config). 
*Sidenote: The loaded song will stay in the CS:GO directory until another song is loaded.*
