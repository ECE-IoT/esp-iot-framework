#include "spiffs.h"

void EspSpiffs::spiffsBeginn()
{
  if (!SPIFFS.begin(true))
  {
    return;
  }
}

char* EspSpiffs::readSpiffs(char* path)
{
  File file = SPIFFS.open(path);

  if (!file)
  {
    return (char*)"\0";
  }
  size_t size        = file.size();
  char* file_content = (char*)malloc((size + 1) * sizeof(char));

  file.readBytes(file_content, size);
  file_content[size] = '\0';
  file.close();

  return file_content;
}

bool EspSpiffs::printLog(char* path)
{
  File file = SPIFFS.open(path);

  if (!file)
  {
    return false;
  }
  size_t size        = file.size();
  char* file_content = (char*)malloc((size + 1) * sizeof(char));

  file.readBytes(file_content, size);
  file_content[size] = '\0';
  file.close();

  Serial.println(file_content);
  free(file_content);

  return true;

}

void EspSpiffs::appendLog(char* message, char* path)
{
  File file = SPIFFS.open(path, "a");

  if (!file)
  {
    return;
  }

  file.println(message);
  file.close();
}

void EspSpiffs::createFile(char* path)
{
  File file = SPIFFS.open(path, "w+");

  if (!file)
  {
    return;
  }
  file.print("");
  file.close();
}
