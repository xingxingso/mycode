#include <stdio.h> 
#include <string.h> 
// #include "syscalls.h" 
// #include <unistd.h>
#include <fcntl.h>      /* flags for read and write */ 
#include <sys/types.h>  /* typedefs */ 
#include <sys/stat.h>   /* structure returned by stat */ 
#include <dirent.h> 
#include "../../helper/dirwalk.h"

#ifndef DIRSIZ 
#define DIRSIZ  14 
#endif 

void fsize(char *);

/* print file name */ 
int main(int argc, char *argv[]) { 
    if (argc == 1)  /* default: current directory */ 
        fsize("."); 
    else while (--argc > 0) 
        fsize(*++argv); 
    return 0; 
} 

// int stat(const char *, struct stat *); 
void dirwalk(char *, void (*fcn)(char *)); 

/* fsize:  print the name of file "name" */ 
void fsize(char *name) 
{ 
    struct stat stbuf; 

    if (stat(name, &stbuf) == -1) { 
        fprintf(stderr, "fsize: can't access %s\n", name); 
        return; 
    } 
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) 
        dirwalk(name, fsize); 
    printf("%8lld %s\n", stbuf.st_size, name); 
} 


// char *name; 
// struct stat stbuf; 
// int stat(char *, struct stat *); 

// stat(name, &stbuf); 

// struct stat   /* inode information returned by stat */ 
// { 
//     dev_t     st_dev;      /* device of inode */ 
//     ino_t     st_ino;      /* inode number */ 
//     short     st_mode;     /* mode bits */ 
//     short     st_nlink;    /* number of links to file */ 
//     short     st_uid;      /* owners user id */ 
//     short     st_gid;      /* owners group id */ 
//     dev_t     st_rdev;     /* for special files */ 
//     off_t     st_size;     /* file size in characters */ 
//     time_t    st_atime;    /* time last accessed */ 
//     time_t    st_mtime;    /* time last modified */ 
//     time_t    st_ctime;    /* time originally created */ 
// };

// // <sys/stat.h>
// #define S_IFMT    0160000  /* type of file: */ 
// #define S_IFDIR   0040000  /* directory */ 
// #define S_IFCHR   0020000  /* character special */ 
// #define S_IFBLK   0060000  /* block special */ 
// #define S_IFREG   0010000  /* regular */ 
// /* ... */ 


// struct direct {   /* directory entry */ 
//     ino_t d_ino;           /* inode number */ 
//     char  d_name[DIRSIZ];  /* long name does not have '\0' */ 
// };

// int fstat(int fd, struct stat *);
