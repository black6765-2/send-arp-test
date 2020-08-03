#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

void find_mac(char attacker_mac[])
{
    struct ifreq s;
    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    char temp[10];
 
    strcpy(s.ifr_name, "eth0");
    if (0 == ioctl(fd, SIOCGIFHWADDR, &s)) 
    {
        int i = 0;
        for (i = 0; i < 6; ++i)
        {
            sprintf(temp ,"%02x:", (unsigned char) s.ifr_addr.sa_data[i]);       
            strcpy(attacker_mac + i*3, temp);
        }
        attacker_mac[17] = '\0';
    }
    printf("%s", attacker_mac);
}