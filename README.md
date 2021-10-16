# csgo_music_bot_jarvis_CLI
A Linux music bot with a simple CLI for loading songs.
# Installation (compile from source)
## Prerequisites
* Have `gcc` and `ncurses` installed (ncurses come default with modern gcc installations)
* All of your songs must be .wav files with the following specifications:
    * Frequency of 22050Hz
    * 16 bit audio
    * Only 1 audio channel
* These specifications can be met by converting your files to .wav (google how to do it, there are many ways to do so, but i recommend using ffmpeg) and then using `sox` to convert them to the specific specifications by running the command `sox "[INPUT_FILENAME]" -r 22050 -c 1 -b 16 "[OUTPUT_FILENAME]"`. The input and output filenames **must** be different, as sox likes to complain when it has to overwrite the file that it is converting. Also aliasing `sox` to `sex` is preferable but not neccessary.
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

### How does this function?
The C - Application `jarvis` basically takes a song from a directory, copies it into your CS:GO directory and renames it to 'voice_input.wav'. CS:GO and some other source games have a command that plays this waveform file as your in-game voice input audio. After pressing the key that is aliased in the config (`X` by default), it loads the aforementioned audio file as your voice input, makes it so that you don't have to hold your push-to-talk key to speak in-game and also that you can hear your own voice input audio. Afterwards, it rebinds the same key to do the opposite, so when you press it again, everything is back to normal. This won't give you any problems with VAC (most likely, i am not responsible for your misfortunes while using my application), but it can get you muted if too many people report you for abusive voice communications.

### Common bugs:
none
