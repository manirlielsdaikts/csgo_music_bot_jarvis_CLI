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
