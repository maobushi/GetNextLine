#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 

int main(){
    
    char buf[100];

    buf = "HIK";
    printf("%zd",read(1,buf,2));
    printf("%zd",read(1,buf,2));
}

