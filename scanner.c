#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int soc;
    char target_ip[20];
    struct sockaddr_in target;
    int scantype;

    printf("Scannable ports on your local Net. \n");
    system("sudo arp-scan -l");
    printf("\n Enter target IP: ");
    scanf("%s", target_ip);

    printf("\n Scan one port wich you will chose : 1 \n Scan all ports (1-1024): 2 \nSelection: ");
    scanf("%d", &scantype);

    if(scantype == 1) {
        int choosenport;
        printf("Port number: ");
        scanf("%d", &choosenport);

        soc = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_family = AF_INET;
        target.sin_port = htons(choosenport);
        target.sin_addr.s_addr = inet_addr(target_ip);

        if (connect(soc, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open.\n", choosenport);
        } else {
            printf("Port %d is closed or filtered.\n", choosenport);
        }
        close(soc);
    } 
    else if(scantype == 2) {
        printf("Scanning...\n");
        for(int i = 1; i <= 1024; i++) {
            soc = socket(AF_INET, SOCK_STREAM, 0); 
            target.sin_family = AF_INET;
            target.sin_port = htons(i);
            target.sin_addr.s_addr = inet_addr(target_ip);

            if(connect(soc, (struct sockaddr *)&target, sizeof(target)) == 0) {
                printf("Open port: %d\n", i);
            }
            close(soc); 
        }
    }

    else{printf("type '1' or '2' only. "); return 0;} 

    return 0;
}
