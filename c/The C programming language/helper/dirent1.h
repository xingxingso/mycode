// dirent.h  in mac `/usr/include/dirent.h`

#include <stdlib.h>

#define NAME_MAX   14   /* longest filename component; */ 
                        /* system-dependent */ 
typedef struct {       /* portable directory entry */ 
    long ino;                  /* inode number */ 
    char name[NAME_MAX+1];     /* name + '\0' terminator */ 
} Dirent; 

typedef struct {       /* minimal DIR: no buffering, etc. */ 
    int fd;               /* file descriptor for the directory */ 
    Dirent d;             /* the directory entry */ 
} DIR; 

DIR *opendir(char *dirname); 
Dirent *readdir(DIR *dfd); 
void closedir(DIR *dfd); 


/* opendir:  open a directory for readdir calls */ 
DIR *opendir(char *dirname) { 
    int fd; 
    struct stat stbuf; 
    DIR *dp; 

    if ((fd = open(dirname, O_RDONLY, 0)) == -1 
        || fstat(fd, &stbuf) == -1 
        || (stbuf.st_mode & S_IFMT) != S_IFDIR 
        || (dp = (DIR *) malloc(sizeof(DIR))) == NULL) 
        return NULL; 
    dp->fd = fd; 
    return dp; 
} 

/* closedir:  close directory opened by opendir */ 
void closedir(DIR *dp) 
{ 
    if (dp) { 
        close(dp->fd); 
        free(dp); 
    } 
}

#include <sys/dir.h>   /* local directory structure */ 

/* readdir:  read directory entries in sequence */ 
Dirent *readdir(DIR *dp) 
{ 
    struct direct dirbuf;  /* local directory structure */ 
    static Dirent  d;      /* return: portable structure */ 

    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0) /* slot not in use */ 
            continue; 
        d.ino = dirbuf.d_ino; 
        strncpy(d.name, dirbuf.d_name, DIRSIZ); 
        d.name[DIRSIZ] = '\0';  /* ensure termination */ 
        return &d; 
    } 
    return NULL; 
} 
