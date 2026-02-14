#define MATE_IMPLEMENTATION
#include "mate.h/mate.h"

i32 main(void) {
  // You can create a config that allows you to use different compilers as well as build directories
  //CreateConfig((MateOptions){.compiler = GCC, .buildDirectory = "./build"});
  StartBuild();
  {
    Executable executable = CreateExecutable((ExecutableOptions){
            .output = "main", 
            .debug = FLAG_DEBUG
    });

    
    AddFile(executable, "./src/hello.c");
    AddFile(executable, "./third_party/glad/src/glad.c")
    AddFile(executable, "./third_party/cglm/src/vec2.c");

    AddIncludePaths(executable, "./third_party/SDL/include");
    AddIncludePaths(executable, "./third_party/glad/include");
    AddIncludePaths(executable, "./third_party/cglm/include");
    
    AddLibraryPaths(executable, "./third_party/SDL/lib");

    LinkSystemLibraries(executable, "SDL3");
    
    // Add Standard C Math Library
    InstallExecutable(executable);
    
    if (!(RunCommand(executable.outputPath))){
        printf("something wrong happened");
    }
     // executable.ninjaBuildPath is the path where the build.ninja is at, here is where we grab all the commands from
    // Create compile commands for better LSP support
  }
  EndBuild();
}
