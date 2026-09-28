#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

  if(!argv[1]){
    printf("Please pass the folder name as well");
    return 1;
  }

  // 0755 is the permission for read/write and execute
  if(argv[1]) {
    int folderCreation = mkdir("/home/sajakshrestha", 0755);

    if (folderCreation == 0) {
      printf("File created successfully");
      return 0;
    } else {
      printf("Error in file creation");
      return 1;
    }
  }

  return 0;
}

// Algorithm
//

// Step 1: User type commandName folderName
// Step 2: argv[1] = folderName.
//  somehow communicates to the kernel for creating folder. (Kernel ma folder kasari create hunxa or kun location ma vanera kasari tha hunxa? )
// system call mkdir(path, mode) le chai create gardo raixa kernel ma folder. mode vaneko chai permission of the folder. path vaneko maile create garna lako folder ko path.
// VFS (Virtual file system) vaneko k ho?
//  -> Kernel ma katai sys_mkdir
// If kernel ma kasari create hunxa tha payo vane argv[1] lai kernel ma katai pass garna milxa hola.
