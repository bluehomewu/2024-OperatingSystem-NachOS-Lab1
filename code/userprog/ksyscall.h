/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"
#include "synchconsole.h"

void SysHalt() {
    kernel->interrupt->Halt();
}

void SysPrintInt(int val) {
    DEBUG(dbgTraCode, "In ksyscall.h:SysPrintInt, into synchConsoleOut->PutInt, " << kernel->stats->totalTicks);
    kernel->synchConsoleOut->PutInt(val);
    DEBUG(dbgTraCode, "In ksyscall.h:SysPrintInt, return from synchConsoleOut->PutInt, " << kernel->stats->totalTicks);
}

int SysAdd(int op1, int op2) {
    return op1 + op2;
}

int SysCreate(char *filename) {
    // return value
    // 1: success
    // 0: failed
    return kernel->fileSystem->Create(filename);
}

// When you finish the function "OpenAFile", you can remove the comment below.

OpenFileId SysOpen(char *name)
{
  return kernel->fileSystem->OpenAFile(name); // OpenAFile() is a member function of FileSystem class in filesys/filesys.h L68
}

int SysWrite(char *buffer, int size, OpenFileId id)
{
  return kernel->fileSystem->WriteAFile(buffer, size, id); // WriteAFile() is a member function of FileSystem class in filesys/filesys.h L99
}

int SysRead(char *buffer, int size, OpenFileId id)
{
  return kernel->fileSystem->ReadAFile(buffer, size, id); // ReadAFile() is a member function of FileSystem class in filesys/filesys.h L87
}


int SysClose(OpenFileId id)
{
  return kernel->fileSystem->CloseAFile(id); // CloseAFile() is a member function of FileSystem class in filesys/filesys.h L110
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
