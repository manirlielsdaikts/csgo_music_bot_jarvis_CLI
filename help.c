#include <stdlib.h>
#include <stdio.h>
#define FILENAME "~/Music/tracklist.sex"   //Replace with your own tracklist directory (preferably - same folder as your songs)
#define MUSIC_DIRECTORY "~/Music"          //Replace with your own music directory
#define CSGO_DIRECTORY "~/.local/share/Steam/steamapps/common/'Counter-Strike Global Offensive'"  //Replace with your CS:GO directory
int lastpath;
int line = 4;
char fuckinghelpme[256][200]; //adjust first value to increase maximum amount of tracks, currently set at 256
int amountOfSongs = 0;
int min = 0;
int maxWindowSize = 10;
int onsex = 0;
int getLine(char* outLine, int lineNumber);
void title();
int getchoice(int total, int paths[], char* text[]);

void w(char* text) {
  extern int line;
  mvprintw(line, 2, "%s", text);
  line++;
}

void path(int id) {
  lastpath = id;
  switch(id) {
    case 1: 
      title();
      w("Welcome to Jarvis Sex.");
      int size = 3;
      int paths[128] = {2, 3, 4};
      char* options[128] = {
        "Load Song",
        "//Coming Soon!", 
        "Exit"
      };
      path(getchoice(size, paths, options));
      break;
    case 2:
      mvprintw(3, 2, "Select a song.");
      int y, x;
      getmaxyx(stdscr, y, x);
      maxWindowSize = y - 7;
      size = maxWindowSize;
      int counter = 0;
      while(getLine(fuckinghelpme[counter], counter) != 1){
         counter++;
      }
      amountOfSongs = counter;
      for(int i = 0; i < maxWindowSize + min; i++){
         options[i] = fuckinghelpme[min + i];
         paths[i] = min + i + 10;
      }
      path(getchoice(size, paths, options));
      break;
    case 3:
      mvprintw(3, 2, "MMMMMMMMMMMMMMMWK00Oxx0XWWMMMMMMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMXx:,,''',:loxKNMMMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMNo............'l0WMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMW0:..':cllllc:,.':OWMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMNo..,codxkkkxxdc,':0MMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMWx'.,:ldkxdooodd:':0MMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMK:''';:llc:cllll:oXMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMWx,',,;cllcccclolxXMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMM0l;::codxxxxxxxx0NMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMNx:::;coxkkkkxxONMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMXo;,;cllodxxdkXMMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMW0l,;clddolox00XMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMMNx,,:codxkOOdclkKWMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMMNd,';lkKK0xc::;;:lxOXWMMMMMMMMMMMM\n  MMMMMMMMMMMMMNK0dccllkX0o::;;;,,',,;cdkO0XWMMMMMMM\n  MMMMMMMMMWXOdl:;,,;oxxdc;;;,,,,'',,,;::::lkNMMMMMM\n  MMMMWNWMWO:,,,;:c:cxOo:;;,,,,,,,,,,;:c:::;:kWMMMMM\n  MMMMKkKWKo:c:;,:ccdxl:;,,,,,,;;;;;;;cccc:::lKMMMMM\n  MMMXkdxxdoolo:,:ddoc;;,',,,;;;;;;:;;:cccc:::dXMMMM\n  MMXdcloolodoc,,::;;;;,',,,;;,,,;lxo;,;;;::::;oXMMM\n  WXxc:loollcc,.',,,;,,',,,,,'.';oOOl;,,'',;;;;c0MMM\n  0l:cccoolc;;,'',,,,,,,,,'''';;;loc,''';c:;;,,:xNMM\n  d:c:::c:;.......''''''',,,,,;,',,,.',:dx:;::;;:xNM\n  :',,','........'''''',,,,,,;,'';c;.';cl:',;:::;:dX\n  .................',,,,,,;;;,,,,;;,...,,'';;;;;;;:x\n  :....... ........,;;,,;;;;;,,,;;;;'...''',;;;;;;;l\n  x'..............,;;;;::;;,,,;;:::;'........',,;;,:\n");
      options[0] = "sex";
      paths[0] = 4;
      path(getchoice(1, paths, options));
      break;
    case 4:
      break;
   default:
      char cmd[256];
      char output[256] = {'\0'};
      int daikts = strlen(fuckinghelpme[id - 10]);
      for(int i = 0; i < daikts - 1; i++){
         output[i] = fuckinghelpme[id - 10][i];
      }
      sprintf(cmd, "cp %s/'%s' %s/", MUSIC_DIRECTORY, output, CSGO_DIRECTORY);
      system(cmd);
      sprintf(cmd, "mv %s/'%s' %s/voice_input.wav", CSGO_DIRECTORY, output, CSGO_DIRECTORY);
      system(cmd);
      path(2);
      break;
   }
}

int getLine(char* outLine, int lineNumber){
   char *line_buf = NULL;
   size_t line_buf_size = 0;
   int line_count = 0;
   ssize_t line_size;
   FILE *file = fopen(FILENAME, "r");
   line_size = getline(&line_buf, &line_buf_size, file);
   while (line_size >= 0){
      if(line_count == lineNumber){
         for(int i = 0; i < line_size; i++){
            outLine[i] = line_buf[i];
         }
         free(line_buf);
         line_buf = NULL;
         fclose(file);
         return 0;
      }
      line_count++;
      line_size = getline(&line_buf, &line_buf_size, file);
   }
   free(line_buf);
   line_buf = NULL;
   fclose(file);
   return 1;
}
void title() {
   int y, x;
   getmaxyx(stdscr, y, x);
   attron(A_BOLD);
   mvprintw(1, ((x-20)/2), "Jarvis Sex", y, x);
   attroff(A_BOLD);
}

int getchoice(int total, int paths[], char* text[]) {
   extern int line;
   line = 4;
   int y, x;
   getmaxyx(stdscr, y, x);
   if(y < 30 || x < 120) {
      while(1) {
         getmaxyx(stdscr, y, x);
         resize_term(y, x);
         clear();
         if(y < 30 && x >= 120) {
            printw("Increase your window size by %d character(s) vertically.", 30-y);
         }else if(y >= 30 && x < 120) {
            printw("Increase your window size by %d character(s) horizontally.", 120-x); 
         }else if (y < 30 && x < 120) {
            printw("Increase your window size by %d character(s) horizontally and %d character(s) vertically.", 120-x, 30-y); 
         }else{
            clear();
            title();
            box(stdscr, 0, 0);
            refresh();
            return lastpath;
         }
         getch();
         refresh();
      }
   }
   refresh();
   WINDOW *menu = newwin(total+2, x, y-(total+2), 0);
   keypad(menu, TRUE);
   box(menu, 0, 0);
   mvwprintw(menu, 0, 0, "├");
   mvwprintw(menu, 0, x-1, "┤");
   wrefresh(menu);
   int on = onsex, choice, funny = 0;
   while(1) {
      if(funny == 1) {
         getmaxyx(stdscr, y, x);
         resize_term(y, x);
         delwin(menu);
         clear();
         title();
         box(stdscr, 0, 0);
         noecho();
         curs_set(0);
         refresh();
         return lastpath;
      }
   for(int i = 0; i < total; i++) {
      if(i == on) { wattron(menu, A_REVERSE); }
         mvwprintw(menu, i+1, 1, text[i]);
         wattroff(menu, A_REVERSE);
      }
      choice = wgetch(menu);
      if(choice == 10) {
         onsex = 0;
         delwin(menu);
         clear();
         title();
         box(stdscr, 0, 0);
         refresh();
         return paths[on];
      }
      switch(choice) {
         case KEY_UP:
            if(--on < 0) {on = 0; if(min > 0){min--; onsex = 0; return lastpath;}}
            break;
         case KEY_DOWN:
            if(++on >= total) {if(amountOfSongs > (min + maxWindowSize)){on = total-1; min++; onsex = on; return lastpath;}else{--on;}}
            break;
         case KEY_RESIZE:
            funny = 1;
            break;
         default:
            break;
      }
   }
}
