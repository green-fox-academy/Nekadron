#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include "server.h"
#include "cilent.h"
#include <process.h>
#include "command_line.h"
#include "DISCOVERY.h"
#include "BROADCAST.h"

void command_line(char buffer)
{

    if (buffer == 'h') {
        printf("Your command: Display this help info\n");
    } else if (buffer == 'e') {
        printf("Exit\n");
        exit(buffer);
    } else if (buffer == 'n') {
        printf("Set user name\n");
    } else if (buffer == 'l') {
        printf("List known users\n");
    } else if (buffer == 'd') {
        printf("Send discovery request\n");
    } else if (buffer == 'm') {
        _beginthread(cilent_call, 0, NULL);
        printf("Send message\n");
    } else {
        printf("You pressed a wrong key!");
    }
}
