#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buffer [1024];

void tail (int fd, int num) {
    int i, n, numLines, npLines;
    int tempFile;
    
    //create temporary file w/ read write privalages.
    
    tempFile = open ("tempFile", O_CREATE | O_RDWR);
    
    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
        
        //write to the temporary file
        write (tempFile, buffer, n);
        
        //iterate through each byte
        for (i = 0; i < n; i++) {
            
            //check if byte = new line char
            if(buffer[i] == '\n') {
                //increment numLines to keep track of total number of lines
                numLines++;
            }
        }
    }
    
    if (n < 0) {
        printf (1, "err: cannot read \n");
        exit ();
    }
  
    /*calculate number of lines that will not be printed
     keep track of this to print only lines after this number, take total number of lines and subtract it by num which is 10 by default or greater than / less than depending on if specified by argument passed to program. */
    
    if (numLines < num) {
        npLines = 0;
    }
    
    else {
        npLines = numLines - num;
    }
    
    //npLines = numLines - num;

    close (tempFile);
    
    //re-open temporary file to which we wrote previously
    tempFile = open ("tempFile", 0);

    int counter = 0;
    while ((n = read(tempFile, buffer, sizeof(buffer))) > 0) {
        for (i = 0; i < n; i++) {
            
            //counter keeps track of which line we're at
            //make sure we only print lines after the first npLines not to print
            if (counter >= npLines)
                printf(1, "%c", buffer[i]);
            
            if (buffer[i] == '\n') {
                //increment for each new line byte, counter keeps track of what line we're currently at
                counter++;
            }
        }
    }
    
    close (tempFile);
    unlink("tempFile");
}

int main(int argc,char *argv[]) {
    int fd = 0;
    int nl = 10;
    char c;
    int i;
    
    //in case of no arguments passed then just read from stdin (fd=0) and nl =10 (# lines to print)
    if  (argc <= 1) {
        tail(fd, nl);
        exit();
    }
    
    else {
        for (i = 1; i < argc; i++) {
            //get char value to check for - argument below
            c = *argv[i];
            
            if (c == '-') {
                
                //if argument - is provided for number of lines, increment argv[i] and convert it to int
                argv[i]++;
                nl = atoi(argv[i]++);
            }
            
            else {
                if ((fd = open(argv[i], 0)) < 0) {
                    printf(1, "tail: cannot open %s\n", argv[i]);
                    exit();
                }
            }
        }
        
        tail(fd, nl);
        close(fd);
        exit();
    }
}
