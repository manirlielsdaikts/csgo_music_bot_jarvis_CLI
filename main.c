#include <locale.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "help.c"
void updateTracklist();

int main(void){
   updateTracklist();
   setlocale(LC_ALL, "");
   initscr();
   noecho();
   curs_set(0);
   box(stdscr, 0, 0);
   start_color();
   init_pair(1, COLOR_RED, COLOR_BLACK);
   path(1);
   endwin();
   system("clear");
   printf("  MMMMMMMMMMMMMMMWK00Oxx0XWWMMMMMMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMXx:,,''',:loxKNMMMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMNo............'l0WMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMW0:..':cllllc:,.':OWMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMNo..,codxkkkxxdc,':0MMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMWx'.,:ldkxdooodd:':0MMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMK:''';:llc:cllll:oXMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMWx,',,;cllcccclolxXMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMM0l;::codxxxxxxxx0NMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMNx:::;coxkkkkxxONMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMXo;,;cllodxxdkXMMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMW0l,;clddolox00XMMMMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMMNx,,:codxkOOdclkKWMMMMMMMMMMMMMMMM\n  MMMMMMMMMMMMMMMMNd,';lkKK0xc::;;:lxOXWMMMMMMMMMMMM\n  MMMMMMMMMMMMMNK0dccllkX0o::;;;,,',,;cdkO0XWMMMMMMM\n  MMMMMMMMMWXOdl:;,,;oxxdc;;;,,,,'',,,;::::lkNMMMMMM\n  MMMMWNWMWO:,,,;:c:cxOo:;;,,,,,,,,,,;:c:::;:kWMMMMM\n  MMMMKkKWKo:c:;,:ccdxl:;,,,,,,;;;;;;;cccc:::lKMMMMM\n  MMMXkdxxdoolo:,:ddoc;;,',,,;;;;;;:;;:cccc:::dXMMMM\n  MMXdcloolodoc,,::;;;;,',,,;;,,,;lxo;,;;;::::;oXMMM\n  WXxc:loollcc,.',,,;,,',,,,,'.';oOOl;,,'',;;;;c0MMM\n  0l:cccoolc;;,'',,,,,,,,,'''';;;loc,''';c:;;,,:xNMM\n  d:c:::c:;.......''''''',,,,,;,',,,.',:dx:;::;;:xNM\n  :',,','........'''''',,,,,,;,'';c;.';cl:',;:::;:dX\n  .................',,,,,,;;;,,,,;;,...,,'';;;;;;;:x\n  :....... ........,;;,,;;;;;,,,;;;;'...''',;;;;;;;l\n  x'..............,;;;;::;;,,,;;:::;'........',,;;,:\n\n\njarvis sex\n");
   return(0);
}
void updateTracklist(){
   struct dirent **namelist;
   int n;
   FILE *tracklist = fopen(FILENAME, "w");
   n = scandir("/home/boss/Desktop/slam", &namelist, NULL, alphasort);
   if (n < 0){
      perror("scandir");
   }else{
      for (int i = 0; i < n; i++) {
         unsigned char *help = {namelist[i]->d_name};
         int length = strlen(help);
         if(help[length - 1] == 'v' && help[length - 2] == 'a' && help[length - 3] == 'w' && help[length - 4] == '.'){
            fprintf(tracklist, "%s\n", namelist[i]->d_name);
         }
         free(namelist[i]);
      }
      free(namelist);
   }
}
