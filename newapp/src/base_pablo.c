#include "base_pablo.h"

char *
read_file(const char *filename)
{
  FILE *fileptr;
  char *buffer;
  long filelen;

  if(access(filename, F_OK) == -1)
    return NULL;

  fileptr = fopen(filename, "rb");      // Open the file in binary mode
  fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
  filelen = ftell(fileptr);             // Get the current byte offset in the file
  rewind(fileptr);                      // Jump back to the beginning of the file

  buffer = (char *)malloc((filelen + 1) * sizeof(char)); // Enough memory for file + \0
  fread(buffer, filelen, 1, fileptr);   // Read in the entire file
  fclose(fileptr);                      // Close the file

  if(buffer)
    return buffer;
  else
    return NULL;
}

long
file_size(const char *filename)
{
  FILE *fileptr;
  long filelen;

  if(access(filename, F_OK) == -1)
    return -1;

  fileptr = fopen(filename, "rb");      // Open the file in binary mode
  fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
  filelen = ftell(fileptr);             // Get the current byte offset in the file
  rewind(fileptr);                      // Jump back to the beginning of the file

  fclose(fileptr);                      // Close the file

  return filelen;
}